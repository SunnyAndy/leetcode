#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:

    int val_search_left ( int start, int end , int target , vector <int> &nums){
      int middle=(start+end)/2;
      if(start==0 and nums[start]==target){
	return start;
      }
      if(( end==start+1 ) ){
	if ( (nums[end] !=target) and  (nums[start] !=target  ) ) {
	  return -1;  //not hit
	}
	if ((nums[end]==target) and (nums[start] !=target)){
	  return end;
	}
	if ((nums[end]==target) and (nums[start] ==target)){
	  return start;
	}
      }
      if ( (start == end)  ){
	if ( nums[start]!=target ) {
	  return -1;  // not hit
	}
	if (nums[start]==target){
	  return start;
	}
      }
      if (nums[middle]>target){
	return  val_search_left(start, middle-1 ,  target, nums  );
      }
      if (nums[middle]==target){
	return  val_search_left(start, middle ,  target, nums  );
      }
      if(nums[middle] <target){
	return val_search_left(middle  ,  end , target ,  nums);
      }
      return -2;
    }

    int val_search_right ( int start, int end , int target , vector <int> &nums){
      int middle=(start+end)/2;
      if ( (end == nums.size()-1) and (nums[end]==target) ){
	return  end;
      }

      if(  ( end==start+1 ) ){
	if ( (nums[end] !=target) and  (nums[start] !=target  ) ) {
	  return -1;  //not hit
	}
	if(( nums[end]!=target  ) and ( nums[start] ==target  ) ){
	  return start;
	}
	if(( nums[end] == target  ) and ( nums[start] ==target  ) ){
	  return end;
	}
      }

      if ( (start == end) ){
	if (( nums[start]!=target ) ){
	  return -1;  // not hit
	}
	if ((nums[start]==target)){
	  return start;
	}
      }
      if (nums[middle]>target){
	return  val_search_right( start , middle  ,  target, nums  );
      }

      if(nums[middle] <target){
	return val_search_right(middle+1,end , target ,  nums);
      }

      if(nums[middle] ==target){
	return val_search_right(middle,end , target ,  nums);
      }
      return -3;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      int start=0; 
      int end= nums.size()-1;
      vector <int> result;
      // the following is for the small cases ;
      int left=1000000;
      int right =-1;
      if (nums.size() <=10 ){
	for(int i=0 ; i < nums.size(); i++){
	  if (nums[i]==target   and  i <left ){
	    left=i;
	  }
	  if (nums[i]==target and  i>right){
	    right=i;
	  }
	}
	if (left ==1000000){
	  left=-1;
	}
	result.push_back(left);
	result.push_back(right);
	return result;
      }

      // end of the small cases ;


      result.clear();
      // step one looking for the left point 
      left= val_search_left( start, end , target , nums );
      result.push_back(left);
      cout<<"left is "<<left<<endl;


      right = val_search_right(start , end, target  , nums);
      cout<<"right is "<< right<<endl;

      result.push_back(right);
      return result;
      //if pivot ==0  sorted      
    }
};

int main (){


  class Solution sol;
  vector<int> input;
  input.push_back(0);
  input.push_back(1);
  input.push_back(1);
  input.push_back(2);
  input.push_back(2);
  input.push_back(3);
  input.push_back(3);
  input.push_back(4);
  input.push_back(4);
  input.push_back(5);
  input.push_back(5);
  input.push_back(5);
  input.push_back(6);
  input.push_back(6);
  input.push_back(6);
  input.push_back(6);
  input.push_back(7);
  input.push_back(7);

  sol.searchRange(input, 7);



  for(int i=0 ; i < input.size(); i ++ ){
    cout<<"index "<<i<<" value "<<input[i]<<endl;;


  }

  return 0;

}






