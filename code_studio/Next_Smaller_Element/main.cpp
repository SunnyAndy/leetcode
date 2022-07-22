// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    vector<int> nextSmallerElement(vector<int>& arr,  int n  ) {

      /////////////////////////////////
      vector <int > res;
      if (n==2){
	if (arr[1]>=arr[0]){
	  res.push_back(-1);
	}else {
	  res.push_back(arr[1]);
	}  
	res.push_back(-1);
	return res; 
      }
      stack <int> st;
      std::unordered_map<int, int>  under_map;
      for (int i=0  ; i < arr.size();  i ++   ){
	while ( !st.empty() && arr[st.top()] > arr[i]  ){
	  under_map[st.top()]=arr[i];
	  st.pop();
	}
	st.push(i);
      }
      while(!st.empty()){
	under_map[st.top()]=-1;
	st.pop();
      }
      for (int i=0 ; i <arr.size() ; i ++){
	res.push_back(under_map[i]);
      }
#ifdef DEBUG
      for(int i=0; i <res.size(); i++ ){

	cout<<res[i]<<" ";
      }
#endif

      return res;
      //////////////////////////////////////////////////////
    }

};

int main() {
  class Solution mysolution;

  vector <int> target= {3, 2 ,1 ,1 ,2, 3};

  mysolution.nextSmallerElement( target,  target.size() );

  return 0;

}  




