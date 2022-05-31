#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<bits/stdc++.h> 
#include<numeric>
using namespace std; 

class Solution
{
  public:
    void dfs (   vector < int >  arr   , int index  ,   vector <int> &cur , vector <int> &res  ){
      if (index==arr.size()){
	res.push_back(accumulate(cur.begin(),cur.end(),0));
//	cout<<" index "<<index<<" sum " << res[res.size()-1]<<endl;
	return;
      }
      if (index <arr.size()){
	cur.push_back(arr[index]);
	dfs( arr, index+1 ,  cur, res   );
	cur.pop_back();
	dfs( arr, index +1 , cur, res  );
      }
    }

    vector<int> subsetSums(vector<int> arr, int N)    {
      if (N==1){
	if (arr[0]==0){
	  return arr;
	}else{
	  arr.push_back(0);
	  return arr;
	}
      }
      vector <int> cur;
      vector<int>  res;
      cur.push_back(0);
      dfs (   arr, 0, cur, res  );
      return res;
      // Write Your Code here
    }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i = 0 ; i < N ; i++){
      cin >> arr[i];
    }
    Solution ob;
    vector<int> ans = ob.subsetSums(arr,N);
    sort(ans.begin(),ans.end());
    for(auto sum : ans){
      cout<< sum<<" ";
    }
    cout<<endl;
  }
  return 0;
}  // } Driver Code Ends

