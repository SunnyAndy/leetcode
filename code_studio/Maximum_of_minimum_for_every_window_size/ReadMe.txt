

question : 

https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website 




using the binary search method to fetch the final value 

span the each of the array and 





 This question has three idea 

 first if  we can find out the range of the element that the element would be pick up  in that the range or belowe  is the candiate 


 for example 
 10 20 30 50 10 70 30

 for the first element  
 10 would be pick up as it is the smallese 
 in range 1 --> min  {10}   
 in range 2 --> min {10,20}  
 in range 3 --> min {10,20,30}
 in rnage 4 --> min {10, 20,30,50}
 in range 5 --> min {10,20,30,50,10}
 in range 6 --> min {10,20,30,50,10,70} 
 in range 7 --> min {10,20,30,50,10,70,30}  

 there is no  element les than the 10 on the left side    left[0]  is -1 
 same  as the right side  right [0] = 7 
 
  we can create for  a array for each element 
  left= {-1 0 1 2 -1 4 4}
  right={ 7 4 4 4  7 6 7}


  if 10  is going to be pick up the windows is less equal  than  7 ( 7--1-1)  
  if 20  is going to be pick up the windows is less equal  than  3 ( 4- 0-1) 
  if 30  is going to be pick up the windows is less equal  than  2 ( 4- 1-1) 
  if 50  is going to be pick up the windows is less equal  than  1 ( 4- 2-1) 
  if 10  is going to be pick up the windows is less equal  than  7 ( 7--1-1) 
  if 70  is going to be pick up the windows is less equal  than  1 ( 6- 4-1) 
  if 30  is going to be pick up the windows is less equal  than  2 ( 7- 4-1) 
  

  now we need to calculate in different windows size what is the max  value 


  for those i whose right-left eqals to "windows size"  choose the maximun 

  beacuse the tha i has  the mima  windows size that value would be choosen so we need to compare the value to those who has the same window size 
  for each i in right-left    result[i] = max {result[i] , array[i]  

  third   the span size means  less than the  windows size the a[i] is potentially to be pick up 
  say when windows size is 7 "10 (i=1)" was picked size is 6 "10 (i=1)" was also picked up 

  so from 
  result [n-1] = max {result [n], result[n-1]} 
  a[6] it self was pickked or a[7]  which one is max whould be the answer 


    

  






