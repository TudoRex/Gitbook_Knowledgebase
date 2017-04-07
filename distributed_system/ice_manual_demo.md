# ICE Manual and Demos 手册和demo关联解读
## Technical Articles
讲述了Ice的很多概念
[https://doc.zeroc.com/display/Doc/Technical+Articles]()
## Ice
### Ice/async
- Asynchronous Method Invocation (AMI) in C++

### Ice/bidir
- Creating an Object Adapter for Collocated Invocations
- Bidirectional Connections
在server想要调用client的RPC时，需要发起server到client的连接， 然而通常被防火墙阻挡， 那么有一种办法就是复用client连接到server的connection,因此称*bidir callback*

### Ice/callback
### Ice/context
- Request Contexts
演示分布式context相关概念(类似于分布式map）, glacier2, iceStorm会使用这个概念

### Ice/interleaved
A more advanced throughput demo

### Ice/invoke
- 演示streaming API
- ice_invoke

### Ice/latency
- 演示ice_ping

### Ice/multicast
演示如何用UDP广播建立rpc通道的过程

*communicator()->propertyToProxy*方法
	Discover.Proxy=discover:udp -h 239.255.1.1 -p 10000
配置文件设定了名为**Discover.Proxy**的property,
借这个例子了解一下config.client, config.server中有关property的概念，如何配置， 这些与例子中的ObjectAdapter等概念密切相关


### Ice/nrvo
named return value optimization

### Ice/optional
当接口中出现optional的字段时， 调用时利用IceUtil::None来填充字段


## IceGrid
### IceGrid/allocate
	icegridnode		--Ice.Config=config.grid
**node** 类似于**docker**的概念，是service的容器, **registry**和**node**
或者

	icegridnoded 	--Ice.Config=config.grid

Only **one** client can access this object
at a time. All other clients will **hang** until the object is released.
Use the following command to deploy this descriptor:

    $ icegridadmin --Ice.Config=config.grid -e "application add application-single.xml"

application-single.xml 和 application-multi.xml分别举例说明了application, server, node的三者关系,          
                            
