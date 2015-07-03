#include<string>
#include<iostream>
using namespace std;
int main(){
  string s;
  //append
  s.append("test");
  s.append(5, 'z');
  //insert
  s.insert(0, 5, 'c');
  s.insert(s.end(), 'a');
  s.insert(s.size(), "ab");
  s.erase(0, 3);
  s.erase(s.begin()+1);
  //erase
  //relpace
  s.replace(0, 3, "replace");
  s.replace(s.begin(), s.begin()+4, "first");
  //substr
  //copy
  //compare 
  //find, find_first_of, find_first_not_of, find_last_of, find_last_not_of
  cout<<s.find("first")<<endl;; 
  //
  //stoi, stol, stoll, stoul, stof, stod, stold, 
  //
  //to_string
  cout<<s<<endl;
  return 0;
}

