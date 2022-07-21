// Stack class.
class Stack {
    
public:
    int *stack;
    int index;
    int stack_size;
    bool IsEmpty;
    bool IsFull;
    
    Stack(int capacity) {
        stack_size=capacity;
        stack=new  int[capacity+2]; 
        index=0;
        IsEmpty=true;
        IsFull=false;
        // Write your code here.
    }
    ~Stack(){
        delete stack;
    }
    void push(int num) {
        if (IsFull==false){
            IsEmpty=false;
            index++;
            stack[index]=num;
            if (index==stack_size+1){
                IsFull=true;
            }
        }
        // Write your code here.
    }

    int pop() {
        int target=-1;
        if (IsEmpty!=true){
            IsFull=false;
            target=stack[index];
            stack[index]=-100000;
            index--;
            if(index==0){
                IsEmpty=true;
            }
        }
        return target;
        // Write your code here.
    }
    
    int top() {
        int target=-1;
        if (IsEmpty!=true){
            target=stack[index];
        }
        return target;
            // Write your code here.
    }
    
    int isEmpty() {
        if (IsEmpty==true){
            return 1;
        }else{
            return 0;
        }
        // Write your code here.
    }
    
    int isFull() {
        if (IsFull==true){
            return 1;
        }else{
            return 0;
        }
        // Write your code here.
    }
    
};// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




