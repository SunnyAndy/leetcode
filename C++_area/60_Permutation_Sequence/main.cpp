#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class Solution {
  private:
    int toFactorial(int n) {
      if(n == 1 || n==0) // 終止狀態
	return 1;
      else
	return n * toFactorial(n - 1); // 歸納項
    }

    void  dfs (   vector <int>  digits  ,  int   k  ,    string  &res ){
        if (digits.size()==0){
		return;
	}
 	int d = toFactorial( digits.size()-1   );
	int n= k/d;
	int r= k%d;
	sort(digits.begin(), digits.end());
	res += char(digits[n]+48);
	digits.erase(digits.begin()+n);
	dfs( digits ,  r,  res);
    }

  public:
    string getPermutation(int n, int k) {

      string res;
      vector <int> to_digits;
      for ( int i=1; i<=n ; i++){
	to_digits.push_back(i);
      }
      sort(to_digits.begin() , to_digits.end());
      
//     special case  express way 
      if(k==1){
	for(int  i =0 ;  i < to_digits.size() ; i++){
	  res += char(to_digits[i]+48);
	}
	return res;
      }else if (k==toFactorial(n) ){
	for(int i=(to_digits.size() -1) ; i >=0 ; i--){
	  res += char(to_digits[i]+48);
	}
	return res;
      }
//    end of express way 
      dfs (to_digits  ,   k-1  ,     res );  // k is  zero based 
#ifdef DEBUG
      cout<<res<<endl;
#endif 
      return res ;
    }
};

int main (){
  class Solution sol;
  cout<<  sol.getPermutation(4,9)<<endl;
  return 0;
}


