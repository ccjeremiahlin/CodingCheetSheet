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
      //atomic_exchange
    }
    void put(){
      //atomic_exchange
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
    }
    cout<<"count up () finished"<<endl;
    m_done=true;
  }
  void print(){
    //print until done
    cout<<"Counting: "<<m_count<<endl;
    cout<<flush;
    cout<<"print() finished"<<endl;
  }

  public:
  ThreadCounter():m_done(false){}
  void run(){
    //run thread countup
    //run thread print
    //join both thread
  }
};

int main(){
  ThreadCounter tc;
  tc.run();
  return 0;
}
