#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  srand(time(0));
  int M = rand()%10;
  int N = rand()%10;
  int twodAry[M][N];
  for(int i=0;i<M;++i){
    for(int j=0;j<N;++j){
      cout<<setw(11)<<twodAry[i][j]<<" ";
    }
    cout<<endl;
  }
}
