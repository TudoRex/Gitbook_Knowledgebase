# 1.Windows系统编程

### 如何将VC工程从win32窗口改为控制台？
在项目属性->配置属性->链接器->系统-->子系统

### visual leak的工程默认属性路径如何去除(vs2013)？
$(user)/AppData/Local/Microsoft/MSBuild/v4.0/下的xml配置文件


### visual studio 2013 x64工程配置
[](http://blog.csdn.net/cddchina/article/details/17550417)
新建工程时要继承win32， 并且不要新建

### windbg
[](http://www.yiiyee.cn/Blog/windbg/)

#### SOS.dll (SOS Debugging Extension)
[](https://msdn.microsoft.com/en-us/library/bb190764(v=vs.110).aspx)

### Completion Port

### Visual Studio Unicode编码的控制台工程打印中文的方法
`setlocale(LC_ALL, "chs")`


## 运维
### Windows Server 2012 右键打开命令行（管理员），自动切换到当前目录

```
Windows Registry Editor Version 5.00
[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\runas]
@="@shell32.dll,-8506"
"HasLUAShield"=""

[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\runas\command]
@="cmd.exe"
"IsolatedCommand"="cmd.exe /s /k pushd \"%V\""

```

## windows-classic-examples
### iocp
平台： windows10 ， vs2013_x64
在iocpserverex项目中的myprint调用Windows API WriteConsole(),StringCchVPrintf()实现,
发现打印了几行之后不能刷新buffer， 改用vprintf实现后没有出现这个问题.原因不明

## 流媒体直播
- [http://nicoconi.com/2015-09/obs-monaserver-live.html]()
- [http://blog.eqoe.cn/posts/rtmfp-p2p-live.html]()