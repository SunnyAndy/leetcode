#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
class MedianFinder  {
  public:
    priority_queue <int,  vector <int> ,   less <int> >  max_heap ;  // right heap 
    priority_queue <int ,  vector <int > , greater <int>> min_heap  ;  // left heap 
    double  median=0;
    MedianFinder() {
    }
    void addNum(int num) {
      double med = findMedian();
      if (num  > med ){
	min_heap.push(num);
      }else {
	max_heap.push(num);
      }

      if( min_heap.size() > max_heap.size()){
	int n= min_heap.top();
	min_heap.pop();
	max_heap.push(n);
      }else if (max_heap.size () >  ( min_heap.size()+1) ){
	int n=max_heap.top();
	max_heap.pop();
	min_heap.push(n);
      }
    }

    double findMedian(bool flag=false) {
      if (max_heap.size() ==0){
	return  median;
      }
      if (max_heap.size() == min_heap.size()){
	this->median= (double) (( (double)max_heap.top()+  (double )  min_heap.top())/2);
      }else{
	this->median= max_heap.top();
      }

      return this->median;
    }
};


/*
   template<class T>
   void printQueue(T& q)
   {
   while (!q.empty())
   {
   cout << q.top() << endl;
   q.pop();
   }
   }

   void SamplePriorityQueue()
   {
   auto compare = [](int lhs, int rhs)
   {
   cout<<" lhs "<<lhs;
   return lhs > rhs;
   };

   std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

   for(int n : {1,8,5,6,3,4,0,9,7,2})
   q.push(n);


   printQueue(q);

   std::priority_queue<int, std::vector<int>, std::less<int> > q;
   for(int n : {1,8,5,6,3,4,0,9,7,2})
   q.push(n);
   printQueue(q);  
   }

 */






int main (){
  class MedianFinder  sol;
  sol.addNum(6) ;
  sol.addNum(8) ;
  sol.addNum(3) ;
  sol.addNum(4) ;
  sol.addNum(4) ;
  sol.addNum(5) ;
  //cout<<sol.findMedian(true)<<endl;
  cout<<sol.findMedian(true);//<<endl;

  sol.addNum(8) ;
  sol.addNum(3) ;
  sol.addNum(9) ;

  cout<<sol.findMedian(true);//<<endl;
  //SamplePriorityQueue();


  return 0;
}
