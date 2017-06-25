# ICE Manual and Demos 手册和demo关联解读
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


