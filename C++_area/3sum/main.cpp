#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;
//#define  DEBUG   NULL

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int start_vale=0;
      int three_sum;
      int r, l ;
      std::sort(nums.begin() , nums.end());
      vector <int> res_set;
      vector <vector <int >> result;
      for (int i =0 ; i <nums.size(); i++){
	if (i>=1   and nums[i-1]==nums[i] ){
	  continue;
	}
	start_vale=nums[i];
	l=i+1;
	r=nums.size()-1;
	res_set.clear();
	while (r>l){
	  three_sum=nums[l]+nums[r]+start_vale;
	  if (three_sum >0){
	    r-=1;
	  }else if (three_sum <0){
	    l+=1;
	  }else{    //threesum  = 0 ; 
	    res_set.push_back(start_vale);
	    res_set.push_back(nums[l]);
	    res_set.push_back(nums[r]);
	    result.push_back(res_set);
	    l+=1;
	    while (r>l and nums[l]==nums[l-1] ){
	      l+=1;
	    }
	    res_set.clear();
	  }
	}

      }

// debug area 
 
#ifdef DEBUG

      for (int i=0;  i< result.size(); ++i ){
	for (int j = 0 ;   j <result[i].size(); ++j){
	  cout<<" "<<result[i][j]<<" ";
	}
	cout<<endl;
      }


#endif
      return result;
    }
};


int main (){

  //  vector<int> v1 = {-1,0,1,2,-1,-4};
  vector<int> v1 = { -4,-2 ,-2 ,-1,-1,0,1,1,2,-1,-4};
  //  vector<int> v1 = { 0,0,0,0};

  class Solution mysol;


  vector <int> c={1,2,3,4,5};
  vector <vector<int>> result=mysol.threeSum(v1);

  //cout<<result[0][0];  

  return 0;

}

