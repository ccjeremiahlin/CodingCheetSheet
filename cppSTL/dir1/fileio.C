#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class testStructure{
  public:
  char _a;
  int _b;
  string _c;
  testStructure(char a='a', int b=0, string c="init"):_a(a), _b(b), _c(c){
  }
};
int main(int argc, char *argv[]){
  if(argc<2)return 1;
  cout<<argv[0]<<" "<<atoi(argv[1])<<endl;

  //output
  ofstream fs("testoutput", ios::binary|ios::out); 
  if(!fs)return 1;
  for(int i=0;i<atoi(argv[1]);i++){
    testStructure tmp('a'+i, i, "str"+to_string(i));
    fs.write(reinterpret_cast<char *>(&tmp), sizeof(tmp));
  }
  fs.close();
  //intput
  ifstream ifs("testoutput", ios::in); 
  if(!ifs)return 1;
  testStructure tmp;
  while(ifs.read(reinterpret_cast<char *>(&tmp), sizeof(tmp))){
    cout<<"char a: "<<tmp._a<<endl;
    cout<<"int b: "<<tmp._b<<endl;
    cout<<"string c: "<<tmp._c<<endl;
    cout<<"gcount: "<<ifs.gcount()<<endl;
  }
  ifs.close();
  return 0;
}
