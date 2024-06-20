#include "tcp_socket.hpp"

int main() {
    //创建服务器
    int serFd = init_server_socket();
    
    //客户端请求连接
    // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    // 监听socket的文件描述符
    // 指向一个 sockaddr 结构体的指针，用于存储连接客户端的地址信息。对客户端地址信息不感兴趣，可以传递 NULL。
    // 一个指向 socklen_t 类型变量的指针，该变量保存 addr 结构体的大小。如果 addr 为 NULL，则 addrlen 也应该为 NULL。
    
    /* 使用 accept(fd, NULL, NULL)
    int cliFd = accept(serFd, NULL, NULL);
    if (cliFd < 0) {   
        print_error("accept error");
    }
    */

    //使用 int accept(fd, &addr, &addrlen);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int cliFd = accept(serFd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (cliFd < 0) {
        print_error("accept error");
    }
    std::cout << "Client connected" << std::endl;

    //与客户端通信
    char buf[BUFSIZ] = { 0 };
    while (1) {
        //recv 从指定的sokcet通信
        if (recv(cliFd, buf, BUFSIZ, 0) == -1) {
            print_error("recieve error");
        } ;   
        std::cout << "recv:" << buf << std::endl;

        //发送消息
        std::cout << "send>";
        std::cin.getline(buf, BUFSIZ);
        if (strcmp(buf, "exit") == 0) {
            break;
        }
        if (send(cliFd, buf, BUFSIZ, 0) < 0) {
            print_error("send error");
        }
    }

    std::cout << "Successfully exited" << std::endl;

    close(serFd);
    close(cliFd);

    return 0;
}
