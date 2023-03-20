#include <iostream>
#include<sstream>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <climits>

using namespace std;

/*
auto splitter(vector<string> base, string S) { 
  istringstream iss = (istringstream)S;
  string s;
  while ( getline( iss, s, ' ' ) ) {
    base.push_back(s.c_str());
     // cout << "\n"<< s.c_str();
  }
  return base;
}
*/

string floatToRawIntBits(float F){
  union
  {
    float input; 
     int output;
  } data;

  data.input = F;

  bitset<32>bits(data.output);
  string bit = bits.to_string();
  string sup = "";
for(int i = 0; i <bit.length(); i++){
  if (i == 0 || i == 8){
    sup=sup+bit[i] + " ";
    } else {
    sup=sup+bit[i];
    }
}
  bit = sup;
  //cout << "\n" << bit << std::endl;
  return bit;
}

int main(int argc, char **argv) {
vector<string> base;
//string s = argv[1];
//base = splitter(base,s);
float val1 = stof(argv[1]);
float val2 = stof(argv[3]);
string raw1 = floatToRawIntBits(val1);
string raw2 = floatToRawIntBits(val2);
float aws = 0.0;
  if (argv[2][0] == '+'){
    aws = val1+val2;  
  }
  if (argv[2][0] == '-'){
    aws = val1-val2;
  }
  if (argv[2][0] == '*'){
    aws = val1*val2;
  }
  if (argv[2][0] == '/'){
    aws = val1/val2;
  }
string rawAws = floatToRawIntBits(aws);
cout << "Var 1    " << raw1 << " = " << val1 << endl;
cout << "Var 2    " << raw2 << " = " << val2 << endl;
cout << "Resposta " << rawAws << " = " << aws << endl;
  }

