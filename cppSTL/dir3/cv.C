#include <condition_variable>
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <future>
#include <algorithm>
#include <numeric>
using namespace std;

/* why condition variable? 
 *  1. lock/unlock usage is not able to guarrantee the order of threads
 *  2. pair locks are ugly.
 */
mutex m;
bool ready;
condition_variable cv;
void offload_work(int workid){
  switch(workid%2){
    case 0:
      {
        unique_lock<mutex> l1(m);
        ready=true;
        this_thread::sleep_for(chrono::seconds(3));
        cout<<"Produce!"<<endl;
      }
      cv.notify_one();
      break;
    case 1:
      {
        unique_lock<mutex> l2(m);
        cout<<"Waiting!!"<<endl;
        cv.wait(l2, [&](){return ready;});
        cout<<"Comsume!"<<endl;
      }
      break;
  }
}

int main(){
  vector<thread> thpool; 
  thpool.push_back(thread(offload_work,1));
  thpool.push_back(thread(offload_work,0));
  for(thread &th: thpool){
    th.join();
  }
  return 0;
}
