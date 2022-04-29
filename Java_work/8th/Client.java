
import java.io.*;
import java.net.*;
import java.util.*;

public class Client {
	public static void main(String[] args) {
		String serverName = args[0];
		int port = Integer.parseInt(args[1]);
		try {
			Scanner scan = new Scanner(System.in);
			int n = scan.nextInt();
			Socket socket = new Socket(serverName, port);
			// System.out.println("远程主机地址 - " + socket.getRemoteSocketAddress());
			OutputStream os = socket.getOutputStream();
			os.write(n); os.flush();
			InputStream is = socket.getInputStream();
			int ans = is.read();
			System.out.print(ans);
			socket.close();
			scan.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}