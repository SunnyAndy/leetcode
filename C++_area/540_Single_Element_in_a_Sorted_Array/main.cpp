#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1){
	return nums[0];
      }
      if(nums[nums.size()-1] != nums[nums.size()-2]){
	return nums[nums.size()-1];
      }
      if(nums[0]!=nums[1]){
	return nums[0];
      }
      int head=0;
      int tail = nums.size()-2;
      int mid= (head+tail)/2;
      int  index=-1;
      while(  tail>head  ){
	cout<<"mid is "<<mid<<":"<<nums[mid]<<endl;
	cout<<"tail "<<tail;
	cout<<"head "<<head<<endl;
	if ( nums[mid +1] == nums[mid]){
	  index=mid ;
	}
	else if (  nums[mid-1] == nums[mid]){
	  index=mid-1;
	}else{
	  return nums[mid];
	}	
	if (index %2==1 ) {
	  tail=mid;
	}else{
	  head=mid;
	}
	mid=(head+tail)/2;
      }

      return head;
#ifdef DEBUG
      cout<<"testing"<<endl;
#endif
      return  0;   
    }
};

int main (){
  class Solution sol;
  vector <int> input={  1 ,2,2 , 3,  3};
  //    vector <int> input={1,1,2,2,3,4,4,5,5,6,6,7,7};
  cout<<sol.singleNonDuplicate( input)<<endl ;
  return 0;
}
