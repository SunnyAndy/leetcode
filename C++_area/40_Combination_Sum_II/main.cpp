#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {

  private:
    void  dfs (  vector <int> &candidates, int  target ,  int  index   , vector <int> &cur , int  total  ,  vector <vector <int> > &res  ){
      if (total == target){
	res.push_back(cur);
	return ;
      }
      if( total >target  ){
	return;
      }
      for(int i=  index  ;  i < candidates.size()  ; i++){
	if(i!=index and candidates[i]==candidates[i-1]) continue;
	cur.push_back( candidates[i]    );
	dfs(candidates, target , i+1 , cur,  total+candidates[i]  ,res  );
	cur.pop_back();
      }
    }



  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector <int>  cur;
      vector <vector <int> > res;
      cur.clear();
      res.clear();
      int total=0;
      int index=0;

      sort(candidates.begin(),  candidates.end());

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
  vector <int> input={10,1,2,7,6,1,5};
  sol.combinationSum2( input,  8) ;



  return 0;
}


