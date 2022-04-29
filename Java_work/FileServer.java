import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FileServer {
	public static void main(String args[]) throws Exception {
		int port=Integer.parseInt(args[0]);
		ServerSocket server=new ServerSocket(port);
		System.out.println("服务器正在等待连接");
		ExecutorService threadPool=Executors.newFixedThreadPool(100);
		while (true) {
			Socket socket=server.accept();
			Runnable runnable=()->{
				try {
					System.out.println("连接到远程主机 - "+socket.getRemoteSocketAddress());
					InputStream is=socket.getInputStream();
					OutputStream os=socket.getOutputStream();
					DataInputStream dis=new DataInputStream(is);
					DataOutputStream dos=new DataOutputStream(os);
					String filePath=dis.readUTF();
					System.out.println("目录接收成功 - "+filePath+"，正在查找...");
					File src=new File(filePath);
					try {
						InputStream temIs=new FileInputStream(src);
						byte[] bytes=new byte[1024];
						int len=-1;
						while  ((len=temIs.read(bytes))!=-1) {
							os.write(bytes);
						}
						os.flush();
						temIs.close();
						dos.writeUTF("success");
					} catch (FileNotFoundException f) {
						dos.writeUTF("文件不存在");
						f.printStackTrace();
					}
				} catch(Exception e){
					e.printStackTrace();
				}
			};
			threadPool.submit(runnable);
		}
	}
}