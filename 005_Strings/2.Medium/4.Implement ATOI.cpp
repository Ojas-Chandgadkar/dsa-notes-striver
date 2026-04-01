// Implement the myAtoi(string s) function, 
// ATOI means 'ASCII to Integer'
// which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// 1. Read in and ignore any leading whitespace.
// 2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// 3.Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// 4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// 5.If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// 6.Return the integer as the final result.
// Note:

// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 
// Example : 
//     Input: s = "4193 with words"
//     Output: 4193
//     Explanation:
//     Step 1: "4193 with words" (no characters read because there is no leading whitespace)
//             ^
//     Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
//             ^
//     Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
//                 ^
//     The parsed integer is 4193.
//     Since 4193 is in the range [-231, 231 - 1], the final result is 4193.


class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;
        int isPositive = true;
        long result = 0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') isPositive = false;
            i++;
        }   
        for(i; i<n && (s[i]-'0'>=0 && s[i]-'0'<=9); i++){
            int digit = s[i] - '0';
            result = result*10 + digit; 
            if(result<INT_MIN || result>INT_MAX) break;
        } 

        (isPositive)? : result = -result;

        if(result > INT_MAX) return INT_MAX;
        else if(result < INT_MIN) return INT_MIN;
        return result;
        
    }
};