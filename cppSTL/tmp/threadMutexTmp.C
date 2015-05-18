#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
using namespace std;

mutex m1, m2;
timed_mutex tm;
mutex sharedm;

bool ready=false;

void work_for_thread(int id){
  switch(id%4){
    case 0:
    //defer initialilize locks
    //lock 2 without sequence
      break;
    case 1:
    //timed lock
      break;
    case 2:
    //shared lock for read
      break;
    case 3:
    //exclusive lock for write
      break;
    default:
      ;
  }
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
