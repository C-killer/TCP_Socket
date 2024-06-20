#ifndef _TCP_SOCKET_HPP
#define _TCP_SOCKET_HPP

#include <sys/socket.h>         // 用于socket函数和相关网络编程API
#include <iostream>
#include <arpa/inet.h>          // 用于inet_addr函数
#include <unistd.h>             // 用于close函数
#include <string>
#include <cstring>

#define PORT 8888    //[0,65535)   0~1024为系统保留端口

//报错并返回
int print_error(std::string msg);
//创建服务器socket并监听
int init_server_socket();
//创建用户端socket并请求连接
int init_client_socket(const char *ip);

#endif // _TCP_SOCKET_HPP