


main idea is coming  from the youtuber 
https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51


main idea 


a string "AAABBBBCCCDDD" 


could be divide the two part 
the formmer part (string[0:N] and string[N+1:end]) N could be  from 1 to  the length of String



our solution 

we  literatirely divide the string from N=1 to N=lengthofString 
and check if the former part string is palidrome the thorow the latter part to our  function 
till the  latter part is empty 

that we can say , we find out a partiton method to  make all  small strings  palidrom 


example 
step one:
A, AAABBBBBCCC

A is palidrom now check AAABBBBBCCC 
    A,AABBBBBCCC 
        A,ABBBBBCCC
	   A,BBBBBCCC 
	       . . . . .. . 
               

AA, AABBBBBCCC 
    A, ABBBBBBCCC
        







