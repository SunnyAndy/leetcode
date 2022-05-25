#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;
//#define  DEBUG   NULL
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums  , int target    ) {
      std::sort(nums.begin() , nums.end());
      long long  all_sum;
      int start_vale=0;
      int r, l ;
      int s_val;
      vector <int> res_set;
      vector <vector <int >> result;
      for (int s =0 ; s< nums.size(); s++){
	s_val=nums[s];
	if(s>=1 and nums[s-1]==nums[s]){
	  continue;
	}
	for (int i =s+1 ; i <nums.size(); i++){
	  if (i-s>1   and nums[i-1]==nums[i] ){
	    continue;
	  }
	  start_vale=nums[i];
	  l=i+1;
	  r=nums.size()-1;
	  res_set.clear();
	  while (r>l){
	    all_sum=nums[s];
	    all_sum+=nums[l];
	    all_sum+=nums[r];
	    all_sum+=start_vale;
	    if (all_sum >target){
	      r-=1;
	    }else if (all_sum <target){
	      l+=1;
	    }else{    //threesum  = 0 ; 
	      res_set.push_back(nums[s] );
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
//  vector<int> v1 = { -4,-2 ,-2 ,-1,-1,0,1,1,2,4};
    vector<int> v1 = { 2,2,2,2,2};

  class Solution mysol;


  vector <int> c={1,2,3,4,5};
  vector <vector<int>> result=mysol.fourSum(v1 , 8 );

  //cout<<result[0][0];  

  return 0;

}

