#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>

//template<typename A, typename L>
//vector<A> make_permutation(const vector<A> array, L len){
// if(len == 0) return array;
// vector<A> results = make_permutation(array, len - 1);
// vector<A> temp;
// for(L i = 0; i <= array.size(); i++){
//  temp.push_back(i);
// 
// for(auto r : results){
//  results.push_back(i + r);	  
//  }
// }
// return results;
//}
//
class Comb{
private:
 std::vector<char> charArray;
 std::vector<int> array;
 int* number;
 int lengthChar, lengthNum;

public:
template<typename A>
  std::vector<std::vector<A>> permutation(const std::vector<A>& nums){
  std::vector<std::vector<A>> results;
  std::vector<A> temp(nums.size());
  std::vector<bool> used(nums.size(), false);
  dfs(0, nums, results, temp, used);
  return results;
 }

 //cur_pos is the index to temp
template<typename A>
 void dfs(int cur_pos, const std::vector<A>& nums, std::vector<std::vector<A>>& res, std::vector<A>& temp, std::vector<bool>& used){
  if(cur_pos == nums.size()){
   res.push_back(temp);
   return;
  }
  //enmerate possible numbers for current position
   for(int i = 0; i < nums.size(); i++){
    if(!used[i]){
     used[i] = true;
     temp[cur_pos] = nums[i];
     dfs(cur_pos + 1, nums, res, temp, used);
     //restore for used, no need to restore path becuase it will be overwritten in the next iteration
     used[i] = false;
    }
   }
 }

  std::vector<int> getArray(){
   return array;
  }

  void insertArray(int n){
   return array.push_back(n);
  }
template<typename A>
 void printComb(const std::vector<std::vector<A>>& v){
  for(int i = 0; i < v.size(); i++){
   for(int j = 0; j < v[i].size(); j++){
   std::cout << v[i][j];
   }
  std::cout << std::endl;
  }
 }
};

/*std::ostream& operator << (std::ostream& output,Comb comb){ //overload extraction operator(it must be decleared before int main() )
    output << comb.getChar() << comb.getNum() << " ";
    return output;
}
*/

int main(){
   std::ofstream o;
   o.open("password.txt");
   Comb comb;
   std::vector<char> cArray;
   std::vector<int> newArray;
   std::vector<std::vector<int>> secArray;
   std::vector<std::vector<char>> sCharArray;
   for(char c = 'a'; c <= 'd'; c++){
    cArray.push_back(c);
   }
   for(int i = 0; i <= 3; i++){
    newArray.push_back(i);
   }
   sCharArray = comb.permutation(cArray);
   secArray = comb.permutation(newArray);
   comb.printComb(sCharArray);
   comb.printComb(secArray); 

   o.close();

 return 0;
}
