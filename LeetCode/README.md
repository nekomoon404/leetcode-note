## MacOS VSCode C++调试

单文件调试：

直接使用系统默认的clang++和lldb，比较方便；

关键是生成task.json-->用于生成可执行文件，和launch.json-->用于调用lldb调试task.json中生成的可执行文件。

launcher.json中的preLaunchTask要和task.json中的label相同，这样在调试之前会将preLaunchTask重新编译一遍。

launch.json—”program”表示要调试的可执行文件名字，需要和task.json中生成的可执行文件名字相同。

另外MacOS需要在launch.json里修改配置"externalConsole"为true，因为MacOS输出结果不能在vscode内集成中的终端中打印，需要用外部的终端。

可以参考官方文档：https://vscode.github.net.cn/docs/cpp/config-clang-mac