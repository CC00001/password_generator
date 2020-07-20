#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
using namespace std;

class Comb{
private:
 char character;
 int number;
 int digit;
 vector<char> charArr;

public:
 Comb(){ //Default constructor
  character = ' ';
  number = 0;
  digit = 0;
  vector<char> charArr {}; //Define empty vector by using {}
 }
 
 Comb(const char &c, int n, int d, vector<char> &ca){ //Constructor with paramters
  character = c;
  number = n;
  digit = n;
  charArr = ca;
 }

 Comb(const Comb &passwd){ //Constructor with generic datatype
  character = passwd.character;
  number = passwd.number;
  digit = passwd.digit;
  charArr = passwd.charArr;
 }

 Comb operator = (const Comb &passwd){ //equal operator overload Comb datatype
  if(&passwd == this){
   return *this;
  }
  character = passwd.character;
  number = passwd.number;
  digit = passwd.digit;
  charArr = passwd.charArr;
  return *this;
 }
  
 //Method: Set comb of passwords
 void setPasswd(const char &c, int n, int d, vector<char> &ca){
  character = c;
  number = n;
  digit = d;
  charArr = ca;
 }

 char getChar(){
  return character;
 }

 int getNum(){
  return number;
 }
};

std::ostream& operator << (std::ostream& output,Comb comb){ //overload extraction operator(it must be decleared before int main() )
    output << comb.getChar() << comb.getNum() << " ";
    return output;
}


Comb& Comb::operator [] (vector<Comb> a){
   for(auto i = a.begin(); i != a.end(); i++){
     return a[i];
    }
}

int main(){
   ofstream o;
   o.open("password.txt");
   vector<Comb> array;  
   vector<char> charArray;

   for(char i = 'a'; i <= 'z'; i++){
    for(char j = i+1; j <= 'z'; j++){
    array.push_back(Comb(i, j, 4, charArray)); 
   }     
  }

  for(auto i = array.begin(); i != array.end(); i++){
   for(auto j = i + 1; j != array.end(); j++){
     charArray.push_back(array[i]);
     
    }
  }
  /*
  for(auto i = array.begin(); i != array.end(); i++){
   for(auto j = i + 1; j != array.end(); j++){
	cout << array[i][j] << endl;
      }
    }
   */
  //o.close();
 
 return 0;
}
