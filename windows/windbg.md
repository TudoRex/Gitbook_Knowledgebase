# windbg调试器

## windows下的dll查看符号工具dumpbin
### 进入vc环境的方法
"C:\Program Files(x86)\Microsoft Visual Studio 12.0\VC" 找到vcvarsall.bat，  通过读取该脚本和自带的快捷方式学习了进入不同体系结构的环境的方法：
`vcvarsall.bat x86`
进入后， 环境变量里出现了dumpbin（对应架构的dumpbin）, 
```
dumpbin /imports my.dll
dumpbin /exports my.dll
```

### vs2010 undname demangle工具
undname

### 同一头文件不同版本dll的进程空间共存
rohon, ctp 头文件相同
同时使用
```
#pragma comment(lib, "ctp.dll")
#pragma comment(lib, "rohon.dll")
```

根据vc调试模式下的模块加载信息， 发现， 先被处理的#pragma被链接进进程

## visual c++ linker
1. 增量链接
[http://www.cnblogs.com/Dahaka/archive/2011/08/01/2124256.html]()
通过linker的/NODEFAULTLIB选项， 和链接器输入顺序决定了链接的函数库是哪个(观察链接器详细输出）
所以采用第二套方案

2. 动态加载可以实现同一个头文件多个版本的载入

3. UndecorateSymbolName
[http://blog.csdn.net/icefireelf/article/details/6591298]()