// Example, 
//      Input: strs = ["flower","flow","flight"]
//      Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res = "";
        int n = strs.size();
        
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[n-1];
        int minLen = min(first.size(), last.size());
        for(int i=0; i<minLen; i++){
            if(first[i]!=last[i]) return res;
            else res += first[i];
        }
    

        return res;
    }
};