#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;



// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };




class Solution{

  public:
    vector <int > node_add(  int add1 , int add2 , int carry_in  ){
	    int all_sum=  add1+add2+carry_in;
	    int carry_out = int (all_sum/10);
	    int result_bit = all_sum%10;
	    vector<int> result;
	    result.clear();
	    result.push_back(result_bit);
	    result.push_back(carry_out);
	    return result;
    }
    struct ListNode node_creating(  int value , struct ListNode * nextNode){
	    struct ListNode result;
	    result.val=value;
	    result.next =nextNode;
	    return result;
    }

    //static struct ListNode result_List;
    ListNode * addTwoNumbers(ListNode*  l1 , ListNode*l2){
	    vector <int>   inter_result;
            
    	    struct ListNode * result_List;
            struct ListNode *  iter;
	    result_List=nullptr; 
	    iter=result_List;
	    result_List=iter;
	    //result_List.val=-10;
	    //result_List.next=nullptr;
	    struct ListNode * pointer1 = l1 ;
	    struct ListNode * pointer2 = l2 ;  
	    int in1=0;
	    int in2=0;
	    int carry=0;
	    while(pointer1 !=nullptr  || pointer2 !=nullptr || carry !=0){
	      struct ListNode  *current_node;
	      current_node = new struct ListNode;
	      if (pointer1 != nullptr){
		in1=pointer1->val;
	      }else{
	        in1=0;
	      }
	      if (pointer2 != nullptr){
		in2=pointer2->val;
	      }else{
	        in2=0;
	      }
	      inter_result = node_add(in1 , in2 , carry);
	      carry = inter_result[1];
	      current_node->val=inter_result[0];
	      current_node->next=nullptr;
	      if (result_List==nullptr){
		result_List=current_node;
		cout<<"val is "<<result_List->val<<endl;
		iter=current_node;
	      }else{
	        iter->next=current_node;
		iter = iter->next;
		cout<<"value is "<< iter->val<<endl;
	      }
	      
	      if (pointer1 ==nullptr){
		      pointer1=nullptr;
	      }else if (pointer1->next != nullptr){
	        pointer1 = pointer1->next;
	      }else{
		pointer1 = nullptr;
	      }
	      if(pointer2 == nullptr ){
	          pointer2 =nullptr;
	      }else if (pointer2-> next != nullptr){
	        pointer2= pointer2->next;
	      }else{
		pointer2=nullptr;
	      }
	    } 
	  while (result_List!=nullptr){
          	cout<<"hello "<<result_List->val<<" "<<endl;
          	result_List=result_List->next;
 	 }


            return result_List; 
    
    }

};




int main (){
 
  class Solution mysol;
 //// mysol.myprintf("oh my god ~~~"); 
  vector <int> res= mysol.node_add(3  ,2,1   );
  
  vector <int> input;
  input.push_back(1);
  input.push_back(1);
  input.push_back(7);
  vector <int> input2;
  input2.push_back(1);
  input2.push_back(2);
  input2.push_back(3);

  struct ListNode l1_nodes[input.size()];
  struct ListNode l2_nodes[input2.size()];
  
  for (int  i =0 ; i < input.size(); i++){  
  	l1_nodes[i] = mysol.node_creating(input[i] , NULL);
  }
  for (int i=0; i < input.size()-1 ; i++ ){
        l1_nodes[i].next=&l1_nodes[i+1] ; 
  }
  for (int i  =0 ; i <input2.size() ; i++ ) {
  	l2_nodes[i] = mysol.node_creating(input2[i] , NULL);
  }

  for (int i =0 ; i <input2.size()-1 ; i++){
        l2_nodes[i].next=&l2_nodes[i+1] ;
  }

  struct ListNode *temp_iter;
  temp_iter = mysol.addTwoNumbers(l1_nodes , l2_nodes);
//  temp_iter =mysol.result_List;
  while (temp_iter!=nullptr){
	  cout<<"AAAA "<<temp_iter->val<<" "<<endl;
          temp_iter =temp_iter->next;
// tempv=temp1->val;
//        cout<<tempv<<endl;
  }





  return 0;
  int tempv= l1_nodes->val;
  std::cout <<tempv<<std::endl;
  struct ListNode *temp1  ;
  temp1=l1_nodes;;
  while (temp1->next!=nullptr){
	  temp1 =temp1->next;
	  tempv=temp1->val;
//	  cout<<tempv<<endl;
  }

  temp1=l2_nodes;
  cout<<temp1->val<<endl;
  while (temp1->next!=nullptr){
	  temp1=temp1->next;
	  tempv=temp1->val;
//	  cout<<tempv<<endl;

  }

  int length_1=input.size();
  int length_2=input2.size();
  int times_of_operations=0;
  if ( length_1 >= length_2){
	  times_of_operations=length_1;
  }else{
	  times_of_operations=length_2;
  }




  cout<<res[0]<<" "<<res[1]<<endl;
  cout<<"hello world \n";	

  return 0;

}

