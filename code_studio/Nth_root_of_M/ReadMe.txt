
quesiton : 
https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website 

key: momenotic imcresing or decresing 


solution idea from :
https://www.youtube.com/watch?v=WjpswYrS2nY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63
the binary search doesn't work 


golden answer using Netown methodn: 
https://zh.wikipedia.org/zh-tw/%E7%89%9B%E9%A1%BF%E6%B3%95 



Newton Raphson Method
Let’s say X is the Nth root of M.
X = M ^ (1 / N)
The above equation can be written as follows:
X ^ N = M
X ^ N - M = 0
Let’s assume F(X) = X ^ N - M
Now we need to find the root of this equation, for which we can use the Newton Raphson method to solve this equation.
In Newton's Raphson method we start with an initial guess value of X (any random initial value is fine) and iterate through a process that takes us towards the actual solution of the equation.
Let’s say X(0) is the initial guess value.
The relationship between the current value of solution value x(k) and the solution of the equation in the next iteration X(K + 1) is as follows:
X(K + 1) = X(K) - F(X(K)) / F'(X(K)), where F'(X(K)) denotes the value derivative of F(X) at X = X(K).                                    ....(1)
In the given case F'(X(k)) = N * X(K) ^ N - 1.
So equation (1) can be written as follows:
X(K + 1) = X(K) - (X(K) ^ N - M) / (N * X(K) ^ N - 1)
X(K + 1) = (X(K) * (N * X(K) ^ N - 1) - X(K) ^ N + M) / (N * X(K) ^ N - 1))
X(K + 1) = (X(K) ^ N * (N - 1) + M) / (N * X(K) ^ N - 1)
So using the above formula to calculate new possible solution value X. Till the gap between X(K + 1) and X(K) become less than 10-7.
When this condition is reached we get our required solution.

