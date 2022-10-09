#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# create pb python file
echo Creating Python protobuf
protoc --python_out $SCRIPT_DIR boardcomms.proto

# create pb c files
echo Creating C protobuf
python3 nanopb/generator/nanopb_generator.py boardcomms.proto

# copy to the directories they will be used in
cp boardcomms_pb2.py ../coral_coms/coms_py/boardcomms_pb2.py
cp boardcomms.pb.c ../atmega_coms/atmega_comms/boardcomms.pb.c
cp boardcomms.pb.h ../atmega_coms/atmega_comms/boardcomms.pb.h
