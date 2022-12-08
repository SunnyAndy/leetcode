// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  int value;
  node* next;    // next to the tail 
  node* prev;    // prev to the head
};
class LRU_queue{
  public:
    node head;
    node tail;
    LRU_queue(){  // constructor 
      head.next=&tail;
      head.prev=NULL;
      tail.prev=&head;
      tail.next=NULL;
    }
  node * create_node( int new_key , int new_value   ) {
    node *new_node= new  node;
    new_node->key=new_key;
    new_node->value=new_value;
    return new_node;
  }
  void add_node( node * new_node  ){
    new_node->next=head.next;
    head.next->prev=new_node;  
    head.next=new_node;
    new_node->prev=&head;
  }
  void delete_node(node * del_node   ){
    del_node->prev->next=del_node->next;
    del_node->next->prev=del_node->prev;
//    delete del_node;    
  }
};


class LRUCache{
  public:
    int max_len;
    unordered_map<int  , struct node *> my_cache;
    class LRU_queue lru_q;
    LRUCache(int capacity) {
      max_len=capacity;
    }
    int get(int key) {
      if (my_cache.find(key)!=my_cache.end()){
	int res=(my_cache[key])->value;
//	struct node * new_node1 = lru_q.create_node(key, res);  //  should not new a one ?
	struct node * new_node1 = my_cache[key];
	lru_q.delete_node( new_node1 );
	lru_q.add_node(new_node1);
//	my_cache[key]=new_node1;
	return res;
      }else{
	return -1;
      }
    }
    void put(int key, int value) {
      // step full or not 
      // if full
      if (my_cache.size()==max_len){
	//hit 
       if (my_cache.find(key)!=my_cache.end()){
//	  struct node * new_node1 = lru_q.create_node(key, value);  // should not new ?  
	  struct node * new_node1 = my_cache[key];
	  new_node1->value=value;  
	  lru_q.delete_node( new_node1 );
	  lru_q.add_node(new_node1);
//	  my_cache[key]=new_node1;
	}else{
	  struct node * last_node= lru_q.tail.prev;
	  int last_key=last_node->key;
	  lru_q.delete_node( last_node);
	  struct node * new_node1 = lru_q.create_node(key, value); // new a one 
	  lru_q.add_node(new_node1);
	  my_cache.erase(last_key);
	  my_cache[key]=new_node1;
	}
	// not full 
      }else{
       if (my_cache.find(key)!=my_cache.end()){
	  //struct node * new_node1 = lru_q.create_node(key, value);    // should not new ?
	  struct node * new_node1 = my_cache[key];
	  new_node1->value=value;
	  lru_q.delete_node( new_node1 );
	  lru_q.add_node(new_node1);
//	  my_cache[key]=new_node1;
	}else {  //  not hit
	  struct node * new_node1 = lru_q.create_node(key, value); // new a one 
	  lru_q.add_node(new_node1);
	  my_cache[key]=new_node1;
	}
      }
    }

    /////////////////////////////////
#ifdef DEBUG
    void help(){
      auto iter = my_cache.begin();
      iter++;
      while (iter != my_cache.end()) {
	std::cout << "[ index " << iter->first << ", key "
	  <<iter->second->key<<", value" <<iter->second->value << "]\n";
	++iter;
      }
      cout<<"" << endl;
    }

#endif
    //////////////////////////////////////////////////////
};


int main() {
  class LRUCache mysolution(2);
  mysolution.put(1, 1);
  mysolution.put(2, 2);
  cout<<  mysolution.get(1)<<endl;
  mysolution.put(3, 3);
  cout<<  mysolution.get(2)<<endl;
  mysolution.put(4, 4);
  cout<<  mysolution.get(1)<<endl;
  cout<<  mysolution.get(3)<<endl;
  cout<<  mysolution.get(4)<<endl;
  return 0;

}  

