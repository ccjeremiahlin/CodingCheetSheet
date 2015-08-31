#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Container>
void dump(Container &s){
  for(auto i: s){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main(){
  set<int> s;
  /* back_inserter only applies to container that supports push_back() function */
  generate_n(inserter(s, s.end()), 10, [&](){return rand()%10;});
  dump(s);
  auto itbegin3 = s.begin();
  advance(itbegin3, 2);
  auto itbegin1 = prev(itbegin3, 2);
  auto itbegin5 = next(itbegin3, 2);
  cout<<*itbegin1<<endl;
  cout<<*itbegin3<<endl;
  cout<<*itbegin5<<endl;
  return 0;
}
