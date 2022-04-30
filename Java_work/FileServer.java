import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class FileServer {
	public static void main(String[] args) throws Exception {
		int port = 4001;
		ServerSocket ss=new ServerSocket(port);
		System.out.println("服务器等待连接...");
		ExecutorService threadPool=Executors.newFixedThreadPool(100);
		while (true) {
			Socket socket=ss.accept();
			System.out.println("连接到远程主机 - "+socket.getRemoteSocketAddress());
			Runnable runnable=()->{
				try {
					DataInputStream dis=new DataInputStream(socket.getInputStream());
					DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
					int len;
					byte[] bytes=new byte[1024];
					String filePath=dis.readUTF();
					try {
						File src=new File(filePath);
						FileInputStream fis=new FileInputStream(src);
						dos.writeUTF("success"); dos.flush();
						while ((len=fis.read(bytes)) != -1) {
							dos.write(bytes, 0, len);
						}
						dos.flush();
						fis.close();
						System.out.println("文件传输结束");
						socket.close();
					} catch (FileNotFoundException fnf) {
						dos.writeUTF("fail"); dos.flush();
					}
				} catch (EOFException e) {
					System.out.println("客户端"+socket.getRemoteSocketAddress()+"终止");
				} catch (Exception e) {
					e.printStackTrace();
				} 
			};
			threadPool.submit(runnable);
		}
	}
}