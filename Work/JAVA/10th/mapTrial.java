import java.util.HashMap;
import java.util.Scanner;

public class mapTrial {
	public static HashMap<String, String> maps = new HashMap<String, String>();

	public static String Find(String VV) {
		for (String key : maps.keySet()) {
			if (maps.get(key).equals(VV)) {
				return key;
			}
		}
		return null;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		maps.put("312130", "Google");
		maps.put("123123", "Runoob");
		maps.put("412343", "Taobao");
		maps.put("123453", "Zhihu");
		System.out.println("输入邮编查询城市");
		String tem = scan.next();
		String ans = maps.getOrDefault(tem, null);
		if (ans != null)
			System.out.printf(ans+'\n');
		else
			System.out.printf("没找到");
		tem = scan.next();
		ans = Find(tem);
		if (ans == null) System.out.printf("没找到");
		else System.out.printf(ans+"\n");
	}
}
