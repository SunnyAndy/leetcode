// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    vector<int> nextGreaterElement(vector<int>& find, vector<int>& target ) {
      vector <int > res;
      stack <int> st; 
      std::unordered_map<int, int>  under_map;
      for (int i=0  ; i < target.size();  i ++   ){
	while ( !st.empty() && st.top() < target[i]  ){
	  under_map[st.top()]=target[i];
	  st.pop();
	}
	st.push(target[i]);
      }
      for (int i=0 ; i <find.size() ; i ++){
	if (under_map[find[i]]!=0){
	  res.push_back(under_map[find[i]]);
	}else{
	  res.push_back(-1);
	}
      }
#ifdef DEBUG
      for(int i=0; i <res.size(); i++ ){

	cout<<res[i]<<endl;
      }
#endif
     return res; 
    }

};

int main() {
  class Solution mysolution;

  vector <int> find  = {4,1,2};
  vector <int> target= {1,3,4,5,2,6};

  mysolution.nextGreaterElement(find , target);

  return 0;

}  




