#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:
     void nextPermutation(vector<int>& nums) {
       if (nums.size() ==1 ){
	 return ;
       }
       int oper=0;
       bool bk=false;
       for (int i=nums.size()-1  ;  i>=0; i--){
	 oper=nums[i];
	 for (int j=nums.size()-1 ; j>i; --j ){
	   if( nums[j] > nums[i]){
		int  temp= nums[j];
		nums[j]=nums[i];
		nums[i]=temp;
		bk=true;

		std::sort(nums.begin()+i+1, nums.end());
		break;
	   }
	 }
	 if (bk){
		break;
	 }
       }
       if (!bk){
	std::sort(nums.begin() , nums.end());
       }


#ifdef DEBUG       
       for (int i=0 ; i < nums.size();  i++){
	 cout<<" "<<nums[i];
       }
       cout<<endl;
#endif



     }
};

int main (){

  class Solution sol;
  vector<int> input;
  input.push_back(1);
  input.push_back(3);
  input.push_back(2);
//  input.push_back(5);
  sol.nextPermutation(input);

  for (int  i=0 ; i < input.size(); ++i){

    cout<<input[i];

  }



#ifdef DEBUG
  cout<<"golden is "<< "2 1 3 "<<endl;
#endif
  //cout<< ( sol.generateParenthesis(2))[0] <<endl;

  return 0;

}






