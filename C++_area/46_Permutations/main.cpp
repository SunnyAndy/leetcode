#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution_swap{
  public:
    void swap (   int post1 , int post2   ,  vector <int> &nums )  {
      int temp= nums[post1];
      nums[post1] = nums[post2];
      nums[post2]= temp;
    }


    void  dfs (  vector <int>  &nums ,   int ind     ,  vector <vector <int> > &res  ){

      if ( ind >= nums.size()){
	res.push_back(nums);
      }

      
      for (int i =ind ; i < nums.size() ; ++i ){
	  swap( ind  ,  i  , nums  );    // current  index with the following digits swap 
	  dfs(nums , ind+1  ,  res);
          swap(  ind ,  i  , nums  );    //  swap back  or swap ( i, ind , nums ) both are okey  
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector <vector <int> > res;
      res.clear();
      dfs(  nums     ,  0       , res   );

#ifdef DEBUG
      for (int  i =0 ; i <res.size() ; i ++){
	for (int j=0 ;j <res[i].size(); j++){
	  cout<<" "<<res[i][j]<<" ";
	}
	cout<<endl;
      }
#endif 
      return res;
    }
};


class Solution {
  public:
    void  dfs (  vector <int>  &nums ,  vector <bool> & map  , vector <int> &cur   ,  vector <vector <int> > &res  ){

      if (cur.size() == nums.size()){
	res.push_back(cur);
	return ;
      }

      for (int i =0 ; i < nums.size() ; ++i ){
	if(map[i]){
	  cur.push_back( nums[i]);
	  map[i]=false;
	  dfs( nums , map , cur, res  );
	  cur.pop_back();
	  map[i]=true;
	}
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector <int>  cur;
      vector <vector <int> > res;
      vector <bool> map;
      for (int i=0 ; i <nums.size();  ++i){
	map.push_back(true);
      }
      cur.clear();
      res.clear();
      dfs(  nums     ,  map   , cur   , res   );
#ifdef DEBUG
      for (int  i =0 ; i <res.size() ; i ++){
	for (int j=0 ;j <res[i].size(); j++){
	  cout<<" "<<res[i][j]<<" ";
	}
	cout<<endl;
      }
#endif 
      return res;
    }
};


int main (){
  class Solution_swap sol;
  vector <int> input={1,2,3};
  sol.permute(   input ) ;
  return 0;
}
