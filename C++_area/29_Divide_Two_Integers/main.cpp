#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
      int sign=0;
      if ( (dividend  <0 and divisor <0 ) or  (dividend > 0 and divisor >0)  ){
	sign=1;

      }else{
	sign =-1;
      }
      long long Dend= dividend;
      Dend= abs(Dend);
      long long Dsor = divisor;
      Dsor=abs(Dsor);
      long long a=1;
      long long  q=0;
      long long  sum=0;
      for (int i = 31 ;  i >=0 ; --i){
	if ( (sum + ( Dsor<<i) ) <= Dend){
	  sum+=Dsor<<i;
	  q+= a<<i;
	}
      }
      int res=0;
      if (sign ==1 ){
	q=q;
      }else{
	q =q*-1;
      }
      if (q>2147483647 ){
	res=2147483647;
      }else{
	res =q;
      }
      return res;
    }
};

int main (){

  class Solution sol;
  //cout<< ( sol.generateParenthesis(2))[0] <<endl;

  sol.divide(  2147483647   ,  1    ) ;
  sol.divide(  2147483647   ,  -1    ) ;
  sol.divide(  -2147483647   ,  1    ) ;
  sol.divide(  -2147483647   ,  -1    ) ;
  return 0;

}





// time limiation excess 
class Solution_1 {
  public:
    int divide(int dividend, int divisor) {

      if (divisor ==0){
	cout<<"error nothing could be divided by zero"<<endl;
	return -1;
      }
      if (dividend ==0){
	cout<<"0 is  0"<<endl;
	return 0;
      }
      cout<<"golden  answer is "<< dividend/divisor<<endl;
      long long  quiet=0;
      int remi=dividend;
      if(dividend >0 ){
	if (divisor >0){
	  while(remi >0){
	    quiet+=1;
	    remi -=divisor;
	    cout<<"remi is "<<remi<<endl;
	  }
	  if(remi !=0)
	    quiet-=1;

	  cout<<"quiiet "<<quiet<<endl;
	} else if( divisor <0   ){
	  while(remi >0){
	    quiet+=1;
	    remi -=-1*divisor;
	    cout<<"remi is "<<remi<<endl;
	  }
	  if (remi !=0 )
	    quiet-=1;
	  quiet *=-1;
	  cout<<"quiiet "<<quiet<<endl;
	}
      }else if (dividend < 0 ){
	if (divisor >0) {
	  while(remi <0){
	    quiet+=1;
	    remi -=-1*divisor;
	    cout<<"remi is "<<remi<<endl;
	  }
	  if(remi !=0)
	    quiet-=1;
	  quiet *=-1;
	  cout<<"quiiet "<<quiet<<endl;
	}else if(divisor < 0){
	  while(remi <0){
	    quiet+=1;
	    remi -=divisor;
	    cout<<"remi is "<<remi<<endl;
	  }
	  if (remi !=0)
	    quiet-=1;
	  cout<<"quiiet "<<quiet<<endl;
	}
      }


      int res=0;
      if (quiet >2147483647){
	res=2147483647;
      }else if (quiet<-2147483648 ){
	res= -2147483648 ;
      }else{
	res =quiet;
      }

      return  res;
    }
};





