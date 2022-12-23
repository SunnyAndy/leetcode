// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    string reverseWords(string s) {
      s +=" ";
      int length=s.size();
      string temp="";
      stack <string> mystack;
      int start=0;
      while(start!=length){
	if(s[start]==0x20){
	  if(temp!=""){
	    mystack.push(temp);
	    temp="";
	  }
	  start +=1;
	  continue;
	}else{
	  temp =temp+s[start];
	  start +=1;
	}
      } 

      string result="";
      while(mystack.size()!=0){
	result+=mystack.top();
	if(mystack.size()==1){
	}else{
	  result+=" ";
	}
	mystack.pop();
      }

      cout<<result;
      return result;

    }
}; 






int main() {

  class  Solution  answer;

  string s=" hello       world myworld";
  cout<<s<<endl;
  answer.reverseWords(s);


  return 0;
}  

