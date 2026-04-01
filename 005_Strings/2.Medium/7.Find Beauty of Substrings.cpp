class Solution {
public:

    int beautyOf(vector<int> &a){
        int mostFreq = INT_MIN;
        int leastFreq = INT_MAX;

        for(int i=0; i<26; i++){
            mostFreq = max(mostFreq, a[i]);
            if(a[i]>0) leastFreq = min(leastFreq, a[i]);
        }

        return mostFreq - leastFreq;
    }

    int beautySum(string s) {
        
        int beautySum = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            vector<int> alpha(26,0);
            for(int j=i; j<n; j++){
                alpha[s[j]-'a']++;

                beautySum += beautyOf(alpha);
            }
        }

        return beautySum;
    }
};