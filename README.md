<!-- リポジトリ名と説明 -->
# bag_converter

This is a rosbag converter repository.

## Getting Started

<!-- 開発環境 -->
### Prerequisites

  * 

<!-- インストール方法 -->
### Installation

Clone the repository.

```
git clone https://github.com/iidalab/Your-Repository-Name.git
```

<!-- 使用方法 -->
## Usage
  1. put bag file in bag_converter/bag
  2. run `roslaunch bag_converter rosbag_tf_converter.launch bag_name:=abc target_frame:=/map source_frame:=/base_link export_topic_name:=pose` if you want to convert tf to pose(std_msgs::Float32MultiArray).
  3. run `roscd bag_converter && . to_csv.sh bag_file_name /pose` if you want to convert .bag file to .csv file.





<!---
  以下はサンプルです．



# Template-README

This README file is merely one of the samples provided. While using this as a reference, please make necessary adjustments individually. For instance, please modify the versions of Python and OpenCV mentioned in "Prerequisites" to match your development environment. The sections that should be modified include the repository name, description, "Prerequisites," "Installation," "Usage," and "Contact." "Contributing" and "License" may seldom require alterations. Additionally, it might be advisable to remove the comments. If you have any uncertainties, please refer to past repositories for guidance. Wishing you a productive research journey ahead.

## Getting Started

### Prerequisites

  * Python 3.11.5
  * OpenCV 4.8.0

### Installation

Clone the repository.

```bash
git clone https://github.com/iidalab/TomatoDetector-for-Mobile.git
```

## Usage

  1. Run the code with `python3 main.py`

## Contributing

We welcome contributions from the team to enhance the project. To contribute,  follow the instructions of the project manager.

## License

This project is proprietary and confidential, intended for internal use by the team. Unauthorized copying, reproduction, or distribution of the code is strictly prohibited.

## Contact

For questions or feedback, please contact:

  - Taro Kosen (April 2023 - Present)
  - Hanako Kosen (April 2023 - March 2024)
  
-->