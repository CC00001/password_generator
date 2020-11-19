#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
using namespace std;

vector<string> make_permutations(int length, int num){
  if (length == 0) {
    return vector<string>{};
  }
    
  vector<string> results;
  vector<string> children = make_permutations(length - 1, num);
  vector<int> numbers;
  stringstream ss;
  
  for (char letter = 'a'; letter <= 'z'; letter++) { 
    results.emplace_back(1, letter); //emplace_back() moves forward values with less time consumption
    for(auto child : children) {
      results.push_back(std::string(1, letter) + child); //push_back() copys values with time consumption, but safer
    }
  }
  
  for(int i = 0; i < num; i++){ //Integer implentation
   numbers.emplace_back(i);
   swap(numbers[i], numbers[i+1]);
   make_permutations(length - 1, num);
   swap(numbers[i], numbers[i+1]);
   //for(int j = i + 1; j < num; j++){
     //numbers.push_back(j);    
   //}
  } 
  for(auto n : numbers){
   ss << numbers[n];
  
   string s_numbers = ss.str();
  
  results.push_back(s_numbers);
  }
  return results;
}

int main()
{
 ofstream output;
  output.open("wordlist.lst");
 auto results = make_permutations(5, 4);
    for(auto s : results){ 
      cout << s << endl;
      output << s << "\n";
    }
    output.close();
 return 0;
}
