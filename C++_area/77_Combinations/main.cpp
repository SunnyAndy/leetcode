#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {
  public:
    void  dfs (  vector <int> &candi, int  select_size ,  int  index   , vector <int> &cur   ,  vector <vector <int> > &res  ){

      if (cur.size() == select_size){
	res.push_back(cur);
	return ;
      }

      for(int i=index  ;  i < candi.size()  ; i++){

	cur.push_back( candi[i]    );
	dfs(candi,   select_size  , i+1 , cur, res  );
	cur.pop_back();
      }

    }

    vector<vector<int>> combine(int n, int k) {


      vector <int> candi;
      for (int i=1; i <= n ; i++){
	candi.push_back(i);
      }

      vector <int>  cur;
      vector <vector <int> > res;
      cur.clear();
      res.clear();
      int total=0;
      int index=0;
      dfs(candi  ,  k   ,  0   , cur   , res   );
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
//  vector <int> input={2,3,5};
  sol.combine(  5 , 3 ) ;
  return 0;
}
