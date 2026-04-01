// Given an integer x, return true if x is a palindrome, and false otherwise.


class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;

        int temp = x;
        long long revNum = 0;
        while(temp != 0){
            revNum = (revNum*10) + temp%10;
            temp /= 10;
        }

        if(revNum == x) return true;
        return false;
        
    }
};