#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    //Function to find minimum number of pages.
    int  divid_funct ( int  barrier, int A[], int N     ){
      int temp=0;
      int i=0 ; 
      int number_group=0;

      while( i <N ){
	if (temp+A[i] <= barrier){
	  if (temp==0){
	    number_group+=1;
	  }
	  temp+=A[i];
	}else{
//	  cout<<"temp "<<temp<<endl;
	  if(temp !=0){
	    number_group+=1;
	  }
	  temp=A[i];
	  if (temp > barrier){
	    return INT_MAX;   // if the barrier  cannot contain a single element that we need more  high barrier 
	  }
	}
	i+=1;
      }
//      cout<<"number_of_group "<<number_group<<endl;
      return number_group;
}

int findPages(int A[], int N, int M) {
  if (M>N){
    return -1;
  }
  int sum =0;
  int min_v=100000000;
  int max_v=0;
  for (int i=0 ; i < N ; i++){
    sum += A[i];
    min_v = min(min_v, A[i]);
    max_v =max(max_v , A[i]);
  }
  if(M==N){
    return max_v;
  }

  int high=sum;
  int low= min_v;
  int number_group=0;
  int mid;
  while (high >= low ){
    mid= (high+low)>>1;
//    cout<<"mid is "<<mid<<endl;
    number_group=divid_funct(  mid,   A  , N );
    if (number_group > M){
      low=mid+1;
    }else if (number_group  ){
      high= mid-1;
    }
  }
  return low;


}
};


int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    int m;
    cin>>m;
    Solution ob;
    cout << ob.findPages(A, n, m) << endl;
  }
  return 0;
}







