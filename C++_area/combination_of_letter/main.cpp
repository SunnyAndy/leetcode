#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;
int main (){
  vector <string> result2;
  result2.push_back("a");
  result2.push_back("b");
  result2.push_back("c");

  vector <string> result3;
  result3.push_back("d");
  result3.push_back("e");
  result3.push_back("f");
  vector <string> result4;
  result4.push_back("g");
  result4.push_back("h");
  result4.push_back("i");
  vector <string> result5;
  result5.push_back("j");
  result5.push_back("k");
  result5.push_back("l");
  vector <string> result6;
  result6.push_back("m");
  result6.push_back("n");
  result6.push_back("o");
  vector <string> result7;
  result7.push_back("p");
  result7.push_back("q");
  result7.push_back("r");
  result7.push_back("s");
  vector <string> result8;
  result8.push_back("t");
  result8.push_back("u");
  result8.push_back("v");
  vector <string> result9;
  result9.push_back("w");
  result9.push_back("x");
  result9.push_back("y");
  result9.push_back("z");

  /*  
  char *a =  new  char [20] ; 
  	
  for ( int i=0 ; i <26  ;  i++){
    a[i]=i+97;
  }
*/  

 
  map< char   ,  vector <string>  >  digital_map;
  digital_map.insert(  pair< char ,  vector<string> > ( '2', result2 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '3', result3 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '4', result4 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '5', result5 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '6', result6 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '7', result7 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '8', result8 ) );
  digital_map.insert(  pair< char ,  vector<string> > ( '9', result9 ) );

  string mystring="23";

   if (mystring==""){


	   vector <string> a;
	   return a;
   }


  vector <char> query_stack;
  for (int i=0  ; i <mystring.length() ; ++i){
    query_stack.push_back(mystring[i]);
    //cout<<query_stack[i]<<endl;
  }
  // to here we got the all the char stack in our program // 
  //
  vector <string> result_string;
  //initialize the result_String vector  
  vector <char>::iterator it;
  it=query_stack.end()-1;
  result_string.resize(1  ,"" );
  int orig_size=query_stack.size();
  //cout<<result_string.size()<<endl; 
  for ( int i =0  ; i <orig_size ; i++){
    it=query_stack.end()-1;
    char iter=*it;
    int current_size = result_string.size();
    cout <<current_size<<endl;
    for (int j=0 ;   j < digital_map[iter].size();j++){
	if (current_size ==1 ){
	  result_string.resize(digital_map[iter].size() , "");
	}else{
          for ( int k=0 ; k < current_size  ;  k++  ){
	      result_string.push_back(result_string[k]);
          }
	}
    }
    


    //cout<<*it<<endl;
    
    //current_size = result_string.size();
    cout<<"curent size is "<<current_size<<endl;
    for (int j=0 ;   j <digital_map[iter].size() ; j++ ){
       for (int k=0 ; k <current_size  ; k ++){
        result_string[k+j*current_size]=      digital_map[iter][j]+result_string[k+j*current_size];
	cout <<"result is "<<result_string[j*current_size +k ]<<endl;
       }
     //   result_string[].push_back((digital_map[iter][j] ));
    //	cout<< *(result_string.end()-1)<<endl;
    } 
     
  result_string.resize(current_size*digital_map[iter].size() );
  //  cout<<result_string[3]<<endl;
  //  cout<<result_string[4]<<endl;
  //  cout<<result_string[5]<<endl;
    query_stack.pop_back();
  }


  for (int j=0 ; j < result_string.size(); j++ ) {
       cout<<"current i is "<<j <<" and " << result_string[j]<<endl;


  }
  return 0;
    
  for (int i=0 ; i <mystring.length() ; i++){
    char it=mystring[i];
    for (int j =0 ; j < digital_map[it].size() ; j++ ){
      tempstring+=digital_map[it][j];
      cout<<tempstring<<endl;
    }

  }

	  



/*
  //for (int i=0 ; i < digital_map.size();  i++){
  cout << digital_map[2][0]<<digital_map[2][1]<<endl;
  cout << digital_map[2][1]<<endl;
  */  
//#    cout<<temp<<endl;
 // }
//  cout<<digital_map.begin()->second[0]<<endl;
//#list <int> my_list;
  
  
  return 0;
		
}

