#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
//#define  DEBUG   NULL
class Solution {
  public:
     int fourSumCount(    vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4   ) {
       unordered_map<int ,int> AB;
       unordered_map<int, int> CD;
       for (int i=0 ; i <nums1.size() ; i++){
         for (int j=0 ; j <nums2.size() ; j++){
	   AB[nums1[i] + nums2[j]] +=1;
	   CD[nums3[i] + nums4[j]] +=1;
	 }
       }
       int res=0;
       for ( auto iter :AB){
	 res = res + iter.second*CD[ -1*iter.first];
       }
      return res;
    }
};


int main (){

//    vector<int> v1 = {-1,0,1,2,-1,-4};
//  vector<int> v1 = { -4,-2 ,-2 ,-1,-1,0,1,1,2,4};
  vector<int> v1 = { 1  ,2};
  vector<int> v2 = { -2,-1};
  vector<int> v3 = { -1,2};
  vector<int> v4 = { 0,2};


  class Solution mysol;

  int result;
  vector <int> c={1,2,3,4,5};
  result=mysol.fourSumCount(v1 , v2,v3,v4 );

  cout<<result<<endl;

  return 0;

}

