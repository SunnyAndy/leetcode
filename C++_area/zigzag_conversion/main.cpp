#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

class Solution{
  public:
    string convert(string s, int numRows) {
      if (numRows ==1){
	return s;
      }

      string result="";

      int cycle_dis = 2*numRows -2 ;
      for (int r=0 ;r < numRows; r++){
	for (int j=0 ; r+j < s.length() ; j += ( cycle_dis  )){
	  result+=s[r+j];
	  if (r >0   and  r < numRows -1  and ( r+j+cycle_dis   -2*r <s.length()) ){
		result += s[ r+j+  cycle_dis - 2*r ];
	  }
	}
      }

      return result;
    }
};







int main (){


  class Solution mysol;
  cout<<mysol.convert("PAYPALISHIRING" , 4);  // testing  case 

  return 0;

}

