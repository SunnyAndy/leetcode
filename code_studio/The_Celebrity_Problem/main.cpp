#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    if (n==1){
        return -1;
    }
    stack<int>  mystack;
    for (int i=0 ; i < n; i++){
        mystack.push(i);
    }
    int oper_a;
    int oper_b;
    while(!(mystack.size()==1)){
        oper_a=mystack.top();
        mystack.pop();
        oper_b=mystack.top();
        mystack.pop();
        if(knows(oper_a , oper_b)){
            mystack.push(oper_b);
        }else if(!knows(oper_a , oper_b)){
            mystack.push(oper_a);
        }
    }
    
    int target=mystack.top();
    for (int  i=0 ; i < n ; i ++){
        if ( knows(target , i)    ){  
            return -1;
        }
        if(!knows(i, target) and target!=i){
            return -1;
        }
    }
    return target;
    
}

