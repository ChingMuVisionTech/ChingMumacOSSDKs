## ChingMu macOS SDK 使用说明

vrpn_client_1工程为生成动态库工程，生成库文件在vrpn_client-mac-demo\vrpn_client_1\build-xcode\Release目录下<br>

### 编译配置说明：

1. CMakeLists.txt: 工程配置cmake文件<br>
2. release-xcode.sh：构建XCODE工程脚本<br>

### 编译环境：

1. macOS 12.7<br>
2. cmake 3.27.9<br>
3. XCODE 14.2<br>

### 编译步骤：

１. 打开终端切换到CMakeLists.txt目录下。<br>
２. 执行release-xcode.sh．构建XCODE工程产生build-xcode文件夹。<br>
３. build-xcode文件夹下使用XCODE打开mac_vrpn.xcodeproj即可。<br>
