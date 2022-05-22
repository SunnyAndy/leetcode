#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
      string **romans;
      romans = new (string (*[4]));
      for(int i =0 ; i<4; i++ ){
	romans[i] = new string[10];
      }
      romans[0][1]="I"      ;  // 1
      romans[0][2]="II"     ;  //2
      romans[0][3]="III"    ;  //3
      romans[0][4]="IV"     ; //4
      romans[0][5]="V"      ; //5
      romans[0][6]="VI"     ; //6
      romans[0][7]="VII"    ; //7
      romans[0][8]="VIII"   ; //8
      romans[0][9]="IX"     ; //9 

      romans[1][1]="X"      ; //10 
      romans[1][2]="XX"     ; //20
      romans[1][3]="XXX"    ; //30 
      romans[1][4]="XL"     ; //40 
      romans[1][5]="L"      ; //50 
      romans[1][6]="LX"     ; //60
      romans[1][7]="LXX"    ; //70
      romans[1][8]="LXXX"   ; //80 
      romans[1][9]="XC"     ; //90

      romans[2][1]="C"      ; //100
      romans[2][2]="CC"     ; //200
      romans[2][3]="CCC"    ; //300
      romans[2][4]="CD"     ; //400
      romans[2][5]="D"      ; //500
      romans[2][6]="DC"     ; //600 
      romans[2][7]="DCC"    ; //700
      romans[2][8]="DCCC"   ; //800
      romans[2][9]="CM"     ; //900

      romans[3][1]="M"      ; //1000
      romans[3][2]="MM"     ; //2000
      romans[3][3]="MMM"    ; //3000 


      string result="";
      for (int i=0; i<4 ; ++i){

	int d=num%10;
	int r=num/10;
	num=r;
	result=result.insert(0,romans[i][d]);
//	result+=romans[i][d];
	if (r>0){
	  num=r;

	}else{

	  break;
	}

      }



      return result;

    }
};




int main (){

  class Solution mysol;
  cout<<mysol.intToRoman( 399  );  // testing  case 
  cout<<endl;
  /*
  cout<<mysol.intToRoman( 1232  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1233  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1234  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1235  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1236  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1237  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1238  );  // testing  case 
  cout<<endl;
  cout<<mysol.intToRoman( 1239  );  // testing  case 
*/
  return 0;

}

