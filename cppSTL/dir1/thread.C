#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;
mutex m;
condition_variable cv;
bool ready=false;

void work_for_thread(int id){
  if(id%2){
    return;
  }
  unique_lock<mutex> lk(m);
  cv.wait(lk, [](){return ready;});
  cout<<"From thread # "<<id<<endl;
  lk.unlock();
  cv.notify_one();
}

int main(){
  int parts = 4;
  cout<<"Hardware Concurrency: "<<thread::hardware_concurrency()<<endl;
  vector<thread> thpool;
  for(int i=0;i<parts;i++){
    thpool.push_back(thread(work_for_thread, i));
  }

  //lock and notify
  {
    unique_lock<mutex> lk(m);
    ready = true;
  }
    cv.notify_one();

  for(thread &th : thpool){ //NOTE!!! pay attention to the &
    th.join();
  }
  cout<<"End"<<endl;
}
