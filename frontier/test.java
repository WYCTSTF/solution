import java.io.*;

public class test {
  public static void main(String[] args) throws Exception {
    File file = new File("A_secret.txt");
    FileOutputStream fos = new FileOutputStream(file);

    byte[] bytes1 = { -28, -67, -96, -26, -104, -81, -25, -116, -86, -27, -112, -89, 63 };

    fos.write(bytes1);
    fos.close();

  }
}