import java.io.*;

class MyThread extends Thread {
	Thread thdNext = null;
	
	public MyThread(String szName) {super(szName);}
	public void run() {
		for (int i = 0; i < 100; ++i) {
			try {
				Thread.sleep(1000000);
			} catch(InterruptedException e) {
				System.out.print(getName() + " ");
				if (thdNext.isAlive()) thdNext.interrupt();
			}
		}
	}
	
	public void setNextThread(Thread t) {thdNext = t;}
}

public class JavaLab {
	public static void main(String args[]) throws InterruptedException {
		MyThread my_thread1 = new MyThread("thd1");
		MyThread my_thread2 = new MyThread("thd2");
		MyThread my_thread3 = new MyThread("thd3");
		my_thread1.setNextThread(my_thread2);
		my_thread2.setNextThread(my_thread3);
		my_thread3.setNextThread(my_thread1);
		my_thread1.start();
		my_thread2.start();
		my_thread3.start();
		my_thread1.interrupt();
		my_thread1.join();
		my_thread2.join();
		my_thread3.join();
		System.out.println("main");
	}
}