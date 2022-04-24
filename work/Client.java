import java.io.*;
import java.net.*;

public class Client {
	public static void main(String[] args) {
		String serverName = args[0];
		int port = Integer.parseInt(args[1]);
		try {
			System.out.println("连接到主机: " + serverName + ", 端口号" + port);
			Socket client = new Socket(serverName, port);
			System.out.println("远程主机地址: "+ client.getRemoteSocketAddress());
			OutputStream outToServer = client.getOutputStream();
			DataOutputStream out = new DataOutputStream(outToServer);
		}
	}
}