#!/bin/bash
# Build program with release mode.


BUILD_DIR=build-xcode
rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR && \
cd $BUILD_DIR && \
CXX_COMPILER=$(xcrun -find c++);
COMPILER=$(xcrun -find cc); 

cmake -G "Xcode" .. -D CMAKE_C_COMPILER=$COMPILER  -D CMAKE_CXX_COMPILER=$CXX_COMPILER  &&\
 # mkdir -p ../build && \
# cd ../build && \
# rm -rf ./* && \
# cmake ..  && \
# make -j4 && \
# cp ./janus ../$BUILD_DIR/Debug/ && \
exit 0

