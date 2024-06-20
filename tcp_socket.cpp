#include "tcp_socket.hpp"

int print_error(std::string msg) {
    std::cerr << msg <<std::endl;
    return -1;
}


int init_server_socket() {
    /* 创建空socket */
    //参数一：通信域 domain/address family （AF_INET，IPv4； AF_INET6，IPv6； AF_UNIX，本机通信
    //参数二：类型 type （SOCK_STREAM，TCP流；SOCK_DGRAM，UDP数据报； SOCK_ROW 原始网络协议访问）
    //参数三：协议 protocol (通常选择默认协议 0 )
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        print_error("create error");
    }

    /* 给socket绑定ip与端口号 */
    // 服务器地址结构体 struct sockaddr_in{
    //     short int          sin_family;   //地址族（Address family） 对于IPv4地址，值应设置为 AF_INET
    //     unsigned short int sin_port;     // 端口号（Port number）
    //     struct in_addr     sin_addr;     // IP地址（IP address）
    //     unsigned char      sin_zero[8];  // 填充字段（Padding field）使结构体大小与 `sockaddr` 保持一致à
    // }
    // struct in_addr {
    //     unsigned long s_addr;  // 32位IPv4地址
    // }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);  //本地字节序 ==> 网络字节序（大端存储）
    addr.sin_addr.s_addr = INADDR_ANY;  // inet_addr("127.0.0.1"); （127.0.0.1为本地IP）
    if (bind(fd, (const sockaddr *)&addr, sizeof(addr)) < 0) {
        print_error("bind error");
    }

    /* 监听 */
    if (listen(fd, 10) < 0) {    //最多监听10个
        print_error("listen error");
    }
    std::cout << "Server is listening on port " << PORT << std::endl;

    return fd;
}


int init_client_socket(const char *ip) {
    /* 创建空socket */
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        print_error("create error");
    }
    /* 连接服务器 */
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);   
    addr.sin_addr.s_addr = inet_addr(ip);   //本机作服务器因此输入本地IP
    if (connect(fd, (const sockaddr *)&addr, sizeof(addr)) < 0) {
        print_error("connect error");
    }
    std::cout << "Connected to server" << std::endl;

    return fd;
}