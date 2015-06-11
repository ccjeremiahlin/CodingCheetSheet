#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  cout<<showpoint<<1234.0<<endl;
  cout<<showpos<<1234.0<<endl;
  cout<<setw(10)<<setfill('c')<<setprecision(2)<<hex<<fixed<<right<<1234.0<<endl;
}
