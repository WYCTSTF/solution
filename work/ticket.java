import java.util.Scanner;
public class ticket {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("输入总票数M");
		Control.total = scan.nextInt();
		Thread t1 = new Thread(new RunnableDemo("窗口1"));
		Thread t2 = new Thread(new RunnableDemo("窗口2"));
		t1.start();
		t2.start();
		scan.close();
	}
}
class Control {
	public static final Object lock = new Object();
	public static int total;
}
class RunnableDemo implements Runnable {
	private Thread t;
	private String threadName;
	RunnableDemo(String name) {
		threadName = name;
	}
	public void run() {
		while (true) {
			try { Thread.sleep(20); }
			catch(InterruptedException e) { e.printStackTrace(); }
			synchronized(Control.lock) {
				if (Control.total > 0) {
					Control.total--;
					System.out.println(threadName + "售票1张");
				} else {
					System.out.println("票已售完");
					System.exit(0);
				}
			}
		}
	}
}