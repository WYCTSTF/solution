class Add {
  int add(int a,int b){return a+b;}
  int add(int a,int b,int c){return a+b+c;}
  int add(int a,int b,int c,int d){return a+b+c+d;}
}
public class Main {
  public static void main(String[] args) {
    Add  ad = new Add();
    System.out.printf("%d\n", ad.add(1,2));
    System.out.printf("%d\n", ad.add(1,2,3));
    System.out.printf("%d\n", ad.add(1,2,3,4));
  }
}