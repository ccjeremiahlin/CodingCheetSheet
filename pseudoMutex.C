class Mutex{
  bool is_held;
  Spinlock lock;
  ThreadQueue queue;
  Mutex():is_held(false){}
  void acquire(){
    lock.lock();
    while(is_held){
      /*
       * my initial not perfect answer
      lock.unlock();
      //interrupt and context switch could happen here
      //in this case, the thread releasing the mutex during this span
      //will not be able to wakeup the thread going to sleep 
      queue.sleep();
      */

      //correct answer
      queue.sleep(lock);//atomic operation of unlock and then sleep

      lock.lock();
    }
    is_held=true;
    lock.unlock();
  }
  void release(){
    lock.lock();
    is_held=false;
    lock.unlock();
    queue.wakeup_front();
  }
};
