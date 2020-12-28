#include <iostream>
#include <vector>
#include <fstream>

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

  std::vector<std::vector<char>> convertChar(const std::vector<std::vector<int>> &iArray){
   const size_t size = iArray[0].size(); //get the size of 1st element of outer array
   std::vector<std::vector<char>> results; //create a new 2d vector
   results.reserve(size); //reserve the space for the new 2d vector
   for(auto &fv : iArray){ //iterate outter loop of iArray
    std::vector<char> rawVec; //create a new 1d vecotr
    rawVec.reserve(size); //reserve the space for the new 1d vector
     for(auto &sv : fv){ //iterate inner loop of iArray
      rawVec.emplace_back(static_cast<char>(sv) + '0'); //store elements with type casting to char after add a '0' terminator at the end of every single elments of inner loop
    }
    results.emplace_back(rawVec); //store inner elements to outter loop of the new 2d vector     
   }
   return results;
  }

   std::vector<std::vector<char>> mergeComb(const std::vector<std::vector<char>> &a, const std::vector<std::vector<int>> &b){
   std::vector<std::vector<char>> results;
   std::vector<std::vector<char>> tempA = a;
   std::vector<std::vector<char>> tempB = convertChar(b);
   results.reserve(tempA.size() + tempB.size());
    for(auto &r : {std::cref(tempA), std::cref(tempB)}){
     results.insert(results.end(), r.get().begin(), r.get().end());
    }
    //permutation(results);
     //results.insert(*it.size() - 1, std::make_move_iterator(tempB.begin()), std::make_move_iterator(tempB.end()));
    return results;
   }

template<typename A>
 void printComb(const std::vector<std::vector<A>>& v){
  for(A i = 0; i < v.size(); i++){
   for(A j = 0; j < v[i].size(); j++){
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
   std::vector<std::vector<char>> results;
   for(char c = 'a'; c <= 'd'; c++){
    cArray.push_back(c);
   }
   for(int i = 0; i <= 3; i++){
    newArray.push_back(i);
   }
   secArray = comb.permutation(newArray);
   sCharArray = comb.permutation(cArray);
   //sCharArray = comb.convertChar(secArray);
   //results = comb.mergeComb(sCharArray, secArray);
   comb.printComb(comb.mergeComb(sCharArray, secArray)); 

   o.close();

 return 0;
}
