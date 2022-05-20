


given a string  abcdefghijk rowNums=4 

 
a    g       -->  string index is "0 6 12"   r + 2*rowNums -2 (for reason that bottom and up reduce two )
       
b  f h       --> string index  is "1  5 7  12  14"  r  -->    r+2*rowNums -2 -2*r  -->   r+2*rowNums-2 --> .... 

c  e i  k     --> same as the above  

d    j       --> same as the first line 


for r  from 1~ nubRows

for r+displace (2*numRows -2) if r != 0 or end   [2*numRows-2-2*r , 2*numRows -2 ]  



more detail is in https://www.youtube.com/watch?v=Q2Tw6gcVEwc&t=623s  




