import java.io.*;
import java.net.*;
import java.util.*;

public class FileClient {
	public static void main(String[] args) throws IOException {
		String host=args[0];
		int port=Integer.parseInt(args[1]);
		Boolean flag=true;
		Scanner scan=new Scanner(System.in);
		while (flag) {
			Socket socket=new Socket(host,port);
			System.out.println("连接成功，本机地址 - "+socket.getLocalSocketAddress());
			System.out.println("输入文件路径和文件名 或者输入 'bye' 退出");
			String filePath=scan.nextLine();
			if (filePath=="bye") {
				System.out.println("再见");
				break;
			}
			InputStream is=socket.getInputStream();
			OutputStream os=socket.getOutputStream();
			DataInputStream dis=new DataInputStream(is);
			DataOutputStream dos=new DataOutputStream(os);
			dos.writeUTF(filePath); dos.flush();
			String message=dis.readUTF();
			String[] strs = filePath.split("/");
			String target=strs[strs.length-1];
			if(message=="success") {
				File tar=new File(target);
				try {
					OutputStream osToFile=new FileOutputStream(tar);
					byte[] bytes=new byte[1024];
					int len=-1;
					while((len=is.read(bytes))!=-1) {
						osToFile.write(bytes,0,len);
					}
				} catch(IOException e) {
					e.printStackTrace();
				}
				System.out.println("文件传输成功");
				flag=false;
			} else {
				System.out.println("失败 文件未找到 请重试");
			}
		}
		scan.close();
	}
}