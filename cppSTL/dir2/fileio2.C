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
  friend ostream& operator<<(ostream& os, testStructure &out){
    os.write((char*)&out, sizeof(testStructure)); 
    return os;
  }
  friend istream& operator>>(istream& is, testStructure &out){
    is.read((char*)&out, sizeof(testStructure));
    return is;
  }
};


int main(int argc, char *argv[]){
  if(argc<2){
    cout<<"Usage: exec_file #_of_structure_to_write"<<endl;
    return 1;
  }
  cout<<argv[0]<<" "<<atoi(argv[1])<<endl;

  int N = atoi(argv[1]);
  //output: write structure
  ofstream ofs("output.txt", ios::binary|ios::out);
  for(int i=0;i<N;i++){
    testStructure tmp('a'+i, i, to_string(i));
    ofs<<tmp;
  }
  ofs.close();
  //input: read structure
  ifstream ifs("output.txt", ios::in|ios::binary);
  testStructure in;
  while( (ifs>>in) ){
    cout<<"Char a: "<<in._a<<" ";
    cout<<"Int b: "<<in._b<<" ";
    cout<<"String c: "<<in._c<<endl;
  }
  ifs.close();
  return 0;
}
