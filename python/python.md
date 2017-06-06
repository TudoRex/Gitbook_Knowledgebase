# Python

## Basic
### Raw String
用os.chdir()遇到`(unicode error) 'unicodeescape' codec can't decode bytes in position 2-3: truncated \UXXXXXXXX escape`
**路径要用r前缀修饰**，代表raw string

混合编程方案：
1. swig
[http://www.jyguagua.com/?p=2769]()
2. Cython
3. ctypes

## swig 封装CTP遇到的问题
1. python3.3/3.4 需要vs2010工具集， 难以部署
2. python3.5 or lator 需要vs2015
3. 由于GIL的存在不能顺利异步回调(尝试 -python -py3 -thread选项)

用swig 转csharp方案代替， 也许兼容性是最好的
GUI(c# winform) + swig(业务ctp api), 

## swig 如何实现python继承virutal function
[http://stackoverflow.com/questions/35608136/how-to-call-a-virtual-method-overridden-in-python-from-c-using-swig]()