#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int count_for_smaller (vector <int > &row ,   int val     ){
      int l = 0, h = row.size() - 1;
      while (l <= h){
	int md = (l + h) >> 1;
	if (row[md] <= val){
	  l = md + 1;
	}else{
	  h = md - 1;
	}
      }
      return l;
    }

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
      vector <int> num1;
      vector <int> num2;
      for (int i=0 ; i < n; i++){
	num1.push_back(arr1[i]);
      }

      for (int i=0 ; i < m; i++){
	num2.push_back(arr2[i]);
      }

      int half_num=0;
//      int total_element_num=nums1.size()+nums2.size();
      half_num=k-1;
      int ret;
      int min=1;
      int max=INT_MAX;
      while (max >= min){
	int mid =  (min+max)>>1;
	int less_number=0;
	less_number += count_for_smaller (  num1 , mid);
	less_number += count_for_smaller (  num2 , mid);
	if (less_number >   half_num  ){
	  max=mid-1;
	}else {
	  min=mid+1;
	}
      }
      ret= min;

      return  min;

    }
};

// { Driver Code Starts.

// Driver code
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n,m,k;
    cin>>n>>m>>k;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
      cin>>arr1[i];
    for(int i=0;i<m;i++)
      cin>>arr2[i];

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
  }
  return 0;
}  // } Driver Code Ends




