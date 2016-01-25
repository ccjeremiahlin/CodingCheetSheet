#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <algorithm>
using namespace std;

timed_mutex tm1, tm2;

bool ready=false;

void work_for_thread(int id){
  switch(id%2){
    case 0:
    //defer initialilize locks
    //lock 2 without sequence
    {
      unique_lock<timed_mutex> l1(tm1, defer_lock);
      unique_lock<timed_mutex> l2(tm2, defer_lock);
      lock(l1,l2);
      this_thread::sleep_for(chrono::seconds(1));
      cout<<"Get unique lock tm1, tm2 from thread id: "<<id<<endl;
    }
    break;
    case 1:
    //timed lock
    {
      unique_lock<timed_mutex> l1(tm1, defer_lock);
      if(l1.try_lock_for(chrono::milliseconds(1))){
        cout<<"Get unique lock within 1 ms from thread id: "<<id<<endl;
      }else{
        cout<<"Failed to get timed lock from thread id: "<<id<<endl;
      }
    }
      break;
    default:
      cout<<"Do Nothing"<<endl;
  }
}

int main(){
  int parts;
  //load hardware concurrency
  parts = thread::hardware_concurrency(); 
  cout<<"Hardware concurrency: "<<parts<<endl;
  //init thread pool
  //push thread to pool (and run)
  vector<thread> thpool;
  int count=0;
  generate_n(back_inserter(thpool), parts, [&](){return thread(work_for_thread, count++);});
  //join treads
  for_each(thpool.begin(), thpool.end(), [](thread &th){th.join();});
  cout<<"End"<<endl;
}
