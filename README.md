vrpn_client_1工程为生成动态库工程，生成库文件在vrpn_client-mac-demo\vrpn_client_1\build-xcode\Release目录下

编译配置说明：
CMakeLists.txt:工程配置cmake文件
release-xcode.sh：构建XCODE工程脚本

编译环境：
1、macOS 12.7
2、cmake　３.２７.９
3、XCODE　１４.２

编译步骤：
１、打开终端切换到CMakeLists.txt目录下。
２、执行　release-xcode.sh．构建XCODE工程产生build-xcode文件夹。
３、build-xcode文件夹下使用XCODE打开mac_vrpn.xcodeproj即可。

