the logic is based on this article :


logic is the following  


  a b  c d e 



 we need to find the  smallest digid from  the  righteest  



start from :
       V 
 a b c d e 
  

 now compare d ane e 

 if e > d  swap and sort  from d to end  that is the smallest permutation 

 if not 


     V
 a b c d e 


if  e <c   swap  and get the digits  a b e d c  then sort d c  

if not 
   conpare d and c  
   if  d< c swap and get   a b d c e  then sort c and e 

   if not move on the next digit 

  V
a b  c d e 
  compare b and e    not match compare b and d  if not matche compare c and b   if not match next digit ,
  if one of the above was matched  just swap and sort the reminding 


V
a b c d e 
  do the same procedure as the above  if still there is  no match that means a b c d e is  the largest number  please sort the whole digite and we get the answer 
  thate si e d c b a 





   



