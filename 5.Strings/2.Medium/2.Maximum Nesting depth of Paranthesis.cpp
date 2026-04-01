class Solution {
public:
    int maxDepth(string s) {
        
        int n = s.size();

        int maxDepth = 0;
        int runningBracketCount = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                runningBracketCount++;
                maxDepth = max(maxDepth, runningBracketCount);
            }
            else if(s[i]==')'){
                runningBracketCount--;
            }
        }

        return maxDepth;
    }
};