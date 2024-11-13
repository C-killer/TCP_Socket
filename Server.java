// Server.java

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String arg[]) {
        int port  = 12345;

        try (ServerSocket serversocket = new ServerSocket(port)){
            // 创建ServerSocket对象并绑定到指定端口，监听客户端连接请求
            System.out.println("服务端正在监听端口 " + port);

            while (true) {
                // 接受客户端连接，accept()方法会阻塞直到有客户端连接
                Socket socket = serversocket.accept();
                System.out.println("新的客户端连接成功");

                // 获取客户端的输入流，用于读取客户端发送的消息
                InputStream input = socket.getInputStream();    // 从Socket对象中获取输入流。
                // InputStreamReader：将字节输入流input转换成字符输入流
                // BufferedReader：将字符流进一步包装为带缓冲的字符输入流
                BufferedReader reader = new BufferedReader(new InputStreamReader(input));

                // 获取输出流，用于向客户端发送响应
                OutputStream output = socket.getOutputStream();     // 从连接的Socket对象中获取输出流。
                // PrintWriter：是一种文本输出流，可以方便地发送字符串和其他文本数据。
                // 使用PrintWriter可以直接使用print或println方法发送文本数据。
                // true参数：开启自动刷新（autoFlush）模式————每次调用println方法发送数据后，会自动将数据刷新到输出流中
                // 确保消息被立即发送到客户端，而不是在缓冲区中等待
                PrintWriter writer = new PrintWriter(output, true);

                // 读取客户端发送的每一行消息
                // BufferedReader的readLine()方法可以逐行读取数据，直到检测到换行符为止。
                String message;
                while ((message = reader.readLine()) != null) {
                    System.out.println("收到客户端消息: " + message);

                    // 将接收到的消息返回给客户端
                    writer.println("服务端已收到: " + message);

                    // 如果收到 "exit" 则结束通信并断开连接
                    if ("exit".equalsIgnoreCase(message)) {
                        System.out.println("客户端已断开连接");
                        break; // 结束当前客户端的通信
                    }
                }
                // 关闭Socket连接，结束与当前客户端的通信
                socket.close(); 
            }
        } catch (IOException ex) {
            System.out.println("服务端异常: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}