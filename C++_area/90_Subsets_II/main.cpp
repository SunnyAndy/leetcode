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
	if (i > index && arr[i] == arr[i - 1]) // here the  duplicate is heare 
	  continue;
	cur.push_back(arr[i]);                 // select 
	dfs( arr, i+1 ,   cur , res   );       //  move on to the next  item 
	cur.pop_back();                        //   not select and i+=1 movimg on the next  
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector < vector<int>  >  res;
      if (nums.size()==1){
	res.push_back(nums);
	res.push_back({});
	return res;
      }
      vector <int> cur;
      sort (  nums.begin(), nums.end()); // we sort first  and we can use nums[i] == nums[i-1] that is duplicate 
      dfs (    nums , 0,   cur, res  );
/*
      vector <vector <int >> resb;
      sort( res.begin(), res.end()  );

      for(int i=0 ; i < res.size(); i++){
	if(i!=0 and res[i]==res[i-1]){
	  continue;
	}else{
	  resb.push_back(res[i]);
	}
      }
      resb.swap(res);
      */
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
	vector <int> temp;
	temp=cur;
	sort(temp.begin(), temp.end());
	res.push_back(temp);
	return;
      }
      if (index <arr.size()){
	cur.push_back(arr[index]);
	dfs( arr, index+1 ,  cur, res   );
	cur.pop_back();
	dfs( arr, index +1 , cur, res  );
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector < vector<int>  >  res;
      if (nums.size()==1){
	res.push_back(nums);
	res.push_back({});
	return res;
      }
      vector <int> cur;
//      sort(nums.begin() , nums.end());
      dfs (    nums , 0, cur, res  );

      vector <vector <int >> resb;
      sort( res.begin(), res.end()  );


      for(int i=0 ; i < res.size(); i++){
	if(i!=0 and res[i]==res[i-1]){
	  continue;
	}else{
	  resb.push_back(res[i]);
	}
      }
      resb.swap(res);

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
  vector <int> input ={ 4,4,4,1,4};
  sol.subsetsWithDup( input);
  return 0;
}
