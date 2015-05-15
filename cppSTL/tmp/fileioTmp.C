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
  if(argc<2){
    cout<<"Usage: exec_file #_of_structure_to_write"<<endl;
    return 1;
  }
  cout<<argv[0]<<" "<<atoi(argv[1])<<endl;

  //output: write structure
  //input: read structure
  return 0;
}
