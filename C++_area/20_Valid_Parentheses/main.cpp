// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    bool isValid(string s ){
      stack <char> mystack;
      if(s.length()%2 !=0){
	return false;
      }
      for (int i=0 ; i < s.length() ; i ++){
	if (s[i]=='(' or s[i]=='[' or s[i]=='{'){
	  mystack.push(s[i]);
	}else{
	  if (mystack.size()==0){
	    return false;
	  }
	  if(s[i]==')'){
	    if (mystack.top()!='(' )  {
	      return false;
	    }
	    else{
	      mystack.pop();
	    }
	  }else if (s[i]==']'){
	    if (mystack.top()!='[') {
	      return false;
	    }
	    else{
	      mystack.pop();
	    }
	  }else if (s[i]=='}'){
	    if (mystack.top()!='{') {
	      return false;
	    }
	    else{
	      mystack.pop();
	    }
	  }
	}
      }
      if(mystack.size()==0){
	return true;
      }else{
	return false;
      }

    }



    bool isValid_failed(string s) {
      stack <char> st1;
      stack <char> st2;
      stack <char> st3;
      for (int i=0 ; i < s.length(); i++){
	if (s[i]=='(' or s[i]==')'){
	  if (s[i]=='('){
	    st1.push(s[i]);
	  }else{
	    if(st1.empty()){
	      return false;
	    }else{
	      st1.pop();
	    }
	  }
	}else if (s[i]=='[' or s[i]==']'){
	  if (s[i]=='['){
	    st2.push(s[i]);
	  }else{
	    if(st2.empty()){
	      return false;
	    }else{
	      st2.pop();
	    }
	  }
	}else if (s[i]=='{' or s[i]=='}'){
	  if (s[i]=='{'){
	    st3.push(s[i]);
	  }else{
	    if(st3.empty()){
	      return false;
	    }else{
	      st3.pop();
	    }
	  }
	}else {
	  cout<< "input error "<<endl;
	  return false;
	}
      }
      return true;
    }
};

int main() {
  class Solution mysolution;


  string A="(((";

  cout << mysolution.isValid(A);
  return 0;

}  




