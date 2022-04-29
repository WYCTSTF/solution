import java.net.*;
import java.io.*;

public class Server extends Thread {
	private ServerSocket ss;
	public Server(int port) throws IOException {
		ss=new ServerSocket(port);
		ss.setSoTimeout(20000);
	}
	public void run() {
		while (true) {
			try {
				Socket socket=ss.accept();
				System.out.println("连接到远程主机 - "+socket.getRemoteSocketAddress());
				InputStream is=socket.getInputStream();
				OutputStream os=socket.getOutputStream();
				int n=is.read(),tem=1,ans=0;
				for (int i=1;i<=n;i++) {tem*=i;ans+=tem;}
				os.write(ans); os.flush();;
				is.close(); os.close();
				socket.close();
			} catch(SocketTimeoutException s){
				System.out.println("服务器等待响应超时 已退出");
				break;
			} catch(IOException e){
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args){
		int port=Integer.parseInt(args[0]);
		try {
			Thread t=new Server(port);
			t.start();
		}catch (IOException e){
			e.printStackTrace();
		}
	}
}