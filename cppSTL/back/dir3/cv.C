#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

condition_variable cv;
mutex m;
bool release=false;

void producer(int pid){
  {
    unique_lock<mutex> lock(m);
    cout<<"Notification sent!! from "<<pid<<endl;
    release = true;
  }
  cv.notify_all();
}

void consumer(int pid){
  unique_lock<mutex> lock(m);
  cout<<"Waiting ..."<<pid<<endl;
  cv.wait(lock, [&](){ return release; });
  this_thread::sleep_for(chrono::seconds(1));
  cout<<"Notification Received"<<pid<<endl;
}
void sequential_work(int pid){
  switch(pid%4){
    case 1:
      producer(pid);
      break;
    default:
      consumer(pid);
  }
}

int main(){
  int N = thread::hardware_concurrency();
  int thcount = 0;
  vector<thread> thvector; 
  generate_n(back_inserter(thvector), N, [&](){ return thread(sequential_work, thcount++);});
  for(auto &th: thvector)th.join();
  return 0;
}
