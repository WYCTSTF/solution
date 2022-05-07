import java.io.*;
import java.util.*;
public class fwrite {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("输入要修改的文件名 时间 操作人名称");
		String fileName = scan.nextLine();
		String date = scan.nextLine();
		String PersonName = scan.nextLine();
		Boolean tag = false;
		try {
			File file = new File(fileName);
			if (file.createNewFile()) System.out.println("文件创建成功");
			else { System.out.println("文件已存在"); tag = true; }
		} catch (IOException e) {
			e.printStackTrace();
		}
		File tem = new File("temporayryRecord");
		char[] buf = new char[5010];
		try {
			if (tag) {
				tem.createNewFile();
				FileReader fr = new FileReader(fileName);
				fr.read(buf);
			}
			FileWriter fw = new FileWriter(fileName, false);
			fw.write("Time: "+date+"\nAuthor: "+PersonName+"\n");
			if (tag) {
				for (char c : buf) {
					if (c == '\0') break;
					fw.append(c);
				}
				tem.delete();
			}
			fw.close(); scan.close();
		}
		catch (IOException e) {
			System.out.println("写入失败"); e.printStackTrace();
		}
	}
}