import java.util.ArrayList;
import java.util.Scanner;
class Book {
	String name, author; double price; int id;
	Book(String name,double price,int id,String author) { this.name=name; this.price=price; this.author=author; this.id=id; }
}
public class test {
	public static ArrayList <Book> BookList = new ArrayList<>();
	public static void Find(String chara,int mode) {
		if (mode == 1) {
			Boolean ff = false;
			for (Book it : BookList) { if (chara.equals(it.author)) { ff = true; System.out.printf("%d %s %s $%f\n", it.id, it.name, it.author, it.price); }}
			if (ff == false) System.out.println("Can not find any book wrote by this author");
		} else {
			Boolean ff = false;
			for (Book it : BookList) { if (chara.equals(it.name)) { ff = true; System.out.printf("%d %s %s $%f\n", it.id, it.name, it.author, it.price); }}
			if (ff == false) System.out.println("Can not find any book's name matches");
		}
	}
	public static void Find(String name,String author) {
		for (Book it : BookList) if (name.equals(it.name) && author.equals(it.author)) { System.out.printf("%d %s %s $%f\n", it.id, it.name, it.author, it.price); return; }
		System.out.println("Can not find");
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.printf("Input the number of books and the information of those book.\nExample: price name author\n");
		int N = scan.nextInt();
		for (int i = 1; i <= N; i++) {
			double Price = scan.nextDouble(); String name = scan.next(); String author =  scan.next();
			Book bb = new Book(name, Price, i, author); BookList.add(bb);
		}
		System.out.println("Input\n有三种询问方式: 输入 '1 xxx' 查询作者 '2 xxx' 查询书名 输入 '3 xxx xxx' 查询书名和作者");
		int Q = scan.nextInt(), mode; String name, author;
		for (int i = 1; i <= Q; i++) {
			mode = scan.nextInt();
			// System.out.printf("%d\n", mode);
			if (mode==1) { author = scan.next(); Find(author, mode);} else if (mode==2) { name = scan.next(); Find(name, mode); } else { name = scan.next(); author = scan.next(); Find(name, author);}
		}
		scan.close();
	}
}