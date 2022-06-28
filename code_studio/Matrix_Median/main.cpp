// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int count_for_smaller (vector <int > &row ,   int val     ){
      int l = 0, h = row.size() - 1;
      while (l <= h)
      {
	int md = (l + h) >> 1;
	if (row[md] <= val)
	{
	  l = md + 1;
	}
	else
	{
	  h = md - 1;
	}
      }
      return l;
    }
    int getMedian(vector<vector<int>> &matrix)
    {
      int min=1;
      int max=1e6;
      int row=matrix.size();
      int col=matrix[0].size();
      while (max >= min){
	int mid =  (min+max)>>1;
	int less_number=0;
	for (int i=0  ; i < matrix.size()  ; i ++){
	  less_number += count_for_smaller (matrix[i] , mid);
	}
	if (less_number >  (row*col)/2  ){  
	  max=mid-1;
	  //	  min=min;
	}else {
	  //	  max=max;
	  min=mid+1;
	}
      }
      return min;

    }
};

    int main() {
      class Solution mysolution;


//      vector <vector <int> > A= { { 2 ,6,9},{1,5,11},{3,7,8}   };
      vector <vector <int> > A= {  {1,2,3}   };

      cout<<mysolution.getMedian(A) <<endl;
      return 0;

    }  




