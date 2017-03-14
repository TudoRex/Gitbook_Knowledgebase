# WinSock API

## 传统Socket编程
### WSAStartup
初始化WinSock DLL Library


### WSACleanup
卸载WinSock DLL

## 利用IOCP
### MSWSock.h
winsock 2 扩展API头文件，定义了**LPFN_ACCEPTEX**， 支持`AcceptEx()`方法
