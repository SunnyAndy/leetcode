// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      // step1 from the left searching for the boundary of left 
      vector<int> Right_small(heights.size(), -1 );
      vector<int> Left_small(heights.size(), -1 );
      stack<int>  oper_stack; 
      oper_stack=stack<int>(); 
      for  (int i = 0 ;  i< heights.size() ; ++i){
	  while(!oper_stack.empty()){
	    int target=oper_stack.top();
	    if (heights[target] >= heights[i]){
	      oper_stack.pop();
	    }else if( heights[target] < heights[i] ){
	      Left_small[i]=target+1;
	      break;
	    }
	  }
	  if(oper_stack.empty()){
	    Left_small[i]=0;
	  }
	oper_stack.push(i);
      }
      // step2 from the right searching for the boundart of right 
      oper_stack=stack<int>(); 
      for  (int i = heights.size()-1 ; i>= 0 ; --i){
	  while(!oper_stack.empty()){
	    int target=oper_stack.top();
	    if (heights[target] >= heights[i]){
	      oper_stack.pop();
	    }else if( heights[target] < heights[i] ){
	      Right_small[i]=target-1;
	      break;
	    }
	  }
	  if(oper_stack.empty()){
	    Right_small[i]=heights.size()-1;
	  }
	oper_stack.push(i);
      }
      // step3 calculate the area
      int max =-10000000;
      for (int i=0 ; i < heights.size(); ++i){
	int temp= ( (Right_small[i]-Left_small[i] + 1 )*heights[i]) ;
	if (temp > max ){
	  max=temp;
	}
      }
      /////////////////////////////////
#ifdef DEBUG
	cout<<"Left_small : ";
	for (int i=0 ; i < Left_small.size() ;++i){
	  cout<<Left_small[i]<<" ";
	}
	cout<<endl;

	cout<<"Right_small : ";
	for (int i=0 ; i < Right_small.size() ;++i){
	  cout<<Right_small[i]<<" ";
	}
	cout<<endl;
	cout<<"heights : ";
	for (int i=0; i <heights.size(); ++i){
	  cout<<heights[i]<<" ";
	}
	cout<<"" << endl;


	cout<<"maxi is "<<max<<endl;
#endif
      //////////////////////////////////////////////////////
      return max;
    }
};



int main() {

  vector <int> testcase={2,1,5,6,2,3,1};
  class Solution answer;

  
  answer.largestRectangleArea(testcase);
  return 0;

}  

