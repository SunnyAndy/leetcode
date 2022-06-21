#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include <bits/stdc++.h>
using namespace std;

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool valid_check(  bool graph[101][101]   , vector < vector < int > > node_color   , int n ,int node   ){
  for (int  i=0 ; i < n ; i ++){
    if(graph[node][i]==1 ){
      if ((node_color[i][1]!=-1) and (node_color[i][1] == node_color[node][1] ) ){
       return false ;  /// the adjcent  node  has the same  color 
      }
    } 
  }
/*
  for (int  i=0 ; i < n ; i ++){
    if(graph[i][node]==1 ){
      if ((node_color[i][1]!=-1) and (node_color[i][1] == node_color[node][1] ) ){
       return false ;  /// the adjcent  node  has the same  color 
      }
    } 
  } */
  return true;
}


void helper ( vector <vector <int>> node_color ){
  for (int i =0  ; i <node_color.size() ; i ++){
    cout<<"node is "<<i << " color  is "<< node_color[i][1]<<endl;
  }
}

bool coloring_procedure (  bool graph[101][101] ,  vector<vector<int>> & node_color   ,  int m, int n  , int  node_index     ){
//  cout<<"node index is "<<node_index<<endl;
//  helper( node_color ) ;
  if(node_index==n){
	return   true;
  }
//    if (node_color[node_index][1] == -1 ){  // the node is not  colorized 
      for(int  color = 0 ; color  < m ; color ++ ) {
	node_color[node_index][1]=color;
        if (valid_check ( graph, node_color ,n , node_index) ){
	  if ( coloring_procedure(graph ,  node_color , m , n , node_index+1 )) return true;
	}

	node_color[node_index][1]=-1;
      }
   // }
    return false;
}



bool graphColoring(bool graph[101][101], int m, int n) {    // n  : number of node , m : number of color  , graph : the edge for nodes , 

  vector <vector<int>> node_color;
  // initialization the node's color

  vector <int> test_node;
  for (int i=0 ; i < n ; i++ ){
    test_node.clear();
    test_node.push_back(i);
    test_node.push_back(-1);  // -1 means not colorizing 
    node_color.push_back(test_node);
  }
#ifdef DEBUG1

  for(int i=0 ; i < n ; i++ ){
    cout<<"Node "<<node_color[i][0]<<" color is "<<node_color[i][1]<<endl;
  }
  for (int i=0 ; i < 101 ; i++){
    for (int j=0 ; j < 101 ; j++){
      cout<<graph[i][j]<<endl;
    }
  }

  return true;
#endif
  if (coloring_procedure(   graph  , node_color , m, n , 0   )){
    return true;
  }else{
    return false;
  }
  // your code here
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++) {
      memset(graph[i], 0, sizeof(graph[i]));
    }
  
    for (i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      graph[a - 1][b - 1] = 1;
      graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
  }
  return 0;
}
// } Driver Code Ends



