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

### 有关C++异常处理的自定义类的对象问题
```
	if (err)
	{
		Exception e(L"WSAStartup()", err);
		cout << "origin e:" << (void*)&e << endl;
		throw e;
	}
```
这里的Exception对象e通过观察ctor，dtor发现是正常销毁的， 如果throw e的地址会有e的内存泄漏的问题, 如果throw e的话(catch 是强类型匹配的), 也仍然会调用dtor

[http://www.cnblogs.com/hellogiser/p/constructor-destructor-exceptions.html]()
[http://baiy.cn/doc/cpp/inside_exception.htm]()

	引用维基百科的描述，讲的比我们解释的清楚，黑体是我加的：
	
	throw
	throw是一个C++关键字，与其后的操作数构成了throw语句，语法上类似于return语句。throw语句必须被包含在try块之中；可以是被包含在调用栈的外层函数的try中。
	
	执行throw语句时，其操作数的结果作为对象被复制构造为一个新的对象，放在内存的特殊位置（既不是堆也不是栈，Windows上是放在“线程信息块TIB”中）。这个新的对象由本级的try所对应的catch语句逐个做类型匹配；如果匹配不成功，则与本函数的外层catch语句依次做类型匹配；如果在本函数内不能与catch语句匹配成功，则递归回退到调用栈的上一层函数内从函数调用点开始继续与catch语句匹配。重复这一过程直到与某个catch语句匹配成功或者直到主函数main()都不能处理该异常。
	
	因此，throw语句抛出的异常对象不同于一般的局部对象。一般的局部对象会在其作用域结束时被析构。而throw语句抛出的异常对象驻留在所有可能被激活的catch语句都能访问到的内存空间中。
	
	throw语句抛出的异常对象在匹配成功的catch语句的结束处被析构（即使该catch语句使用的是非“引用”的传值参数类型）。
	
	由于throw语句都进行了一次副本拷贝，因此异常对象应该是可以copy构造的。但对于Microsoft Visual C++编译器，异常对象的复制构造函数即使私有的情形，异常对象仍然可以被throw语句正常抛出；但在catch语句的参数是传值时，在catch语句处编译报错：

