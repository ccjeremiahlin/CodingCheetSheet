/* 
*  
*  
  1. go through the input string, creat a hashmap to keep the count of each character
  2. sort the combination by the freqency of the charactoer, 
  2.1 key   value
      char   freq 
  2.2 key   value   <--- ordered map, decreasing,  
      freq   char list []
  3. encode from the highest frequency with 1, 01, .... 

*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

#define DEBUG 1
using namespace std;

// To execute C++, please define "int main()"
unordered_map<char, string> codebook;
unordered_map<string, char> decodeBook;

string encode(string &inputString){
  string outputResult;
  unordered_map<char, int> charFreqTable;
  //!!!!! If I have to change the comparater of the map, I have to do it like this.
  map<int, vector<char>, greater<int> > freqCharMap;
  //!!!!!


  for(char ch : inputString){
    charFreqTable[ch]++;
  }

  for(auto charFreqEntry : charFreqTable){
    freqCharMap[charFreqEntry.second].push_back(charFreqEntry.first);
  }
  //encode 
  //the same freq: 1, 01, 001, 
  //next highest freq:  0001
  string tmpEncodePattern;
  for_each(freqCharMap.begin(), freqCharMap.end(), [&](pair<int, vector<char> > freqCharEntry){
    for(char ch : freqCharEntry.second){
      if(!tmpEncodePattern.empty())
        tmpEncodePattern[tmpEncodePattern.size()-1]='0';
      tmpEncodePattern.push_back('1');
      codebook[ch] = tmpEncodePattern;
      decodeBook[tmpEncodePattern] = ch;
    }
  });

  for(char ch : inputString){
    outputResult.append(codebook[ch]);
  }
  
  return outputResult;
}

string decode(string & inputString){
  string outputString;
  int index=0;
  while(index<inputString.size()){
    int nextOne = inputString.find_first_of("1", index);
    //0 1 2 3 4
    //0 0 0 1
    //i
    string key = inputString.substr(index, nextOne-index+1);
    outputString.push_back(decodeBook[key]);
    index=nextOne+1;
  }
  return outputString;
}


int main() {
  string inputString("aaabbbc");
  string outputString = encode(inputString);
  cout<<"Input: "<<inputString<<endl;
  cout<<"Output: "<<outputString<<endl;
  string shouldBeOrigString = decode(outputString);
  cout<<"Encoded: "<<outputString<<endl;
  cout<<"Decoded: "<<shouldBeOrigString<<endl;
  return 0;
}

