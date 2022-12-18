// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
vector<int> maxMinWindow(vector<int> a, int n) {
    vector <int > left_small_index ;
    vector <int > right_small_index;
    for(int i=0 ; i < n ; i++){
      left_small_index.push_back(-1);
      right_small_index.push_back(n);
    }
    stack <int> operator_stack;
    while (!operator_stack.empty()){
      operator_stack.pop();
    }
    //  find the left small index 
    for(int i=0 ; i < n ; i++ ){
      while(!operator_stack.empty()){
	if ( a[operator_stack.top()]>= a[i]  ){
	  operator_stack.pop();
	}else if ( a[operator_stack.top()] < a[i]){
	 left_small_index[i]=operator_stack.top();
	  operator_stack.push(i);	
	  break;
	}
      }
      if (operator_stack.empty()){
	operator_stack.push(i);
      }
    }
    /// debug 
    /*
    for(int i=0 ; i <n ; ++i){
      cout<<" "<<left_small_index[i];
    }
    cout<<endl;
    */
    // end of dbugging 
    // clear the stack 

    while (!operator_stack.empty()){
      operator_stack.pop();
    }
    for(int i=n-1 ; i >=0 ; i--){
      while(!operator_stack.empty()){
	if( a[operator_stack.top()] >= a[i]  ){
	  operator_stack.pop();
	}else if (a[operator_stack.top()] <a[i]){
	  right_small_index[i]=operator_stack.top();
	  operator_stack.push(i);
	  break;
	}
      }
      if(operator_stack.empty()){
	operator_stack.push(i);
      }
    }
    // Write your code here.

    /*
    for(int i=0 ; i <n ; ++i){
      cout<<" "<<right_small_index[i];
    }
    cout<<endl;
*/

      int  len;
    vector <int> result;

    for(int i=0 ; i < n+1 ; i++){
      result.push_back(INT_MIN);
    }

    for(int i= 0 ; i < n ; i++){
      len=right_small_index[i]-left_small_index[i]-1;
      result[len]= max (result[len] , a[i]);
    }

    for (int i=n-1; i >=1  ; i-- ){
      result[i] = max(result[i], result[i+1]);
    }
     result.erase (result.begin());

//    result.erase (result.end()-1);  code studio will truncate  

     for(int  i =0 ; i <= result.size() ; ++i){
    cout<<" "<<result[i] ;
    }

     return result ;
}

int main()
{
//    int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
  //  int n = sizeof(arr) / sizeof(arr[0]);
    
//    vector <int> testcase={10,20,30,50,10,70,30};
    vector <int> testcase={3,3,4,2,4};
    int n= testcase.size();
    maxMinWindow(testcase, n);
    return 0;
}

    /*
    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]
    for (int i = 0; i < n; i++) {
        // length of the interval
        int len = right[i] - left[i] - 1;
 
        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        ans[len] = max(ans[len], arr[i]);
    }
 
    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);

*/
