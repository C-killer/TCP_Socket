// Client.java

import java.io.*;       // 导入输入输出相关类
import java.net.*;      // 导入网络相关类

public class Client {
    public static void main(String[] args) {
        String hostName = "localhost"; // 指定服务端的主机名
        int port = 12345;              // 与服务端匹配的端口号

        try (Socket socket = new Socket(hostName, port)) { // 修正Socket拼写
            // 获取输出流，用于发送消息到服务端
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);

            // 获取输入流，用于接收服务端的响应消息
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            
            // 发送消息到服务端
            writer.println("你好，服务端！");
            // 读取服务端的响应
            String response = reader.readLine();
            System.out.println("服务端回复: " + response);

            // 发送"exit"以终止会话
            writer.println("exit");
            response = reader.readLine();
            System.out.println("服务端回复: " + response);

        } catch (UnknownHostException ex) {
            System.out.println("无法找到服务端: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("I/O异常: " + ex.getMessage());
        }
    }
}
