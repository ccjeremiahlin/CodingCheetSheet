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
  int parts;
  //load hardware concurrency
  //
  //init thread pool
  //push thread to pool (and run)
  //lock and notify

  //join treads
  cout<<"End"<<endl;
}
