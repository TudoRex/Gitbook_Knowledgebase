# 1.Windows系统编程

### 如何将VC工程从win32窗口改为控制台？
在项目属性->配置属性->链接器->系统-->子系统

### visual leak的工程默认属性路径如何去除(vs2013)？
$(user)/AppData/Local/Microsoft/MSBuild/v4.0/下的xml配置文件

### windbg
[](http://www.yiiyee.cn/Blog/windbg/)

#### SOS.dll (SOS Debugging Extension)
[](https://msdn.microsoft.com/en-us/library/bb190764(v=vs.110).aspx)

### Completion Port

### Visual Studio Unicode编码的控制台工程打印中文的方法
`setlocale(LC_ALL, "chs")`


