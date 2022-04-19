import java.io.*;

public class MyCopy {
	public static void main(String[] args) {
		String src = args[0];
		String target = args[1];

		File srcFile = new File(src);
		File targetFile = new File(target);
		
		try {
			InputStream is = new FileInputStream(srcFile);
			OutputStream os = new FileOutputStream(targetFile);
			byte[] bytes = new byte[1024];
			int len = -1;
			while ((len = is.read(bytes)) != -1) {
				os.write(bytes, 0, len);
			}
			is.close();
			os.close();
		} catch (FileNotFoundException e) {
			System.out.println("文件未找到");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("读写失败");
			e.printStackTrace();
		}
	}
}