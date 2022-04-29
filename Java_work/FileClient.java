import java.io.OutputStream;
import java.net.Socket;

public class FileClient {
	public static void main(String[] args) throws Exception {
		// 指定IP地址
		String host = "127.0.0.1";
		// 从命令行参数得到IP地址
		host = args[0];
		// 指定端口
		int port = 4001;
		// 从命令行获取
		port = Integer.parseInt(args[1]);
		// 与服务器建立连接
		Socket socket = new Socket(host, port);
		// 得到客户端输出流 与服务端输入流关联
		OutputStream os = socket.getOutputStream();
		String message = "你好 小帅哥";
		socket.getOutputStream().write(message.getBytes("UTF-8"));
		os.close();
		socket.close();
	}
}