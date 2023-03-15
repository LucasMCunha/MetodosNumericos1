#include <iostream>
#include<sstream>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <climits>

using namespace std;

auto splitter(vector<string> base, string S) { //arrumar pra botar elemento em V
  istringstream iss = (istringstream)S;
  string s;
  while ( getline( iss, s, ' ' ) ) {
    base.push_back(s.c_str());
      cout << "\n"<< s.c_str();
  }
  return base;
}

bitset<sizeof(float) * CHAR_BIT> floatToRawIntBits(float F){
  union
  {
    float input; 
     int output;
  } data;

  data.input = F;

  bitset<sizeof(float) * CHAR_BIT>                 bits(data.output);
  cout << "\n" << bits << std::endl;
  return bits;
}

float intBitsToFloat(bitset<sizeof(float) * CHAR_BIT> B){
  return 0.0;
}

int main() {
vector<string> base;
string s = "1.00 + 2.00";
base = splitter(base,s);
    bitset<sizeof(float) * CHAR_BIT> raw1 = floatToRawIntBits(std::stof(base.at(0)));
    bitset<sizeof(float) * CHAR_BIT> raw2 = floatToRawIntBits(std::stof(base.at(2)));

    float val1 = intBitsToFloat(raw1);
    float val2 = intBitsToFloat(raw2);
    
    float aws = 0.0;
    
    switch(base.at(1)){
      case ("+"):
        aws = val1  + val2;
        break;
      
      case ("-"):
        aws = val1  - val2;
        break;
      
      case ("*"):
        aws = val1  * val2;
        break;
      
      case ("/"):
        aws = val1  / val2;
        break;
    }

  /*
    int rawAws = floatToRawIntBits(aws);
    
    System. out.println("Var 1 " + raw1 + " = " +val1);
    System. out.println("Var 2 " + raw2 + " = " +val2);
    System. out.println("Aws " + rawAws + " = " +aws);

*/
  }
}

