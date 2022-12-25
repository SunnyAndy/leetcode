// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
// solution 1 the space  complexity  O(2N) :

using namespace std;
class Solution {
  public:
    //    RomanMap={{"I", 1 }, {"V",5}, {"X",10} ,{"L",50},{"C",100},{"D",500},{"M",1000}} ;
    int romanToInt(string s) {
      std::unordered_map < char,int > RomanMap;
      RomanMap['I']=1;
      RomanMap['V']=5;
      RomanMap['X']=10;
      RomanMap['L']=50;
      RomanMap['C']=100;
      RomanMap['D']=500;
      RomanMap['M']=1000;
      int result=0; 
      for (int i=s.size()-1 ; i >=0 ; --i){
	if (i==s.size()-1){
	  result +=RomanMap.at(s[i]);
//	  cout<<"test result  "<< s[i] <<" "<< result<<endl;
	}else{
	  if (RomanMap.at(s[i])  < RomanMap.at(s[i+1])   ){
	    result -=RomanMap.at(s[i]);
//	  cout<<"test result  "<< s[i] <<" "<< result<<endl;
	  }else{
	    result += RomanMap.at(s[i]);
//	  cout<<"test result  "<< s[i] <<" "<< result<<endl;
	  }
	}
//	cout<<s[i]<<" "<<RomanMap.at(s[i])<<endl;
      }
      return result;
    }
};




/*
   I             1
   V             5
   X             10
   L             50
   C             100
   D             500
   RomanMap["I"]=1;
   M             1000
 */

// solution 2 the space complexoty  O(N) 


int main() {


  class Solution Roman;

  string s = "III";

  string b = "LVIII";
  string c= "MCMXCIV";
  Roman.romanToInt(s);




  return 0;
}  

