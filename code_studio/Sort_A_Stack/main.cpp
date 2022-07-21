// didn't implement the IO , IO rules are in the question page
//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<stack>
using namespace std;
void InsertSortStack(stack<int> &s , int ele ){
    if (s.empty()==true or ele >= s.top()){
        s.push(ele);   
    }else {
        int temp=s.top();
        s.pop();
        InsertSortStack( s, ele);
        s.push(temp); 
    }
       
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if(!stack.empty()){
        int val=stack.top();
        stack.pop();
        sortStack(stack);
        InsertSortStack(stack , val);            
    }
    
    return;
}

int main(){

  return 0;
}



