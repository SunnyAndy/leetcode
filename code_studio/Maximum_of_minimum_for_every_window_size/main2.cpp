/// better solution 
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
   // while (!operator_stack.empty()){
    //  operator_stack.pop();
   // }
    //  find the left small index 
    for(int i=0 ; i < n ; ++i ){
      while(!operator_stack.empty() &&  a[operator_stack.top()]>= a[i] ){
          operator_stack.pop();
      }
      if (!operator_stack.empty()){
          left_small_index[i]=operator_stack.top();
      }
      operator_stack.push(i);
   }
    
  while (!operator_stack.empty()){
      operator_stack.pop();
    }
    for(int i=n-1 ; i >=0 ; --i){
      while(!operator_stack.empty() &&   a[operator_stack.top()] >= a[i]    ){
          operator_stack.pop();
      }
      if(!operator_stack.empty()){
         right_small_index[i]=operator_stack.top();
       }  
       operator_stack.push(i);
     }
    // Write your code here.
      int  len;
    vector <int> result;
    for(int i=0 ; i < n+1 ; ++i){
      result.push_back(INT_MIN );
    }
    for(int i= 0 ; i < n ; ++i){
      len=right_small_index[i]-left_small_index[i]-1;
      result[len]= max (result[len] , a[i]);
    }
    for (int i=n-1; i >=1  ; --i ){
      result[i] = max(result[i], result[i+1]);
    }
     result.erase (result.begin());

     return result ;
}

