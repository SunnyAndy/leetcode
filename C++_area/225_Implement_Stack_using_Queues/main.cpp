#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;



class MyStack {
public:
    queue<int> stack;
    //eue temp;
    MyStack() {

    }
    void push(int x) {
        stack.push(x);
    }
    int pop() {
        int result=stack.back();
        if (stack.size()==1){
            stack.pop();
        }else{
            std::queue<int> temp;
            for (int i=0 ; i < stack.size() ;  i++){
                temp.push(stack.front());
                stack.pop();
            }
            swap(stack, temp);
        }
        return result;
    }

    int top() {
        return stack.back();

    }

    bool empty() {
        return stack.empty();

    }
};


int main (){


  return 0;

}

