step 1 

read the input X to be an integer 

transfer the int to string 

step 2 

reverse each alpha


step 3

check the reversed string is  in the int  range ( -2^31  ~ 2^31-1 ) 


step 4 

stoi to int 


a faster  solution from web site 

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
}; 
