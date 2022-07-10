import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class FileClient {
	public static void main(String[] args) throws Exception {
		String host="localhost";
		int port=4001;
		Scanner scan=new Scanner(System.in);
		while (true) {
			int len;
			byte[] bytes=new byte[1024];
			Socket socket=new Socket(host, port);
			// assert connection
			System.out.println("已连接到服务器，本机地址 - "+socket.getLocalSocketAddress());
			System.out.println("请输入文件路径 或者 输入 bye 以退出");
			String filePath=scan.next();
			DataInputStream dis=new DataInputStream(socket.getInputStream());
			DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
			if (filePath.equals("bye")) {
				System.out.println("拜拜");
				break;
			}
			dos.writeUTF(filePath); dos.flush();
			String message=dis.readUTF();
			if (message.equals("success")) {
				System.out.println("文件已找到 正在传输至本地");
				String[] src=filePath.split("/");
				String target=src[src.length-1];
				File tar=new File(target);
				tar.createNewFile();
				OutputStream os=new FileOutputStream(tar);
				while ((len=dis.read(bytes))!=-1){
					os.write(bytes,0,len);
					os.flush();
				}
				os.close();
				System.out.println("传输完成");
				break;
			} else {
				System.out.println("文件不存在 请重试");
			}
		}
		scan.close();
	}
}