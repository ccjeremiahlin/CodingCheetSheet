#include<string>
#include<iostream>
using namespace std;
int main(){
  string s="test string operations";
  cout<<s<<endl;
  //append
  s.push_back('C');
  s.append(" to the tail");
  cout<<s<<endl;
  //insert
  s.insert(s.begin()+3, 'i');
  s.insert(4, "inserted");
  cout<<s<<endl;
  //erase
  s.erase(s.begin()+3, s.begin()+10);
  cout<<s<<endl;
  //relpace
  s.replace(s.begin(), s.begin()+4, "replace");
  cout<<s<<endl;
  //substr
  cout<<s.substr(3, 5)<<endl;
  //copy
  string tmp = s;
  cout<<tmp<<endl;
  //compare 
  cout<<boolalpha<<s.compare(tmp)<<endl;
  tmp.replace(s.find("operations"), strlen("operations"), "no");
  cout<<tmp<<endl;
  cout<<boolalpha<<s.compare(tmp)<<endl;
  //find, find_first_of, find_first_not_of, find_last_of, find_last_not_of
  int pos = s.find("something");
  int firstPosOfCharinSth = s.find_first_of("something");
  int findfirstnotofpos = s.find_first_not_of(" ");
  int findlastof = s.find_last_of("last");
  int findlastnotof = s.find_last_not_of("lastnot");
  //
  //stoi, stol, stoll, stoul, stof, stod, stold, 
  int integervaluefromstring = stoi("14");
  int longvaluefromstring = stol("111111111111111111");
  int doublefromstringvalue = stold("111111111111.11111111111");
  //
  //to_string
  string integerstring = to_string(111111111);
  string doublestring = to_string(11111111111.111111111);

  return 0;
}

