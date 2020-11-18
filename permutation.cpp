#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
using namespace std;

vector<string> make_permutations(int length, int num) {
  if (length == 0) {
    return vector<string>{};
  }
  vector<string> results;
  vector<string> children = make_permutations(length - 1, num);
  vector<int> numbers;
  stringstream s_numbers;
  
  for (char letter = 'a'; letter <= 'z'; letter++) { 
    results.emplace_back(1, letter);
    for(auto child : children) {
      results.push_back(std::string(1, letter) + child);
    }
  }
  
  for(int i = 0; 0 <= num; i++){
   numbers.push_back(i);
  }
  copy(numbers.begin(), numbers.end(), ostream_iterator<int>(s_numbers, ""));
  return results;
}

int main()
{
 auto results = make_permutations(2, 3);
    for(auto s : results) cout << s << endl;
}
