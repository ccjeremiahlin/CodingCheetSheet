#include <vector> 
#include <algorithm> 
#include <iostream>

using namespace std;

class Task{
public:
    Task(int s, int e):start(s), end(e){}
    int start;
    int end;
};

bool compare(const Task &left, const Task &right){
    return left.end < right.end;
}

vector<Task> getMaximumThingsDone(vector<Task> &vt){
    sort(vt.begin(), vt.end(), compare);
    vector<Task> result;
    int N = vt.size(); 
    for(int i=0;i<vt.size();i++){
      cout<<"{ "<<vt[i].start<<" , "<<vt[i].end<<" } ";
    }
    cout<<endl<<endl;
    for(int i=0;i<N;i++){
        //for every element, we will compare if the start time is less than the end time of the previous one.
        if(result.empty()){
            result.push_back(vt[i]);
        }else{
            if(vt[i].start >= result.back().end) {
                result.push_back(vt[i]);
            }
        }
    }
    return result;
}

int main(){
  vector<Task> testTask;
  srand(time(0));
  for(int i=0;i<20;i++){
    int begin=rand()%20;
    int end=begin+rand()%20;
    testTask.emplace_back(begin, end);
  }
  for(int i=0;i<testTask.size();i++){
    cout<<"{ "<<testTask[i].start<<" , "<<testTask[i].end<<" }";
  }
  cout<<endl;
  cout<<endl;
  vector<Task> result = getMaximumThingsDone(testTask);
  for(int i=0;i<result.size();i++){
    cout<<"{ "<<result[i].start<<" , "<<result[i].end<<" }";
  }
  cout<<endl;
  return 0;
}
