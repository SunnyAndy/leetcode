#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {
  public:
    bool check_valid(int row , int col ,int n ,  vector <string> &cur){

//      cout<<"row is "<<row<<" col is "<<col<<endl;
      if (row==0){
	return true;
      }else{
	for ( int r =0 ; r <row ; r++){
//	  cout<<"  first "<<cur[r][col];
	  if(cur[r][col]=='Q'){
	    return false;
	   }
	}
//	cout<<endl;
	for (int i=col ; i >=col-row and i>=0;  i--){
	  cout<<"seconde";
	  cout<<row-(col-i)<<" , "<<i<<endl;
	  if(cur[row-(col-i)][i]=='Q'){
	    return false;
	  }
	}
//	cout<<endl;
	for (int i =col;  i <= col+row  ;  i++){
	  cout<<"third "<<endl;
	  cout<<row-(i-col)<<" , "<<i<<endl;
	  if(cur[row-(i-col)][i]=='Q'){
	    return false;
	  }
	}
//	cout<<endl;
      }
      return true;
    }

    void  dfs (  int row ,  int n , vector <string> &cur   ,  vector <vector <string>> &res   ){

      if ( row  ==n ){
	res.push_back(cur);
	return ;
      }
      for (int i =0 ; i <  n  ; ++i ){
	if (check_valid( row , i ,n  , cur )){
	  cur[row][i]='Q';
	  dfs ( row+1 , n  , cur,  res );
	  cur[row][i]='.';
	}
      }
    }  
    vector<vector<string>> solveNQueens(int n) {

      vector <vector <string> > res;

      vector <string> cur; 

      string a="";
      for (int i=0 ;  i < n ; i++){
	a+=".";

      }
      for (int i=0 ; i < n; i++){
	cur.push_back(a);
	//cout<<cur[i]<<endl;
      }

      dfs ( 0 ,   n ,  cur    ,   res   );


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
  sol.solveNQueens( 4) ;
  return 0;
}
