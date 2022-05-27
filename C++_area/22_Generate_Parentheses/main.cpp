#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
//  Definition for singly-linked list.
class Solution {
  public:  
    int string_count( string data_in  , char symbol  ){
      int count=0;
      for (int i = 0 ; i < data_in.length() ; i++){
	if (data_in[i]==symbol){
	  count++;
	}
      }
      return count;
    }
    vector<string> generateParenthesis(int n) {
      queue <string>  processing_list;
      processing_list.push("");
      queue <string>  swap_list;
      string element;
      int len =processing_list.size();
      for (int j=0 ; j <n*2 ; j++){
	len =processing_list.size();
	for (int i =0; i <  len  ;  i ++){
	  element = processing_list.front();
	  element +="(";
	  swap_list.push(element);
	  element = processing_list.front();
	  element +=")";
	  swap_list.push(element);
	  processing_list.pop();
	}
	len=swap_list.size();
	for (int i=0 ; i < len ;  ++i){
	  if (string_count (swap_list.front(),')' ) > string_count(  swap_list.front(), '(' )){
	    swap_list.pop();
	  }else if (  string_count (swap_list.front(), '(') >n ){
	    swap_list.pop();

	  }else{
	    processing_list.push(swap_list.front());
	    swap_list.pop();
	  }

	}

      }
      len = processing_list.size();
      vector <string> temp; 
      for(int i =0 ; i < len  ; i++){
	temp.push_back(processing_list.front());
//	cout<<processing_list.front()<<endl;
	processing_list.pop();
      }
      return temp;
    }
};



int main (){


  /*
     queue <int> test;
     test.push(9);
     test.push(8);
     test.push(7);
     test.push(6);
     test.push(5);
     test.push(4);
     test.push(3);
     test.push(2);
     test.push(1);


     queue <int> test2;
     test2.push(777);


     test2.swap(test);
     int len=test.size();
     for(int i =0 ; i < len ; i++){

     cout<<test.front()<<endl;
     test.pop();
     }





   */

  class Solution sol;
  //cout<< ( sol.generateParenthesis(2))[0] <<endl;
  ( sol.generateParenthesis(3))  ;
  return 0;

}

