# IO Completion Port

## 参考资料
- wikipedia上的完成端口(en.wikipeida.org)

- [理解I/O Completion Port](http://dev.gameres.com/Program/Control/IOCP.htm)
- [完成端口详解](http://blog.csdn.net/piggyxp/article/details/6922277)
- [http://www.cnblogs.com/MRRAOBX/articles/3908059.html]()
- [https://msdn.microsoft.com/en-us/library/windows/desktop/ms737524(v=vs.85).aspx]()
- [Microsoft Windows Classic example](https://github.com/Microsoft/Windows-classic-samples.git)
- [深入解析IOCP](http://cczjp89.blog.51cto.com/2707533/823158)

## IOCP过程
1. **CreateIoCompletionPort**，创建iocp句柄
2. **WSASocket**创建listen套接字加入iocp(**CreateIoCompletionPort**根据参数起到update作用)
3. 创建工作线程（或接收套接字的线程）每个worker调用**GetQueuedCompletionStatus()**
### accept创建的socket加入iocp
这样iocp监管listen套接字和通讯用套接字（类似epoll）
## accept与AcceptEX
- **accept**是传统阻塞
- **AcceptEX**是异步
### accept线程模型
1 accept 线程 + N recv线程
### AcceptEX
N worker模型， 每个worker均可担任数据和建立通讯套接字的职责


