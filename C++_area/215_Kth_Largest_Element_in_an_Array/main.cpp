#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
      sort (nums.begin(), nums.end());
      int n=nums.size();
      cout<<"kth largest value is "<<nums[n-k]<<endl;
      return nums[n-k];
        
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

      priority_queue<int>pq;
      
      int n=nums.size();
      for(int  i=0 ; i < n ; i ++){
	pq.push(nums[i]);
      }

      int f=  k-1;
      for(int i=0; i <f ; i++){
	pq.pop();
      }
      cout<<"kth largest value is "<<pq.top()<<endl;

      return pq.top();
        
    }
};






int main (){
  class Solution sol;
  vector <int> input={ 3,2,3,1,2,4,5,5,6, };

  cout<<sol.findKthLargest( input, 2)<<endl;
  return 0;
}
