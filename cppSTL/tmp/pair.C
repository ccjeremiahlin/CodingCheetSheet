#include <iostream>
using namespace std;
int main(){
  int a1=1, a2=2;
  pair<int &, int &> apair = make_pair(ref(a1), ref(a2));
  cout<<apair.first<<" "<<apair.second<<endl;
  apair.first = 3;
  apair.second = 4;
  cout<<a1<<" "<<a2<<endl;
}
