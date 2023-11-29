#!/bin/bash

NAME=${1}
TOPIC_NAME=${2}

DIR=`pwd`

command="roscd bag_converter && rostopic echo -b ${DIR}/bag/${NAME}.bag -p ${TOPIC_NAME} > ${DIR}/bag/${NAME}.csv"

eval $command