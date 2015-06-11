#include <iostream>
#include <vector>
using namespace std;
#define SIZE 9
bool toggleBitMap(int val, int &checkbitmap){
   int hashIndex = 1<<val;
   if(!(checkbitmap & hashIndex)){
       checkbitmap|=hashIndex;
       return true;
   }
   return false;
}
bool isValidSudoku(vector<vector<int> > &grid){
    //check row
    int row, col, checkbitmap;
    for(row=0;row<SIZE;row++){
        checkbitmap = 0;
        for(col=0;col<SIZE;col++){
            if(!toggleBitMap(grid[row][col], checkbitmap))return false;
        }
    }
    //check column
    for(col=0;col<SIZE;col++){
        checkbitmap = 0;
        for(row=0;row<SIZE;row++){
            if(!toggleBitMap(grid[row][col], checkbitmap))return false;
        }
    }
    //check subSquare
    int sqRow, sqCol;
    const int sqStep=SIZE/3;
    for(sqRow=0;sqRow<SIZE;sqRow+=sqStep){
        for(sqCol=0;sqCol<SIZE;sqCol+=sqStep){
            checkbitmap = 0;
            for(row=0;row<3;row++){
                for(col=0;col<3;col++){
                    if(!toggleBitMap(grid[sqRow+row][sqCol+col], checkbitmap)) return false;
                }                
            }
        }
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tmpInput;
    int countInteger=0;
    vector<vector <int> > grid(SIZE, vector<int>(SIZE,0));
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            char a;
            cin>>a;
            grid[i][j]=a-'0';
        }
    }
    for(auto a : grid)
      for(int i : a)
        cout<<i<<" ";
    cout<<endl;
    cout<<boolalpha<<isValidSudoku(grid)<<endl;
    return 0;
}
