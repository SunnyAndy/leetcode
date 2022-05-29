#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {
  public:
    string all_result[31];
    string countAndSay(int n) {
      if (n==1){
	return "1";
      }
      else{
	if (all_result[n]==""){
	  string Val=countAndSay(n-1);
	  string result="";
	  string temp="";
	  int count=0;
	  for (int i =0 ; i <Val.length(); i++){
	    count+=1;
	    if(   (i != Val.length() ) and  (Val[i]-Val[i+1] != 0 ) ){
	      result +=char(48+count);
	      result +=Val[i];
	      count=0;
	    }

	  }

	  all_result[n]=result;
	  return result;
	}
	else{
	  return all_result[n];
	}

      }
    }
};

int main (){


  class Solution sol;

  cout<< sol.countAndSay(7)<<endl;
  cout<< sol.countAndSay(6)<<endl;
  return 0;

}






/*
      string Val="312211";
      string result="";
      string temp="";
      int count=0;
      for (int i =0 ; i <Val.length(); i++){
	count+=1;
	if(   (i != Val.length() ) and  (Val[i]-Val[i+1] != 0 ) ){
	  result +=char(48+count);
	  result +=Val[i];
	  count=0;
	}

      }

      cout<<result<<endl;

*/
