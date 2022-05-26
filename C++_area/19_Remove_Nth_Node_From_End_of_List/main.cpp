#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head->next==nullptr and n==1){
            
            return nullptr;
        }
        
        ListNode * end=nullptr;
        ListNode * iter=nullptr;
        iter=head;
        int total=0;
        while( iter ){
         
            total+=1;
            std::cout<<iter->val<<endl;
            if (iter->next !=nullptr){
                iter=iter->next;   
            }else{
                end=iter;
                break;
            }

        }       

        cout<<"total" <<total<<endl;
        
        int index = total -n;
        if  (index ==0 ){
            head=head->next;    
            return head;
            
        }
        
        iter=head;
        for (int i=0  ; i <index-1; i++){
            iter=iter->next;            
        }
        iter->next=iter->next->next;        
        return head;

    }
};




int main (){


  return 0;

}

