#include <condition_variable>
#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

condition_variable cv;
mutex m;
bool cv_flag=false;
/* why condition variable? 
 *  1. lock/unlock usage is not able to guarrantee the order of threads
 *  2. latency of suspension/wakening 
 *  3. pair locks are ugly.
 */
void sequential_work(int id){
  switch(id%4){
    case 0:
      //remember to unlock first after notify
      {
        unique_lock<mutex> lock(m);
        cv_flag = true;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Notification sent!"<<endl;
      }
      cv.notify_all();
      break;
    default:
      {
        unique_lock<mutex> lock(m);
        cout<<"Waiting ..."<<endl;
        cv.wait(lock, [&](){return cv_flag;});
        cout<<"Notification received!"<<endl;
      }
      break;
  }
}
int main(){
  int parts = thread::hardware_concurrency();
  vector<thread> thpool;
  int thcount=0;
  generate_n(back_inserter(thpool), parts, [&](){return thread(sequential_work, thcount++);}); 
  for_each(thpool.begin(), thpool.end(), [&](thread & th){th.join();});
  return 0;
}
