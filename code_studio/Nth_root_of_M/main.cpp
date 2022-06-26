// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {

  public:
    double findNthRootOfM(int n, long long m) {
      // Variable to store maximum possible error in order
      // to obtain the precision of 10^(-6) in the answer.
      double error = 1e-7;

      // Difference between the current answer, and the answer
      // in next iteration, which we take as big as possible initially.
      double diff = 1e18;

      // Guessed answer value
      double xk = 2;

      // We keep on finding the precise answer till the difference between
      // answer of two consecutive iteration become less than 10^(-7).
      while (diff > error) {

	// Answer value in the next iteration.
	double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));

	// Difference of answer in consecutive states updated.
	diff = abs(xk - xk_1);

	// Updating the current answer with the answer of next iteration.
	xk = xk_1;
      }

      // Returning the nthRootOfM with precision upto 6 decimal places
      // which is xk.
      return xk;
    }

};


class Solution_fail {
  public:
    double squar_funct(int n  , double mid){
      double ret =1.0;
      for (int  i=1; i <= n ; ++i){
	ret =ret*mid;
      }
      return ret;
    }
    double findNthRootOfM(int n, long long m) {

      setprecision(8);
      double left =1;
      double right = m;
      double mid ; //=(left+right)/2.0;
      double result ; // =squar_funct(n , mid);
      if (  m==1){
	return 1.0;
      }
      double per=1e-7;
      //      double diff=0;
      //      diff= abs(result-m);
      double diff = (right-left);
      while ( diff  >per){
	cout<<" r " <<right<<endl;
	cout<<" l " <<left<<endl;
	cout << fixed  << setprecision(7)<<mid<<endl;
	cout <<mid<<endl;
	mid=(left+right)/2.0;
	result=squar_funct(n, mid);
	if(result > m) {
	  right=mid;
	}else if (result < m){
	  left=mid;
	}else if (result == m ){
	  return mid;
	}
	diff = (right-left);
      }
      mid = mid * 1000000;//x=654.569
      mid = round (mid) ; // Math.Floor(x);//無條件捨去
      mid = mid / 1000000;//把100除回來
      return mid;
    }

};




int main() {
  class Solution mysolution;
  cout<<fixed<<setprecision(6)<<mysolution.findNthRootOfM(2,3)<<endl;
  return 0;

}  // } Driver Code Ends




