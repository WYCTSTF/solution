import java.util.HashSet;

public class test {
  public static int get(int k) {
    final long l = System.currentTimeMillis();
    final int i = (int) (l % (long)(k) + 1);
    return i;
  }

  public static void main(String[] args) {
    HashSet<Integer>s = new HashSet<Integer>();
    for (int i = 1; i <= 6; i++) {
      int d = get(33);
      while (s.contains(d)) {
        d = get(33);
      }
      System.out.print(d + " ");
      s.add(d);
    }
    System.out.print("+ "+get(16));
  }
}