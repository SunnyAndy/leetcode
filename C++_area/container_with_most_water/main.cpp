#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;


class Solution {
  public:
    int maxArea(vector<int>& height) {
      int left=0;
      int right = height.size()-1; 
      int max_area=-10000;
      int temp_area=0;
      while (left != right ){
	temp_area=((right+1)-(left+1))*min(height[left], height[right]);
	if(temp_area > max_area){
	  max_area=temp_area;
	}
	if (height[left] < height[right] ) {
	  left +=1;
	}else{
	  right -=1;
	}

      }
      return max_area;
    }
};





int main (){


  class Solution mysol;
  vector<int> height{1,8,6,2,5,4,8,3,7};
  cout<<mysol.maxArea( height);  // testing  case 

  return 0;

}

