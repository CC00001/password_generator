#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
using namespace std;

template<typename A, typename L>
vector<A> make_permutation(const vector<A> array, L len){
 if(len == 0) return array;
 vector<A> results = make_permutation(array, len - 1);
 vector<A> temp;
 for(L i = 0; i <= array.size(); i++){
  temp.push_back(i);
 
 for(auto r : results){
  results.push_back(i + r);	  
  }
 }
 return results;
}

class Comb{
private:
 vector<char>character;
 int* number;
 int lengthChar, lengthNum;

public:
 Comb(){ //Default constructor
  //character = new char[lengthChar];
  number = new int[lengthNum];
 }
 
 Comb(const int lc, const int ln){ //Constructor with paramters
  lengthChar = lc;
  lengthNum = ln;
 }

  //Method: Set comb of passwords
 void setPasswd(const int lengthChar, const int lengthNum){
  vector<char> tempChar;
  vector<int> tempNum;
  for(char c = 'a'; c <= 'z'; c++){
   tempChar.emplace_back(c);
  }
  character = make_permutation(tempChar, lengthChar);
  for(int i = 0; i < lengthNum; i++){
   for(int j = i+1; j < lengthNum; j++){
    tempNum.push_back(i+j);
   }
  }
  for(int i = 0; i <= lengthNum; i++){
   if(tempNum[0]/tempNum.size() == lengthNum)
    number[i] = tempNum[i];
  }
 }

 void printComb(){
  for(int i = 0; i <= sizeof(character); i++){
   for(int j = 0; j <= number[0]/sizeof(number); j++){ 
    std::cout << character[i] << number[j] << endl;
   }
  }
 } 
};

/*std::ostream& operator << (std::ostream& output,Comb comb){ //overload extraction operator(it must be decleared before int main() )
    output << comb.getChar() << comb.getNum() << " ";
    return output;
}
*/

/*Comb& Comb::operator [] (vector<Comb> a){
   for(auto i = a.begin(); i != a.end(); i++){
     return a[i];
    }
}*/

int main(){
   ofstream o;
   o.open("password.txt");
   vector<Comb> array;  
   Comb comb;
  
   comb.setPasswd(3, 3);
   comb.printComb(); 

   o.close();

 return 0;
}
