// You are given a string s and an integer k. 
// You can choose any character of the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.


// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.



class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longest;
        int size = s.size();
        unordered_map<char, int> WindowCharCntr;

        int i = 0;
        int j = 0;
        int maxFreq = 0;
        while(j<size){
            char currChar = s[j];
            WindowCharCntr[currChar]++;
            maxFreq = max(maxFreq, WindowCharCntr[currChar]);

            while((j-i+1)-maxFreq > k){
                WindowCharCntr[s[i]]--;
                i++;
            }
            
            longest = max(longest, j-i+1);            
            j++;
        }

        return longest;
    }
};

