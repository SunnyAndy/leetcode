#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

class Solution{
  public:
    int reverse(int x ){
      string test_string;
      test_string= to_string(x);
      if (x<0){
	int len=test_string.length();
	test_string=  test_string.substr(1,len);
      }
      string result="";
      for (string::iterator itr = test_string.end()-1 ; itr != test_string.begin()-1 ; itr--) {
	result +=*itr;
      }	 
      string max_string="2147483647";
      string min_string="2147483648"; 
      int num=0;
      if (result.length()<10){
	num = stoi(result);
	cout<<num<<endl;
	if (x<0){
	  num=-1*num;
	}
	return num;
      }else if (result.length() ==10 ){
	if (x>=0){
	  for ( int  i=0; i <result.length() ; i++){
	    if (max_string[i]-result[i]>0) {
		break;
	    }else  if (max_string[i]-result[i] <0) {
	      num=0;
	      return 0;
	    }
	  }
	}else if(x<0){
	  for (int i=0 ; i<result.length () ; i++){
	    if (min_string[i]-result[i]>0){
		break;
	    }else if (min_string[i]-result[i]<0){
	      num=0;
	      return 0;
	    }
	  }
	}
	num=stoi(result);
	if (x<0){
	  num = -1*num;
	}
	return num;
      }else {
	return 0;
      }
    }
};







int main (){
  class Solution mysol;
  cout<<mysol.reverse( -2147483412);  // testing  case 
  return 0;
}

