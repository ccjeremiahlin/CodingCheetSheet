#include <CommonCrypto/CommonDigest.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>

#define STEP 2
#define MYEMAIL "cc.jeremiah.lin@gmail.com"
#define ANVATO "anvato.com"

using namespace std;

string myEmailDigestStr;

string dumpDigest(unsigned char *digest){
  stringstream os;
  for(int i=0;i<CC_MD5_DIGEST_LENGTH;i++){
    os<<setw(2)<<setfill('0')<<hex<<(digest[i]&0x00ff);
  }
  return os.str();
}

bool checkHelper(string &hashvalue, int index, string &dict, string &result, bool readyToCheck){
    if(index>=hashvalue.size()){
      cout<<"matched Length: "<<index<<endl;
      return true;
    }
    for(char a : dict){
      result.push_back(a);
      if(readyToCheck){
        /*
          md5(md5('cc.jeremiah.lin@gmail.com') + 'he' + md5('he')) +
        */
        unsigned char tmpCharBuffer[CC_MD5_DIGEST_LENGTH];
        CC_MD5((const unsigned char*)result.c_str(), result.size(), (unsigned char*)tmpCharBuffer); 
        string tmpStrBuffer = myEmailDigestStr + result + dumpDigest(tmpCharBuffer);
        CC_MD5((const unsigned char*)tmpStrBuffer.c_str(), tmpStrBuffer.size(), (unsigned char*)tmpCharBuffer); 
        if(dumpDigest(tmpCharBuffer) == hashvalue.substr(index, CC_MD5_DIGEST_LENGTH*2)){
          if(checkHelper(hashvalue, index+CC_MD5_DIGEST_LENGTH*2, dict, result, false)){
            return true;
          }else{
            cout<<index+CC_MD5_DIGEST_LENGTH*2<<endl;
            break;
          }
        }
      }else{
        if(checkHelper(hashvalue, index, dict, result, true)){
          return true;
        }
      }
      result.pop_back();
    }
    return false;
}

int main(){
  string hashvalue="99ac65a9642f01a439fd8537921ecc14d6e6de5339718b213886c5327f1ca11b10af1cb715c0b9769ec500aaf2fe89afbcbdb424d601026f6a513935564bffc0321c219e05384539127f15045a98c9ab650f26ab43e27f42fe838ae4a283f8267991e2c138489210f703635a64226f4075893003bc576a31842f26128795a899b123b99cf3c31b45dbb4c8cf385a204be0fc6bfeeaffdf3c55757d31207fea70f11da9977e8e55cbd52935d5bf5f822a40288cbd614bf3769323cd685eb02b66dec9455161a00c2605c645b608347ace4ef425efdfecacad9084c85d187a10786abb7a07d9899f6d89a15f3685421c4fe722cfea7276d4bc0a314d05541265c9f610cd26c04c87e262c97e9d4bacec5e9ebe1c0f1f8a211404d66239abe2ae9c73f637051b74c6ed1d787b495c3ebcc1b4c335a62fe1d26b4c6cc296e8cbcfc1e330b2226fbf64ed45405c4e8f6a25a6ba3f1b278b04e9a8f3447ed08e3f384697f924821292261e107c7bdd19a1de89377c2e45a88c329b3ad0d230abd569d0e9167953f65f936aa8bdbfc84fe40b4358a45591551d432b23754518a5139c6dabef93350df4cf7a1c00088d7784cb44579cc3aaa1b0baa43d4348a26db54c66";

  string myEmail=MYEMAIL;

  int hashRound = hashvalue.size()/CC_MD5_DIGEST_LENGTH;
  unsigned char myEmailDigest[CC_MD5_DIGEST_LENGTH];

  CC_MD5((const unsigned char*)myEmail.c_str(), myEmail.size(), (unsigned char*)myEmailDigest); 
  myEmailDigestStr = dumpDigest(myEmailDigest); 
  string dict(126-31, 0);
  iota(dict.begin(), dict.end(), ' ');
  cout<<dict<<endl;
  string result;

  bool found = checkHelper(hashvalue, 0, dict, result, false);
  cout<<"Solution found?: "<<boolalpha<<found<<" Now: "<<result<<endl;

  return 0;
}
