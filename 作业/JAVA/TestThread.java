/* 
 * 三种创建线程的方法：
 * 1. 通过实现Runnable(内置)接口
 * 2. 通过继承Thread类本身
 * 3. 通过Callable和Future创建线程
 */

// 1. 通过实现Runnable接口
// 为了实现Runnable，一个类只需要执行一个方法调用run()
class RunnableDemo implements Runnable {

	// 在创建了一个实现Runnable接口的类之后，可以在类中实例化一个线程对象
	// 常用的Thread构造方法是
	// Thread(Runnable threadOb,String threadName);
	private Thread t;
	private String threadName;

	RunnableDemo(String name) {
		threadName = name;
		System.out.println("Creating " + threadName);
	}

	public void run() {
		System.out.println("Running "+ threadName);
		try {
			for (int i = 4; i > 0; i--) {
				System.out.println("Thread: "+ threadName + ", " + i);
				Thread.sleep(50);
			}
		} catch(InterruptedException e) {
			System.out.println("Thread" + threadName + " interrupted.");
		}
		System.out.println("Thread " + threadName + " exiting.");
	}

	public void start() {
		System.out.println("Starting " + threadName);
		if (t == null) {
			t = new Thread (this, threadName);
			t.start();
		}
	}
}

// 2. 继承Thread来创建线程
// 创建一个新的类 继承Thread类 然后创建一个该类的实例
// 继承类必须重写run()方法 该方法是新线程的入口点 也必须调用start()才能执行
// 本质上也是实现了Runnable接口的一个实例

class ThreadDemo extends Thread {
	private Thread t;
	private String threadName;
	
	ThreadDemo(String name) {
		threadName = name;
		// System.out.println("Creating " + threadName);
	}

	public void run() {
		System.out.println("Running "+ threadName);
		try {
			for (int i = 4; i > 0; i--) {
				// if (t.isAlive()) {
				// 	System.out.println("YEP");
				// }
				System.out.println("Thread: " + threadName + ", " + i);
				// Thread.sleep(50);
			}
		} finally {
		}
		System.out.println("Thread " + threadName + " exiting.");
	}

	public void start() {
		// System.out.println("Starting " + threadName);
		if (t == null) {
			t = new Thread(this, threadName);
			t.start();
		}
	}
}

public class TestThread {
	public static void main(String[] args) throws Exception {
/* 		// 方式1
		RunnableDemo R1 = new RunnableDemo("Thread-1");
		R1.start();
		Thread.sleep(200);
		RunnableDemo R2 = new RunnableDemo("Thread-2");
		R2.start(); */
		ThreadDemo T1 = new ThreadDemo("Thread-1");
		T1.start();
		T1.join();
		// if (T1.isAlive()) {
		// 	System.out.println("YES");
		// } else {
		// 	System.out.println("NO");
		// }
		ThreadDemo T2 = new ThreadDemo("Thread-2");
		T2.start();
		T2.join();
	}
}