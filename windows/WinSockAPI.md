# WinSock API

## 传统Socket编程
### WSAStartup
初始化WinSock DLL Library


### WSACleanup
卸载WinSock DLL

## 利用IOCP
### MSWSock.h
winsock 2 扩展API头文件，定义了**LPFN_ACCEPTEX**， 支持`AcceptEx()`方法，需要用WSAIoctl找出其函数入口

### AcceptEx处理流程
#### 为什么必须设置**SO_UPDATE_ACCEPT_CONTEXT**
1. accept会继承sockListen的属性， 而AcceptEx必须手动利用**setsockopt**从*sockListen*复制peer的地址属性
```cpp
SOCKET sockListen;
setsockopt(	sockAccept,
		   	SOL_SOCKET,
		   	SO_UPDATE_ACCEPT_CONTEXT, 
			(char*)&sockListen,
			sizeof(SOCKET));
```
### AcceptEx高级用法
参考 
- [http://blog.csdn.net/lziog/article/details/16981825]()
- []()
1. 获取AcceptEx函数入口
```
#include <Mswsock.h>
LPFN_ACCEPTEX pfnAcceptEx;
GUID guidAcceptEx = WSAID_ACCEPTEX;
::WSAIoctl(	hListenSocket,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidAcceptEx, 
			sizeof( guidAcceptEx ),
			&pfnAcceptEx, 
			sizeof( pfnAcceptEx ), 
			&dwBytes, 
			NULL, NULL 
			);
```
- [http://stackoverflow.com/questions/9169086/tcp-shutdown-with-sockets-connected-through-acceptex]()
You have to call setsockopt(SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT) after AcceptEx() completes. The accepted socket is not fully associated with the properties of the listening socket, and as such will not be in a fully connected state, until SO_UPDATE_ACCEPT_CONTEXT is set. Some winsock API functions are affected by that, including getpeername(), getsockname() and shutdown().

If you use ConnectEx() to make an outbound connection, you have to invoke setsockopt(SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT) after ConnectEx() completes before you can then use shutdown(). This is documented behavior on MSDN. It does not say the same for AcceptEx() and SO_UPDATE_ACCEPT_CONTEXT, but shutdown() does have a similar restriction for sockets accepted by AcceptEx().

### 有关AcceptEx用WSAIoctl获取失败的问题
第一次成功， 第二次WSAIoctl成功但是AcceptEx接口为nullptr。