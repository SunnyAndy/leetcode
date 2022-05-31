#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<bits/stdc++.h> 
#include<numeric>
using namespace std; 
class Solution  // golden 
{
  public:
    void dfs (   vector < int >  arr   , int index  ,   vector <int> &cur ,  vector < vector <int> > &res  ){
      res.push_back(cur);
      for (int i = index ; i <arr.size() ; ++i){
	cur.push_back(arr[i]);                 // select 
	dfs( arr, i+1 ,   cur , res   );       //  move on to the next  item 
	cur.pop_back();                        //   not select and i+=1 movimg on the next  
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector < vector<int>  >  res;
      if (nums.size()==1){
	res.push_back(nums);
	res.push_back({});
	return res;
      }
      vector <int> cur;
      dfs (    nums , 0,   cur, res  );
#ifdef DEBUG
      for(int i=0 ; i < res.size(); ++i){
	for (int j =0 ;  j <res[i].size(); ++j){
	  cout<<res[i][j]<<",";
	}
	cout<<endl;
      }
#endif
      return res;
    }
};

class Solution_old  // slowly method  we  use  navie method to remove the duplicat  the above   have the  better solution 
{
  public:
    void dfs (   vector < int >  arr   , int index  ,   vector <int> &cur ,  vector < vector <int> > &res  ){
      if (index==arr.size()){
	res.push_back(cur);
	return;
      }
      if (index <arr.size()){
	cur.push_back(arr[index]);
	dfs( arr, index+1 ,  cur, res   );
	cur.pop_back();
	dfs( arr, index +1 , cur, res  );
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector < vector<int>  >  res;
      if (nums.size()==1){
	res.push_back(nums);
	res.push_back({});
	return res;
      }
      vector <int> cur;
      dfs (    nums , 0, cur, res  );
#ifdef DEBUG
      for(int i=0 ; i < res.size(); ++i){
	for (int j =0 ;  j <res[i].size(); ++j){
	  cout<<res[i][j]<<",";
	}
	cout<<endl;
      }

#endif
      return res;
    }
};

int main (){
  class Solution sol;
  vector <int> input ={ 1 ,2,3};
  sol.subsets( input);
  return 0;
}
