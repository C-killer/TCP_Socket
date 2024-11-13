# TCP_Socket

## C++
### 基于Linux的Socket网络编程

`tcp_socket.hpp` 和 `tcp_socket.cpp` 包含了对于socket服务、用户两端的基本函数：

```cpp
// 报错并返回
int print_error(std::string msg);

// 创建服务端socket并监听
int init_server_socket();

// 创建用户端socket并请求连接
int init_client_socket(const char *ip);
```

### 在`sock_server.cpp` 和 `sock_client.cpp` 中实现了用户端和服务端的在线聊天室。

## python
利用socket库实现server和client的通信，利用分段处理了接受端的粘包问题
