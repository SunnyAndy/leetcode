// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
	queue < pair <  pair <int , int > , int >> myq;
	int row=grid.size();
	int col=grid[0].size();
	//int vis[row][col]={0};

	int **vis = new int*[row];
	for (int i=0; i <row; i++){
	  vis[i] = new int [col];
	}
	
	for (int i=0  ;  i < row; i++){
	    for (int j=0 ; j < col; ++j){
	    vis[i][j]=0;
	    }
	}
	// initialization 
	for (int i=0 ; i < row; i++){
	  for (int j=0 ; j < col ; j++){
		vis[i][j]=grid[i][j];
	      if (grid[i][j]==2){
		myq.push({{i,j} ,0 });
	      }
//	      cout<<vis[i][j]<<" ";
	  }
//	  cout<<endl;
	}
	// BFS here ////
        int x[4] = {1,0,-1,0};
	int y[4] = {0,1,0,-1};
	pair<int, int> iter;
	int iter_x;
	int iter_y;
	int time_to_rottom=0;
	while(!myq.empty()){
	  iter =myq.front().first;
          time_to_rottom= myq.front().second;
	  myq.pop();
//	  cout<<"iter.first "<<iter.first<<" iter.second "<<iter.second<<endl;
	  for (int i=0  ; i< 4 ; i++){
	    iter_x=iter.first+x[i];
	    iter_y=iter.second+y[i];
	    
	  //    cout<<"iter x "<<iter_x<<" iter y " <<iter_y<<endl;
	    if ( iter_x >= 0  && iter_y>=0 && iter_x <row  && iter_y<col  && vis[iter_x][iter_y] ==1   ){
//	      cout<<"iter x "<<iter_x<<" iter y " <<iter_y<<endl;
	      myq.push( {{iter_x,iter_y} , time_to_rottom+1 } );
	      vis[iter_x][iter_y]=2;
	    }
	    
	  }


	}

//	cout<<" time_to_rotton is "<<time_to_rottom<<endl;

	for (int i=0  ;  i < row; i++){
	    for (int j=0 ; j < col; ++j){
	//    cout<<vis[i][j]<<" ";
	     if (vis[i][j]==1 ){return -1 ; }
	    }
//	    cout<<endl;
	}

	return time_to_rottom;        
    }
}; 
    



int main() {

  class  Solution  answer;

//  vector <vector <int> > grid {{2,1,1},{1,1,0},{0,1,1}};

  vector <vector <int> > grid {{2,1,1},{0,1,1},{1,0,1}};

  answer.orangesRotting(grid);


  return 0;
}  

