#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;
class Semaphore {
  atomic<int> m_lock;
  public:
  Semaphore():m_lock(0){}
  void get(){
    while(!atomic_exchange<int>(&m_lock, 0));
  }
  void put(){
    atomic_store<int>(&m_lock, 1);
  }
};

class ThreadCounter{
  static const int N = 100;
  static const int PRINTINTERVAL=10;
  bool m_done;
  int m_count;
  Semaphore m_count_lock;
  Semaphore m_print_lock;
  void count_up(){
    for(m_count=0;m_count<N;m_count++){
      if(m_count%PRINTINTERVAL==0){
        m_print_lock.put();
        m_count_lock.get();
      }
    }
    cout<<"count up () finished"<<endl;
    cout<<flush;
    m_done=true;
    m_print_lock.put();
  }
  void print(){
    do{
      m_print_lock.get();
      cout<<"Counting: "<<m_count<<endl;
      m_count_lock.put();
    }while(!m_done);
    cout<<"print() finished"<<endl;
  }

  public:
  ThreadCounter():m_done(false), m_count(0){}
  void run(){
    //run thread countup
    auto countThread = thread(&ThreadCounter::count_up, this);
    //run thread print
    auto printThread = thread(&ThreadCounter::print, this);
    //join both thread
    countThread.join();
    printThread.join();
  }
};

int main(){
  ThreadCounter tc;
  tc.run();
  return 0;
}
