#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;




class Solution{

  public:
    string longestPalindrome (string s ){
      string max_string="";
      string temp_string="";

      for (int i =0  ; i <s.length(); ++i){
	int l=i;
	int r=i;
	while ( l  >=0   and  r<= s.length() ){
	  if (s[l] == s[r]){
	    l-=1;
	    r+=1;
	  } else {
	    //    l+=1;
	    //    r-=1;
	    break;
	  }
	}
	l+=1;
	r-=1;

	if (r-l+1> max_string.length()){
	  max_string="";
	  for (int j =l ;  j <=r ; j++){
	    max_string += s[j];
	  }
	}
	cout<<"max_string "<<max_string<<endl;	

      }


      for (int i=0 ; i < s.length()-1 ; ++i){
	int l=i;
	int r=i+1;
	while ( l>= 0 and r<=s.length() ){
	  if (s[l] == s[r]){
	    l-=1;
	    r+=1;
	  } else {   
	    break;    
	  }
	}
	l+=1;
	r-=1;
	if (r-l+1 >max_string.length()){
	  max_string="";
	  for (int j=l; j<=r ; j++){
	    max_string += s[j];
	  }

	  cout<< "max_string _even "<<max_string<<endl;
	}
      }





      // an try for the string operation //
      /*
	 string result_string="";
	 for (int  i=0  ; i<3 ; ++i){
	 result_string += s[i];
	 }

	 cout <<result_string.length()<<"_";
       */



      string result="hello world";

      return  max_string;


    }

};




int main (){

  class Solution mysol;
  cout<<mysol.longestPalindrome ("abaccfggfcc" );
  return 0;

}

