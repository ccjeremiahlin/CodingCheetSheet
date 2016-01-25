#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;
class Semaphore {
};

class ThreadCounter{
  void count_up(){
    cout<<"count up () finished"<<endl;
  }
  void print(){
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
