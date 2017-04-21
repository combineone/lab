public class Threaded {
  public static void main(String[] args) throws InterruptedException {
    class Counter {
      private int count = 0;

      public synchronized void increment() {
        ++count;
      }

      public int getCount() {
        return count;
      }
    }

    final Counter counter = new Counter();

    class CountingThread extends Thread {
      public void run() {
        for(int x = 0; x < 10000; ++x)
          counter.increment();
      }
    }

    CountingThread thread1 = new CountingThread();
    CountingThread thread2 = new CountingThread();

    thread1.start();
    thread2.start();

    thread1.join();
    thread2.join();

    System.out.println(counter.getCount());
  }
}
