import java.util.concurrent.atomic.AtomicInteger;

public class Threaded {
  public static void main(String[] args) throws InterruptedException {
    final AtomicInteger counter = new AtomicInteger();

    class CountingThread extends Thread {
      public void run() {
        for(int x = 0; x < 10000; ++x)
          counter.incrementAndGet();
      }
    }

    CountingThread thread1 = new CountingThread();
    CountingThread thread2 = new CountingThread();

    thread1.start();
    thread2.start();

    thread1.join();
    thread2.join();

    System.out.println(counter.get());
  }
}
