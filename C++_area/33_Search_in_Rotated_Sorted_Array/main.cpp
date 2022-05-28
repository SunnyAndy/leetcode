#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:

    int binary_search(   int start , int end  ,  vector <int>  &nums      )  {
      int middle=(start+end)/2;
      // for the corner case that is the arr is sorted without rotate  
      if( ( ( end==start+1 ) and  (nums[end] > nums[start] )    )  or ( start ==  nums.size()-1 ) ){
	return 0;
      }
      if ( nums[middle] > nums[middle+1]){
	return middle+1;
      }
      if (nums[middle] > nums[start]    ){
	int start1 = middle+1;
	int end1=end;
	return binary_search( start1 , end1  , nums);
      }else{
	int start1=start;
	int end1=middle; 
	return binary_search(  start1,  end1 , nums );
      }
    }
    int val_search ( int start, int end , int target , vector <int> &nums){
      int middle=(start+end)/2;
      if(  ( end==start+1 ) ){
	if ( (nums[end] !=target) and  (nums[start] !=target  ) ) {
	  return -1;  //not hit
	}
      }
      if ( (start == end) and ( nums[start]!=target ) ){
	return -1;  // not hit
      }
      if (nums[middle]==target){
	cout<<"hit"<<endl;
	return middle;
      }
      if(nums[middle+1]==target){
	return middle+1;
      }
      if (nums[middle] <  target    ){
	int start1 = middle;
	int end1=end;
	return val_search( start1 , end1 , target , nums);
      }else{
	int start1=start;
	int end1=middle;
	return val_search(  start1,  end1 ,target , nums );
      }
    }
    int search(vector<int>& nums, int target) {


      int pivot;
      int start=0; 
      int end= nums.size()-1;

      if (nums.size() <=3){
	for(int i=0 ; i < nums.size(); i++){
	  if (nums[i]==target){
	    return i;
	  }
	}
	return -1;
      }



      pivot= binary_search(  start , end , nums   );
      cout<<pivot<<endl;
      int res;

      if (pivot==0){  // sorted 
	res = val_search ( start,  end ,target ,nums);
      }else if (target >=  nums[0] and target <= nums[pivot-1]  ){
	start=0;
	end=pivot-1;
	res = val_search ( start,  end ,target ,nums);
      }else if( target >=nums[pivot]  and target <= nums[end]  ){
	start=pivot;
	end=end;
	res = val_search ( start,  end ,target ,nums);
      }else {
	res=-1;
      }

      //if pivot ==0  sorted      
      cout<<"res "<<res<<endl;
      return res;
    }
};

int main (){

  class Solution sol;
  vector<int> input;
  input.push_back(0);
  input.push_back(1);
  input.push_back(2);
  input.push_back(3);
  input.push_back(4);
  input.push_back(5);
  input.push_back(6);
  input.push_back(7);

  sol.search(input   , 9  );


  for(int i=0 ; i < input.size(); i ++ ){
    cout<<"index "<<i<<" value "<<input[i]<<endl;;


  }

  return 0;

}






