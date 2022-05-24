#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;
//#define  DEBUG   NULL

class Solution {
  public:
      int threeSumClosest(vector<int>& nums, int target) {
      int start_vale=0;
      int three_sum;
      int r, l ;
      int min_distance=1000000;
      int result_a=0;
      std::sort(nums.begin() , nums.end());
      for (int i =0 ; i <nums.size(); i++){
	start_vale=nums[i];
	l=i+1;
	r=nums.size()-1;
	while (r>l){
	  three_sum=nums[l]+nums[r]+start_vale;
	  //update the min_distance 
	  if (three_sum  - target  >0){
	    r-=1;
	  }else if (three_sum - target <0){
	    l+=1;
	  }else{    //threesum  = 0 ; 
	    return three_sum;
	  }
	  if ( abs( three_sum -target )  < min_distance ){
	    min_distance=abs(three_sum- target);
	    result_a=three_sum;
	  }

	}

      }
      return result_a;
      }
};


int main (){

  vector<int> v1 = {-1,2,1,-4};

  class Solution mysol;
  int target =1;
  int result=mysol.threeSumClosest( v1   , target);

  cout<<result;

  return 0;

}

