// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
// solution 1 the space  complexity  O(2N) :

using namespace std;
class MinStack {
  public:
    int min_val;
    stack <pair < int ,int>  > Min_Stack;
    // constructor 
    MinStack() {
      min_val=INT_MAX;
    }
    void push(int val) {
      pair<int, int > mypair;
      mypair.first=val;
      if(val <this->min_val){
	mypair.second=val;
	this->min_val=val;
      }else{
	mypair.second=this->min_val;
      }
      this->Min_Stack.push(mypair);
    }

    void pop() {
      this->Min_Stack.pop();
      if (this->Min_Stack.size()!=0){
	this->min_val=this->Min_Stack.top().second;
      }else{
	this->min_val=INT_MAX;
      }
    }

    int top() {
//      cout<<" the top is "<< this->Min_Stack.top().first;
    return this->Min_Stack.top().first;  
    }

    int getMin() {
    //  cout<<"the Min is "<< this->Min_Stack.top().second;
      return  this->Min_Stack.top().second;
    }
};

// solution 2 the space complexoty  O(N) 


int main() {

  vector <int> testcase={2,1,5,6,2,3,1};
  class  MinStack  answer;
  answer.push(-2);
  answer.push(0);
  answer.push(-3);

  answer.getMin();
  answer.pop();
  answer.top();
  answer.getMin();


  cout<<INT_MAX<<endl;

  // input one   ["MinStack","push","push","push","getMin","pop","top","getMin"]
  // input arguement [[],[-2],[0],[-3],[],[],[],[]] 
  // expected  result  [null,null,null,null,-3,null,0,-2] 

  return 0;
}  

