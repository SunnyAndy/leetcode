#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;



// * Definition for singly-linked list.


class Solution{

  public:
    int lengthOfLongestSubstring(string s) {
    //  cout <<s.length()<<endl;
      int  head=0;
      int tail=head;
      unsigned int max_length=0;
      string sub_string="";
      for  (int i=0; i< s.length();  i++){
//	cout <<"at begining "<< sub_string<<endl;
	if (sub_string.find(s[i]) != string::npos ){
		while (sub_string.find(s[i]) !=string::npos){
		  sub_string.erase(0,1);
		}
		sub_string +=s[i];
//		cout<<"hit thanks "<< sub_string <<endl;
		// while loop to operate the sub string 
	}else{
            sub_string +=s[i];
	    if (sub_string.length() > max_length){
		    max_length = sub_string.length();
	    }else{
		    max_length=max_length;
	    }
	}

      }
  //    cout<<sub_string<<endl;
   //   cout<< max_length<<endl;
      
      return max_length ;
    }

};




int main (){
 
  class Solution my_sol;


  cout <<my_sol.lengthOfLongestSubstring("abcabcbb")<<endl;
  cout <<my_sol.lengthOfLongestSubstring("bbbbbbbb")<<endl;
  cout <<my_sol.lengthOfLongestSubstring("pwwkew")<<endl;

  return 0;








}

