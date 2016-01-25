#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;
class Semaphore {
  atomic_int m_signaled;
  public:
    Semaphore(bool initial=false){
      m_signaled=initial;
    }
    void take(){
      while(!atomic_load(&m_signaled)){
        this_thread::sleep_for(chrono::milliseconds(10));
      }
      atomic_store(&m_signaled, 0);
    }
    void put(){
      atomic_store(&m_signaled, 1);
    }
};

class ThreadCounter{
  static const int N = 100;
  static const int REPORT_INTERVAL = 10;
  int m_count;
  bool m_done;
  Semaphore m_count_sem;
  Semaphore m_print_sem;
  void count_up(){
    for(m_count=1;m_count<N;m_count++){
        m_print_sem.put();
        m_count_sem.take();
    }
    cout<<"count up () finished"<<endl;
    m_done=true;
    m_print_sem.put();
  }
  void print(){
    do{
      m_print_sem.take();
      cout<<"Counting: "<<m_count<<endl;
      cout<<flush;
      m_count_sem.put();
    }while(!m_done);
    cout<<"print() finished"<<endl;
  }

  public:
  ThreadCounter():m_done(false){}
  void run(){
    thread tdcount(&ThreadCounter::count_up, this);
    thread tdprint(&ThreadCounter::print, this); 
    tdprint.join();
    tdcount.join();
  }
};

int main(){
  ThreadCounter tc;
  tc.run();
  return 0;
}
