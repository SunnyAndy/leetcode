#include<bits/stdc++.h>
using namespace std;

class Min_Heap
{
  public:
    vector <int> data_array;
    int heap_init(int n){
      for (int i=0 ; i < n ; i++){
	data_array.push_back(i);
      }
      return 0;
    }

    void heap_print_all(){
      for(int i=0;  i < data_array.size(); i++){
	cout<<data_array[i]<<endl;
      }
    }
    void heap_print_min(){
      if (data_array.size()==0){
	cout<<"empty heap \n";
      }else{
	cout<<data_array[0]<<endl;
      }
    }
    int get_parent_i( int position){
      if (position==0){
	cout<<"I am root no parent"<<endl;
	return 0;
      }else{
	int par= (position-1)/2;	
	return par;
      }
    }
    int get_left_child_i( int  position){
      return  (position*2+1);
    }
    int get_right_child_i(int position){
      return  (position*2+2);
    }

    void swap(int post1, int post2 ){
      int  temp= data_array[post1];
      data_array[post1]=data_array[post2];
      data_array[post2]=temp;
    }
    int heap_delete_heapify( int post_to_heapify){
      int left_child_i;
      int right_child_i;
      if ( (data_array.size()-1) < (post_to_heapify*2+1)  ){   //  I am left node node child   no need to heapfy
	return 0; 
      }else if(data_array.size()-1 == (post_to_heapify*2+1) ){  //   only have the left child   // need ot heapify 
	left_child_i = get_left_child_i(post_to_heapify);
	if (  data_array[left_child_i] < data_array[post_to_heapify] ){
	  swap( post_to_heapify , left_child_i);
	  heap_delete_heapify(left_child_i);
	}
      }else{
	left_child_i=get_left_child_i(post_to_heapify);
	right_child_i=get_right_child_i(post_to_heapify);
	int min_i;
	if (data_array[left_child_i] < data_array[right_child_i]){
	  min_i= left_child_i;
	}else{
	  min_i=right_child_i;
	}
	if(data_array[min_i] < data_array[post_to_heapify]  ){
	  swap( min_i, post_to_heapify   );
	  heap_delete_heapify(min_i); 
	}else {
	  // no need to  heapify stop
	  return 0 ;
	}
      }
      return 0;
    }
    int heap_delete(){    //  delete the root is the basic ideoloagy 
      if(data_array.size()==0){
	cout<<"no more data to delete  on heap"<<endl;
      }else if (data_array.size()==1){
	cout<<"data "<<data_array[0]<<" was removed "<<endl;
	data_array.pop_back();
      }else {
	cout<<"data "<<data_array[0]<<" was removed "<<endl;
	data_array[0]=data_array.back();
        data_array.pop_back();
	heap_delete_heapify(0);
      }
    return  0 ;  
    }
    int heap_insert_heapify(int post_to_heapify){
      int parent_i;
      if(post_to_heapify==0){  // root no need to heapify 
	return 0;
      }else{
	parent_i = get_parent_i(post_to_heapify);
	if (data_array[parent_i] > data_array[post_to_heapify]  ){
	  swap( parent_i , post_to_heapify  );
	  heap_insert_heapify(parent_i);
	}else{
	  return 0;
	}
      }
      return 0; // not implement 
    }
    int heap_insert( int val   ){
      data_array.push_back(val);
      heap_insert_heapify(data_array.size()-1);
      return  0 ;  // not implement 
    }

};


int main() {
  cout<<"test case:";
  int t;
  cin>>t;
  //  cout<<t<<endl;
  while(t--){
    int n; // heap _default size
    cout<<"case 1 default size :";
    cin>>n;
    //  cout<<n<<endl;
    Min_Heap  ob ; 
    ob.heap_init(n);
    ob.heap_print_all();
    ob.heap_print_min();
    ob.heap_delete();
    ob.heap_print_all();
    ob.heap_print_min();
    cout<<"insertion "<<endl;
    ob.heap_insert(6);
    ob.heap_insert(9);
    ob.heap_insert(10);
    ob.heap_print_all();
    ob.heap_print_min();
    /*
    //    int A[n];
    for(int i=0;i<n;i++){
    cin>>A[i];
    }
    int m;
    cin>>m;
    cout << ob.findPages(A, n, m) << endl;
     */
  }
  return 0;
}







