#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Test{
  char _c;
  int _i;
  string _s;
  public:
    Test(char a='a', int i=0, string s="init"): _c(a), _i(i), _s(s){}
    friend ostream & operator<<(ostream &os, Test &t){
      os.write((char *)&t, sizeof(t));
      return os;
    }
    friend istream & operator>>(istream &is, Test &t){
      is.read((char *)&t, sizeof(t));
      return is;
    }
    string toString(){
      string t;
      t.append("c: ");
      t.push_back(_c);
      t.append(" i: "+to_string(_i));
      t.append(" s: "+_s);
      return t;
    }
};

int main(){
  //test output
  ofstream  ofs("testout", ios::binary|ios::out);
  for(int i=0;i<10;i++){
    Test t('a'+i, i, "["+to_string(i)+"]");
    ofs<<t;
  }
  ofs.close();
  //test input
  ifstream ifs("testout", ios::binary|ios::in);
  Test t;
  while((ifs>>t)){
    cout<<t.toString()<<endl;
  }
  ifs.close();
  return 0;
}
