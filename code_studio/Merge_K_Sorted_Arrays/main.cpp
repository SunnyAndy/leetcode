// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node{
  int value;
  int index;
};
struct compare{
  public:
  bool operator()(Node& a,Node& b) // overloading both operators 
  {
      return a.value > b.value; // if you want increasing order;(i.e increasing for minPQ)
//      //return a.w > b.w // if you want reverse of default order;(i.e decreasing for minPQ)
   }
};

class Solution{
  public:
    template<class T>
      void printQueue(T& q)
      {
	while (!q.empty())
	{
	  cout << q.top() << endl;
	  q.pop();
	}
      }
    vector<int> mergeKSortedArrays2(vector<vector<int>>&kArrays, int k){
      if (k==1){
	return kArrays[0];
      }
      priority_queue <Node ,  vector <Node > ,  compare > min_heap2; 
      for (int i=0 ; i <k; i++){
	struct  Node temp;
	temp.value=kArrays[i][0];
	temp.index=i;
	min_heap2.push(temp);
      }

        /*    
      while (!min_heap2.empty()){\
	cout<<min_heap2.top().value<<endl;
        min_heap2.pop();
      }
      vector <int> a;
      return a;
*/
      vector <int >  result ;
      while (!min_heap2.empty ()){
	int val= min_heap2.top().value;
	int in_dex=min_heap2.top().index;
	result.push_back(val ) ;
	min_heap2.pop();
	kArrays[in_dex].erase(kArrays[in_dex].begin());
	if(kArrays[in_dex].size()!=0){
	  struct Node temp2;
	  temp2.value=kArrays[in_dex][0];
	  temp2.index=in_dex;
	  min_heap2.push(temp2);
	}
      }

      /*
      while (!min_heap2.empty()){
	result.push_back(min_heap.top().value);
	min_heap2.pop();
      }*/
//      printQueue(min_heap);

      for (int  i=0; i < result.size() ; i ++){
	cout<<result[i]<<endl;
      }
      return result;

    }
    vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
    {
      // Write your code here.

      if (k==1){
	return kArrays[0];
      }
      priority_queue <int ,  vector <int > , greater <int>> min_heap  ;  // 
      for (int i=0 ; i < k ; i ++){
	for (int j=0 ; j < kArrays[i].size() ; j++){
	min_heap.push(kArrays[i][j] );
	}
      }

      vector <int >  result ;
      while (!min_heap.empty()){
	result.push_back(min_heap.top());
	min_heap.pop();
      }
//      printQueue(min_heap);

      for (int  i=0; i < result.size() ; i ++){
	cout<<result[i]<<endl;
      }
      return result;



    }
};

int main() {
  class Solution mysolution;
  vector <vector <int >> kArray;
  vector< int > A1={3,5,9} ;
  kArray.push_back(A1);
  vector< int > A2={1,2,3,8} ;
  kArray.push_back(A2);


  mysolution.mergeKSortedArrays2( kArray , 2  );
  return 0;

}  




