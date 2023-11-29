#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/utils.h>
#include <geometry_msgs/Quaternion.h>
#include <std_msgs/Float32MultiArray.h>

class TfConverter
{
private:
    ros::NodeHandle _nh;
    ros::NodeHandle _pnh;

    ros::Publisher _pose_pub;

    tf2_ros::Buffer _tf_buffer;
    tf2_ros::TransformListener _tf_listener;
    geometry_msgs::Quaternion _imu_quat;
    geometry_msgs::Quaternion _odom_quat;

    std::string _target_frame;
    std::string _source_frame;
    std::string _export_topic_name;
    
public:
    TfConverter();

    void run();
};

TfConverter::TfConverter() :
_nh(""), _pnh("~"), _tf_buffer(), _tf_listener(_tf_buffer)
{
    _pnh.getParam("target_frame", _target_frame);
    _pnh.getParam("source_frame", _source_frame);
    _pnh.getParam("export_topic_name", _export_topic_name);

    _pose_pub = _nh.advertise<std_msgs::Float32MultiArray>(_export_topic_name, 1);  
}

void TfConverter::run()
{
    geometry_msgs::TransformStamped transform_stamped0;
    try
    {
        transform_stamped0 = _tf_buffer.lookupTransform(_target_frame, _source_frame, ros::Time(0));
    }
    catch (tf2::TransformException& ex)
    {
        ROS_WARN("%s", ex.what());
        return;
    }
    double pitch, roll, yaw;
    tf2::getEulerYPR(transform_stamped0.transform.rotation, yaw, pitch, roll);

    std_msgs::Float32MultiArray pose;
    pose.data.push_back(transform_stamped0.transform.translation.x);
    pose.data.push_back(transform_stamped0.transform.translation.y);
    pose.data.push_back(yaw);

    _pose_pub.publish(pose);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "tf_converter");

    TfConverter tfcon;
    
    ros::Rate rate(50.0);
    while (ros::ok())
    {
        ros::spinOnce();

        tfcon.run();

        rate.sleep();
    }

    return 0;
}