#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class Solution{
  public:
    int count_for_smaller (vector <int > &row ,   int val     ){
      int l = 0, h = row.size() - 1;
      while (l <= h)
      {
	int md = (l + h) >> 1;
	if (row[md] <= val)
	{
	  l = md + 1;
	}
	else
	{
	  h = md - 1;
	}
      }
      return l;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

      int half_num=0;
      int total_element_num=nums1.size()+nums2.size();
      half_num=total_element_num/2;
      double ret;
      int min=1;
      int max=1e6;
      while (max >= min){
	int mid =  (min+max)>>1;
	int less_number=0;
	//        for (int i=0  ; i < nums1.size()  ; i ++){
	less_number += count_for_smaller ( nums1 , mid);
	less_number += count_for_smaller ( nums2 , mid);
	//      }
	//cout<<"max "<<max<<" min "<<min<< " mid "<<mid<<" number for the less "<<less_number<<endl;
	if (less_number >   half_num  ){
	  max=mid-1;
	}else {
	  min=mid+1;
	}
      }
      ret= min;

      if((total_element_num)%2==0){
	min=1;
	max=1e6;
	while (max >= min){
	  int mid =  (min+max)>>1;
	  int less_number=0;
	  less_number += count_for_smaller ( nums1 , mid);
	  less_number += count_for_smaller ( nums2 , mid);
	  if (less_number >=   (half_num)  ){
	    max=mid-1;
	  }else {
	    min=mid+1;
	  }
	}
	return (min+ret)/2;
      }else {


	return ret;

      }
      return (double) min;


#ifdef DEBUG
      cout<<"testing"<<endl;
#endif
    }
};


int main (){
  class Solution sol;
  vector <int> input={  1, 10 ,21  , 33};
  vector <int> input2={  1 ,2 , 5, 7};
  //  1 1  2 5 7  18 21  
//  cout<<"  1 1  2 5 7  18 21 33 "<<endl;

  cout<<  sol.findMedianSortedArrays( input , input2) <<endl ;
  return 0;
}
