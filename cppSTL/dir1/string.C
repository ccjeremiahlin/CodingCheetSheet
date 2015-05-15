#include<string>
#include<iostream>
using namespace std;
int main(){
  string s="test string operations";
  cout<<s<<endl;
  //append
  s.append(2, ' ');
  s.append("new tail");
  s.append("append sub", 6, 4);
  cout<<s<<endl;
  //insert
  s.insert(0, 3, ' ');
  s.insert(3, "new head ");
  cout<<s<<endl;
  //erase
  s.erase(0, 3);
  s.erase(s.find("string"), 6);
  cout<<s<<endl;
  //relpace
  s.replace(s.find("operations"), strlen("operations"), "op");
  cout<<s<<endl;
  //substr
  cout<<s.substr(4,8)<<endl;//pos, count
  //copy
  string newstr=s;;
  //compare 
  cout<<boolalpha<<s.compare(newstr)<<endl;
  return 0;
}

