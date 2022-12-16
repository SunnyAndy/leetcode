// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:

    stack <pair<int, int >>  oper_stack;
    StockSpanner() {
    }
    int next(int price) {
      int prev_count=0;
      while ( !oper_stack.empty()){
	if (oper_stack.top().first > price ){
	  oper_stack.push({price, prev_count+1});
	  break;
	}else if (oper_stack.top().first <= price){
	  prev_count += oper_stack.top().second;
	  oper_stack.pop();
	}
      }
      if(oper_stack.empty()){
	oper_stack.push({price, prev_count+1});
      }
      return oper_stack.top().second; 
    }
};

int main() {
  class  StockSpanner  answer;
  int array[7]={100,80,60,70,60,75,85 };
  for (int i=0 ; i<7  ; i++){
	cout<< answer.next(array[i])   <<" "<<endl;;
  }
  return 0;
}  

