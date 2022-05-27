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
    ListNode* swapPairs(ListNode* head) {        
        if (head==nullptr){         
            return head;
        } 
        if (head->next==nullptr ){
            return  head;
        }

        ListNode * first =nullptr;
        ListNode * second=nullptr;
        first=head;
        second=head->next;
        int temp_val;
        while( second ){
            temp_val=first->val;
            first->val=second->val;
            second->val=temp_val;
            if(  second->next !=nullptr  ){
                first=second->next;    
                if(first->next !=nullptr){
                    second=first->next;
                    
                }else{
                    break;
                }
                
            }else{
                break;
            }
            
        }

        return head;

    }
};







int main (){


  return 0;

}

