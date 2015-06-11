#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashMap{
  /*
   *  chaining -> pair
   */
  hash<string> hashFn; 
  vector<vector<pair<string, string>>> _table;
  size_t _size;
  size_t _bucketSize;
  size_t _capacity;
  string dummy;
  pair<bool, string&> get(const string&);
  public:
  HashMap(): _size(0), _bucketSize(0), _capacity(4){
    _table.resize(_capacity);
  }
  void insert(const string &key, const string &value);
  string & operator[](const string & key);
  void erase(const string &key);
  size_t count(const string &key);
  size_t size(){return _size;}
};


pair<bool, string &> HashMap::get(const string & key){
  size_t hashIndex = hashFn(key)%_capacity;
  for(size_t i=0;i<_table[hashIndex].size();i++){
    if(_table[hashIndex][i].first == key){
      return make_pair(true, ref(_table[hashIndex][i].second));
    }
  }
  return make_pair(false, ref(dummy));
}

void HashMap::insert(const string &key, const string &value){
  //full condition
  if(_bucketSize==_capacity){
    size_t _newcapacity = _capacity;
    while(_newcapacity<=_size)_newcapacity<<=1;
    size_t _newBucketSize=0;
    vector<vector<pair<string, string>>> _newTable(_newcapacity); 
    for(size_t i=0;i<_capacity;i++){
      for(size_t j=0;j<_table[i].size();j++){
        size_t newHashIndex = hashFn(_table[i][j].first)%_newcapacity;
        if(_newTable[newHashIndex].empty())_newBucketSize++;
        _newTable[newHashIndex].push_back(move(_table[i][j]));
      }
    }
    _bucketSize = _newBucketSize;
    _capacity = _newcapacity;
    _table.swap(_newTable);
  }
  //collision and update
  auto p = get(key);
  if(p.first){
    p.second = value;
    return;
  }
  size_t hashIndex = hashFn(key)%_capacity;
  _table[hashIndex].push_back(make_pair(key, value));
  _size++;
}
string & HashMap::operator[](const string &key){
  auto p = get(key);
  if(p.first) return p.second;
  insert(key, "");
  auto q = get(key);
  return q.second;
}
void HashMap::erase(const string &key){
  size_t hashIndex = hashFn(key);
  for(size_t i = 0 ; i<_table[hashIndex].size(); i++){
    if(_table[hashIndex][i].first == key){
      _table[hashIndex].erase(_table[hashIndex].begin()+i);
      return ;
    }
  }
}
size_t HashMap::count(const string &key){
  size_t hashIndex = hashFn(key);
  for(size_t i=0;i<_table[hashIndex].size(); i++){
    if(_table[hashIndex][i].first == key) return 1;
  }
  return 0;
}

int main(){
  HashMap strmap;
  for(int i=0;i<10;i++){
    strmap[to_string(i)]=to_string(i)+"lala";
    //strmap.insert(to_string(i), to_string(i)+"lala");
  }
  for(int i=0;i<10;i++){
    cout<<to_string(i)<<" : "<<strmap[to_string(i)]<<endl;
  }
}
