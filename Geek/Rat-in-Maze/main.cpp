// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:

    bool boundary_check(int check_x , int check_y   , int n   ){
      if (check_x >=n  or  check_x < 0  or check_y >=n or  check_y <0 ){
	return false;
      }
      return true;
    }

    bool visited_check(int check_x , int check_y   ,  vector <vector <int > >  &path){
      for (int i =0 ;  i < path.size()  ; i++){
	if (check_x==path[i][0] and check_y==path[i][1]){
	  return false;
	}
      }
      return true;
    }


    void dfs_search(  vector <string> &result ,string & cur_string  ,  vector <vector< int >> &m , int n , vector < vector <int > > &path   , int current_x , int current_y  , vector <vector <int> > &move){

      cout<<"current string "<<cur_string<<endl;
      if ( current_x == n-1 and current_y==n-1    ){
	result.push_back(cur_string);
	return ;
      }
      for (int i =0 ; i <  move.size() ; i ++ ) {
	cout <<"i is "<<i<<" " <<  (current_x  + move[i][1] ) << " " <<   ( current_y +move[i][2]) <<endl;
	if (boundary_check( current_x+move[i][1] , current_y+move[i][2] , n)){
	  if(visited_check( current_x+move[i][1], current_y+move[i][2]  , path )){
	    cout <<  (m[current_x + move[i][1]][ current_y + move[i][2]] !=0) <<endl;
	    if(m[current_y + move[i][2]][current_x + move[i][1]] !=0){
	      vector <int > temp{ current_x + move[i][1] , current_y+move[i][2]   };
	      path.push_back(temp);
	      cur_string += char(move[i][0]);
	      dfs_search(result , cur_string ,  m , n , path ,  current_x+move[i][1] , current_y+move[i][2], move);
	      path.pop_back();
	      cur_string.pop_back();
	    }
	  }
	}
      }
      return;
    }


    vector<string> findPath(vector<vector<int>> &m, int n) {
      // Your code goes here
/*
      for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cout<<  m[i][j];  //  m [y aix] [x aix ]
	  cout<<" x + 1 "<< m[i+1][j]<<" ";
	}
	cout<<endl;
      } 

      vector <string>  result2;
      result2.push_back("123");
      return result2;
*/
      vector <vector <int >> move;
      vector <int> U{85 ,  0, -1};
      vector <int> R{82 ,  1, 0};
      vector <int> D{68 ,  0, 1};
      vector <int> L{76 ,  -1, 0};
      move.push_back(U);
      move.push_back(R);
      move.push_back(D);
      move.push_back(L);
      string cur_string="";
      //mystring += char(move[0][0]);
      //cout<<(move[0][1])<<" "<<move[0][2] ; //<<" "<<char(move[2][0])<<" "<<char(move[3][0])<<endl;
      //cout<<char(move[0][0])<<" "<<char(move[1][0])<<" "<<char(move[2][0])<<" "<<char(move[3][0])<<endl;
      vector <int > start ={0,0};
      vector <vector < int> >  path; 
      path.push_back(start);
      vector <string>  result;

      if (m[0][0]==0){
	return result;
      }
      dfs_search(result , cur_string ,  m , n , path ,   0  , 0 , move);
      return result;
    }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int> (n,0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	cin >> m[i][j];
      }
    }


    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}  // } Driver Code Ends




