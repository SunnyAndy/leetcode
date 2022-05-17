#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;



// * Definition for singly-linked list.


class Solution{

  public:
    int lengthOfLongestSubstring(string s) {
      cout <<s.length()<<endl;
      int  head=0;
      int tail=head;
      unsigned int max_length=0;
      string sub_string="";
      for  (int i=0; i< s.length();  i++){
	if (sub_string.find(s[i]) != string::npos ){
		cout<<"hit thanks " <<endl;
		// while loop to operate the sub string 
	}else{
	    if (sub_string.length() > max_length){
		    max_length = sub_string.length();
	    }else{
		    max_length=max_length;
	    }

	    sub_string.erease(0,0+1);


	}
        sub_string +=s[i];

      }
      cout<<sub_string<<endl;

	    return 1;
    }

};




int main (){
 
  class Solution my_sol;


  cout <<my_sol.lengthOfLongestSubstring("abcabc")<<endl;

  return 0;








}

