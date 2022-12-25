question : 


https://leetcode.com/problems/roman-to-integer/ 


main  logic :

I             1
V             5
X             10
L             50
C             100
D             500
M             1000

MCMXCIV
V--> V is start point

result  += V  (5)

MCMXCIV
I I<V  -->
result = result -I  (1)


MCMXCIV
C --> C >I

result += C  (100)


MCMXCIV
X --> X < C

result -=X  (10)

MCMXCIV
M --> M >X

result += M (1000)


MCMXCIV
C---> C < M

result -= C (100)



MCMXCIV
M ---> M >C
result += M (1000)


1+100-10+1000-100+1000 =1994


 






