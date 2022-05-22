#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

// ascii  a~z  -->  97~122
//        A~Z  -->  65~90
//         +   -->  43
//         -   -->  45 
//         .   -->  46
//       space -->  32 
//       0~9   -->  48  - 57 


class Solution{
  public:
    int  myAtoi( string s ) {
      int length=s.length();
      int i=0;
      bool neg=false;
      string result="";
      while ( s[i]==32){
        i++;
      }
      string reduce_string="";
      reduce_string=s.substr( i, length);
      cout<<"original string:"<<s<<endl;
      cout<<"string with reducing space:"<<reduce_string<<endl;
      // finish reducing the removing space ;
      length =reduce_string.length(); 
      if (reduce_string[0]==45){
	neg=true;
	cout<<"--------";
	reduce_string=reduce_string.substr(1,length);
      }else if (reduce_string[0]==43){
	neg=false;
	reduce_string=reduce_string.substr(1,length);
      }
      cout<<"string with reduce + -:"<<reduce_string<<endl;
      // finish the + - symbol operation 
      length =reduce_string.length(); 
      i=0;
      string res="";
      while (i != length){
	if (reduce_string[i]>57 or reduce_string[i]<48){
	  break;
	} else if (reduce_string[i] >=48 and reduce_string[i]<=57){
	  res +=reduce_string[i];
	  i++;
	}
      }
      if (res.length()==0){
      	return  0;      
      }
      
      i=0;
      length=res.length();
      while(i!=length){
	if (res[i]==48){
	  i++;
	}else{
	  break;
	}
      }

      res =res.substr(i,length);

      if (res.length()==0){
	return 0;

      }



      cout<<"resul string:"<<res<<endl;
      string max_string="2147483647";
      string min_string="2147483648";
      int result_int;
      if (neg==false ){
	if (res.length() <10){
	  result_int = stoi(res);
	  cout<<"answer is "<< result_int<<endl;
	  return result_int;
	}else if (res.length() >10){
	  result_int= stoi(max_string);
	  cout<<"answer is  max value  "<< result_int<<endl;
	  return result_int;
	}else {
         for ( int  i=0; i <res.length() ; i++){
            if (max_string[i]-res[i]>0) {
	      result_int = stoi(res);
	      cout<<"answer is "<< result_int<<endl;
	      return result_int;
            }else  if (max_string[i]-res[i] <0) {
	      result_int= stoi(max_string);    
	      cout<<"answer is  max value  "<< result_int<<endl;
	      return  result_int;
            }
	 }
	}
      }else {
	if (res.length() <10) {
	  result_int= stoi(res);
	  result_int = -1* result_int;
	  cout<<"result is" << result_int <<endl;
	  return result_int;
	}else if (res.length() >10){
	  result_int = -2147483648;
	  cout <<"result is "<<result_int<<endl; 
	  return result_int;
	}else{
	  for (int i=0 ; i<res.length () ; i++){
	    if (min_string[i]-res[i]>0){
	      result_int=stoi(res);
	      result_int = result_int*-1;
	      cout<<"answer is "<<result_int<<endl;
	      return  result_int ; 
	    }else if (min_string[i]-res[i]<0){
	      result_int =-2147483648;
	      cout<<"result is  MIN_VAL "<<result_int <<endl;
	      return  result_int;
	    }
	  }
	}
      }


      if (neg==false){
	result_int = stoi(res);
	cout<<"resulr is  " <<result_int<<endl;
      }else if (neg ==true ){
	string negg="-";
	negg +=res;
	result_int = stoi(negg);
	cout<<"resultis "<<result_int<<endl;

      }	  


      return result_int;
    }
};




int main (){

  class Solution mysol;
  cout<<mysol.myAtoi( "00000-42a1234"  );  // testing  case 

  return 0;

}

