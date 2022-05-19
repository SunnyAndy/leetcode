#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;





class Solution{

  public:
    vector <string> letterCombinations(string digits){
      if (digits==""){
	vector <string> a;
	return a;
      }

      vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      //      for (int i = 2; i <= 9 ; i++){
      //	for (int j=0  ; j <=dict[i].length() ; ++j){
      //	  cout <<"_"<<dict[i][j]<<"_";
      //	}
      //	cout<<endl;
      //      }


      vector <string> queue;
      queue.push_back("");
      string temp;
      vector <string> working_set;
      for (int i =0 ; i < digits.length() ; ++i){
	while (queue.empty() != true){
	  temp=queue.front();
	  queue.erase(queue.begin());
	  for (char it : dict[digits[i]-'0']){
	    string temp2="";
	    temp2 = temp+it;
	    working_set.push_back(temp2);
	  }
	}
	queue.swap(working_set);
      }

      return queue;

    }



};



int main (){


  class Solution mysol;
  vector <string> result =   mysol.letterCombinations("234");

  for (int i=0 ; i <result.size() ; i++){
    cout<<result[i]<<endl;


  }
  return 0;


}

