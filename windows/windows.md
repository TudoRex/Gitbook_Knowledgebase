# 1.Windows系统编程

### 如何将VC工程从win32窗口改为控制台？
在项目属性->配置属性->链接器->系统-->子系统

### visual leak的工程默认属性路径如何去除(vs2013)？
$(user)/AppData/Local/Microsoft/MSBuild/v4.0/下的xml配置文件

### visual studio 2013 x64工程配置
[](http://blog.csdn.net/cddchina/article/details/17550417)
新建工程时要继承win32， 并且不要新建