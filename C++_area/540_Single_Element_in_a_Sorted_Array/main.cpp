#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1){  //  corner case only one element in  input
	return nums[0];
      }
      if(nums[nums.size()-1] != nums[nums.size()-2]){  // corner case the single element is in the last elemetn ex [1 1 2 2 3]
	return nums[nums.size()-1];
      }
      if(nums[0]!=nums[1]){   //  corner case the sinlge element is in the first  ex  [1 2 2 ] 
	return nums[0];
      }
      int head=0;
      int tail = nums.size()-2;
      int mid= (head+tail)/2;
      int  index=-1;
      while(  tail>head  ){
	if ( nums[mid +1] == nums[mid]){   //  say  [1 1 2 2 3(mid ) 3 4 4 5 6 6   ]  if mid +1   == mid , index is assign to be mid
	  index=mid ;
	}
	else if (  nums[mid-1] == nums[mid]){ // say [1 1 2 2 3 3(mid)  4 4 5 6 6  ] if the mid  -1 == mid index is assgin to mid-1
	  index=mid-1;
	}else{
	  return nums[mid];    // say [1 1 2 2 3(mid) 4 4 5 5 ]  hit
	}	
	if (index %2==1 ) {
	  tail=mid ;           // tail are always  to be old 
	}else{
	  head=mid;            // head are always to be even 
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
