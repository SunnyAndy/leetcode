#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {
  public:
    void  dfs (  vector <int> &candidates, int  target ,  int  index   , vector <int> &cur , int  total  ,  vector <vector <int> > &res  ){

      if(index >= candidates.size()){
	return ;
      }

#ifdef DEBUG
      cout<<"index is "<<index<<" , ";
      for(int i=0 ; i <cur.size(); i++){
	cout<<cur[i]<<" ";

      }
      cout <<endl;
#endif

      if (total == target){
	res.push_back(cur);
	return ;
      }
      if( total >target  ){
	return;
      }
      int value=candidates[index];
      cur.push_back( value);
      dfs( candidates, target , index , cur  , total+value  , res );
      cur.pop_back();
      index =index +1;
      dfs( candidates, target  , index , cur  , total , res  );
      return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector <int>  cur;
      vector <vector <int> > res;
      cur.clear();
      res.clear();
      int total=0;
      int index=0;
      std::sort(candidates.begin(), candidates.end());
      dfs(candidates, target  , index  , cur ,  total  , res   );
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
  class Solution sol;
  vector <int> input={2,3,5};
  sol.combinationSum( input,  8 ) ;
  return 0;
}
