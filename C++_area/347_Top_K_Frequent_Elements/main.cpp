// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
struct element{
  int value;
  int times;
};
struct compare{
  public:
  bool operator()(element & a,element & b) // overloading both operators 
  {
      return a.times < b.times; // if you want decreasing order;(i.e decreasing for maxPQ)
   }
};
class Solution{
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map <int , int > m;
      for (int i=0 ; i < nums.size();  i++){
	m[nums[i]]++;
      }
      priority_queue <element ,  vector <element > ,  compare > max_heap;
      struct element Temp;
      for (unordered_map<int,int>::iterator  it=m.begin() ; it != m.end() ; it ++){
	Temp.value=it->first;
	Temp.times=it->second;
	max_heap.push(Temp);
      }
      vector <int > result;
      for (int i =0 ; i < k  ; ++i){
	result.push_back(max_heap.top().value);
	max_heap.pop();
      }
      return result;
      /*
      while (!max_heap.empty()){
	cout<<"the most times values  is "<<max_heap.top().value<<" the times of that values is "<<max_heap.top().times<<endl;
        max_heap.pop();
      }

     for (int  i=0; i < result.size() ; i ++){
        cout<<"index is "<<i<<" times is "<<result[i]<<endl;
      }

      */
    }
};

int main() {
  class Solution mysolution;
  vector< int > A1={1,1,1,1,2,3,3,3,3,4,5,6,7,8,8,8,8,8,8,8,8} ;


  vector <int >ans;
   ans=  mysolution.topKFrequent(A1, 3);
   for (int i=0 ; i < ans.size();  ++i){

     cout<<ans[i]<<" ";
   }

  return 0;

}  




