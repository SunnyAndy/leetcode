// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{ // brute force 
  public:
    vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
      // Write your code here.
      vector <int> result;
      priority_queue<int>pq;
      for (int i =0 ; i <  n ; i++){
	for(int j=0 ; j < n; j++){
	  pq.push(a[i]+b[j]);  
	}
      }

      for (int i=0 ; i < k ; i++){   
	result.push_back(pq.top());
	pq.pop();
      }
      for (int  i=0 ; i < result.size(); i++){
	cout<<result[i]<<" ";
      }
      return result;

    }
};

int main() {
  class Solution mysolution;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int>  arr1;
    vector <int> arr2;
    int temp;
    for(int i=0;i<n;i++){
      cin>>temp;
      arr1.push_back(temp);
    }
    for(int i=0;i<n;i++){
      cin>>temp;
      arr2.push_back(temp);
    }

    Solution ob;
    ob.kMaxSumCombination(arr1, arr2, n, k);

  }
  return 0;

}  




