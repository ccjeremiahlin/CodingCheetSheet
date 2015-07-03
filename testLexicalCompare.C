#include <iostream>
using namespace std;
bool lexicalCompare(int left, int right){
        int tLeft=1, tRight=1;
        while(tLeft*10<=left)tLeft*=10;
        while(tRight*10<=right)tRight*=10;
        while(tLeft>1 || tRight>1){
            int L = left/tLeft;
            int R = right/tRight;
            if(L>R) return true;
            if(L<R) return false;
            left = (tLeft==1)?left:left%tLeft;
            right = (tRight==1)?right:right%tRight;
            tLeft = (tLeft==1)?tLeft:tLeft/10;
            tRight = (tRight==1)?tRight:tRight/10;
        }
        return left>right;
}
int main(){
  cout<<boolalpha<<lexicalCompare(8247, 824)<<endl;
  return 0;
}
