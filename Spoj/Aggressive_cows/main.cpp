#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
  public:
    bool check( int A[]  , int stall, int t_dist,  int cows   ){
//      bool break_flag=false;
      cows -=1;
      int i=0;
      int last_position=A[0];
      for (int  i=1;   i< stall ; i++ ){
	if (A[i]-last_position >=t_dist){
	  last_position=A[i];
	  cows-=1;
	}
	if(cows ==0) {return true;}
      }

      return false;
    }
    int find_largest_min_dist(int A[], int cows , int stall) {
          std::sort(A, A+stall);   
	   for (int i=0 ; i < stall ; i ++){
	     cout<<A[i]<<" ";
	   }
	   int min_dist=1;
	   int max_dist= (A[stall-1] - A[0]);
	   int mid;
	   while(max_dist >= min_dist){
	     mid=(min_dist+max_dist)>>1;
	     cout<<"mid is "<<mid<<endl;
	     if( check (A , stall, mid, cows) ==true    ){
	       min_dist= mid+1;
	     }else if (check(A, stall, mid, cows) ==false){
	      max_dist=mid-1;
	     }
	   }
	return  max_dist;
    }
};


int main() {
  int t;
  cin>>t;
  while(t--){
    int stall;
    cin>>stall;
    int cows;
    cin>>cows;
    int A[stall];
    for(int i=0;i<stall;i++){
      cin>>A[i];
    }
    Solution ob;
    cout << ob.find_largest_min_dist(A, cows, stall) << endl;
  }
  return 0;
}


