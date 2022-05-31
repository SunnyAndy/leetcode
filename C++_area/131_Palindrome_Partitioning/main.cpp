#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class Solution {
  private:
    bool is_palidom( string &p_string   ){
      int len=p_string.length();
      if (len ==1){
	return true;
      }
      for (int i=0 ; i<len/2 ; i++){
	if(p_string[i] !=p_string[len-i-1]){
	  return false;
	}
      }
      return true;
    }
    void  dfs (  string  &s,  int  index   ,  vector <vector <string> > &res  , vector <string> cur ){
//      cout<<" start s " <<s<<endl;
      for(int i=index  ;  i <= s.length()  ; i++){
//	cout<<"s "<< i << " is "<<s.substr(0,i)<<endl;
	string fored=s.substr(0, i);

	if (is_palidom(fored)){
//	  cout<<"fored _string is "<< fored<<endl;
	  string sub_string=s.substr(i);
//	  cout<<"sub _string is "<< sub_string<<endl;
	  cur.push_back(fored);
	  if(sub_string.length()==0){
	    res.push_back(cur);
	  }
	  dfs(sub_string, 1, res, cur);
	  cur.pop_back();
	}

	

      }
    }

    public:
    vector<vector<string>> partition(string s) {
      vector <vector <string> > res;
      vector <string> cur;
      cur.clear();
      res.clear();
      dfs( s , 1 ,  res  , cur );

#ifdef DEBUG
      for (int  i =0 ; i <res.size() ; i ++){
	for (int j=0 ;j <res[i].size(); j++){
	  cout<<","<<res[i][j];
	}
	cout<<endl;
      }
#endif 
      vector< vector <string>> b;
      vector <string> c={"hello world"};
      b.push_back(c);
      return b;
      return res;
    }
};

int main (){
  class Solution sol;
  string s="abcdcefff";
  sol.partition( s) ;
  //  string  sub_string=s.substr(1);
  //   cout<< sub_string<<endl;


  return 0;
}


