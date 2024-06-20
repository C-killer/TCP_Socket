#include "tcp_socket.hpp"

int main() {
    //创建客户端socket并请求连接
    int fd = init_client_socket("127.0.0.1");
    //与服务器通信
    char buf[BUFSIZ];
    while (1) {
        //发送消息
        std::cout << "send>" ;
        std::cin.getline(buf, BUFSIZ);
        if (strcmp(buf, "exit") == 0) {
            break;
        }
        if (send(fd, buf, BUFSIZ, 0) < 0) {
            print_error("send error");
        }
        //接收消息
        if (recv(fd, buf, BUFSIZ, 0) == -1) {
            print_error("recieve error");
        } ;   
        std::cout << "recv:" << buf << std::endl;
    }
    
    std::cout << "Successfully exited" << std::endl;

    close(fd);

    return 0;
}
