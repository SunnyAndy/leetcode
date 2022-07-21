#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
class MyQueue {
  public:
    stack <int> qu;
    MyQueue() {
    }
    void push(int x) {
      stack <int> temp;
      while (qu.size()!=0){
	temp.push(qu.top());
	qu.pop();            
      }
      qu.push(x);
      while(temp.size()!=0){
	qu.push(temp.top());
	temp.pop();            
      }
    }
    int pop() {

      int res= qu.top();
      qu.pop();
      return res;

    }

    int peek() {
      return  qu.top();
    }

    bool empty() {
      if (qu.size()==0){
	return true;
      }else{
	return false;
      }

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
