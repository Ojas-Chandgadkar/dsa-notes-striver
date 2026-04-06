class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longest = 0;
        int n = s.size();

        vector<bool> asciMap(256, false);

        int i = 0;
        int j = 0;
        for(j; j<n; j++){
            int curr = s[j];

            if(!asciMap[curr]){
                asciMap[curr] = true;
            }
            else if(asciMap[curr]){
                while(asciMap[curr]){
                    asciMap[s[i]]  = false;
                    i++;
                }
                asciMap[curr] = true;
            }

            longest = max(longest, j-i+1);
        }


        return longest;
    }
};