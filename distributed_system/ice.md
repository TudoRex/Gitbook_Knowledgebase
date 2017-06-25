# Zeroc ICE
## Python绑定
### IcePy
所有接口方法生成依赖于IcePy, 接口中的out属性如何处理
### winpython 3.3.5.9-64bit下安装Ice（VS2013环境）
1. 进入vs2013编译命令行（x64）
‘StartMenu’-》‘Visual Studio Tools’
2. 替换vs2010为vs2013的环境进行编译
SET VS100COMNTOOLS=%VS120COMNTOOLS%
3. 进入D:\WinPython-64bit-3.3.5.9\python-3.3.5.amd64\Scripts
`pip.exe install zeroc-ice`


## ICE-3.6 Demo解读
- VC12 中ice_builder Build失败的工程配置问题
通用属性-> Ice_builder, 以Ice/Hello为例
Failed：
`Output Directory:	.\generated\server`
Success:
`Output Directory:	$(MSBuildProjectDirectory)\generated\server`
貌似不是这个问题， 似乎强制生成一遍得到目录就可以了

### Simple Printer
Server端
```
Ice::CommunicatorPtr ic;
ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -h localhost -p 10000");
        Ice::ObjectPtr object = new PrinterI;
        adapter->add(object, ic->stringToIdentity("SimplePrinter"));
        adapter->activate();
        ic->waitForShutdown();
```
Client
```
```
### Manual/simpleFileServer
服务器创建有关节点，文件， 目录的三种分布式对象, 配合Lines(文本行数据)

- 具有继承关系的proxy可以利用**checkedCast**，**uncheckedCast**进行*Proxy的类型转换*
- 
### Manual/mapFileSystem


## Slice语言
- ice文件中出现类似指针的语法是**Pass-by-Reference**语法, 生成的是*Proxy*类型

### Server-Side Features

### Client-Side Features
leader & followers 多线程设计模式
- [http://www.cnblogs.com/duzouzhe/archive/2009/09/28/1575813.html]()
总结一下：leader监听， 发生event后,唤醒一个睡眠的follower成为新的leader， 自己处理该event后变为follower


### 


###### 
参见DEMO 'Ice/bidir'
`Ice::ObjectAdapterPtr collocAdapter = communicator->createObjectAdapter("");`

## XLProject 框架
1. 改写接口类IXLSystemDataProvider
查阅slice的operation定义， 可以为parameter添加in， out修饰词， 生成我们想要的c++接口
