// NOT OPTIMAL 

int countSubStrings(string str, int k) 
{
    int substrCount = 0;
    int n = str.size();

    for(int i=0; i<n; i++){
        unordered_set<char> alpha;
        for(int j=i; j<n; j++){
            alpha.insert(str[j]);
            int alphaSize = alpha.size();

            if(alphaSize == k) substrCount++;
            else if(alphaSize > k) break;
        }
    }

    return substrCount;
}


// OPTIMAL (Without DP)

int atMost(string s, int k){

    int substrCntr = 0;
    int size = s.size();
    vector<int> alpha(26,0);

    int i = 0;
    int j = 0;
    int distinctCntr = 0;
    while(j<size){
        int curChar = s[j] - 'a';
        alpha[curChar]++;
        if(alpha[curChar]==1) distinctCntr++;

        while(distinctCntr>k && i<j){
            int temp = s[i]-'a';
            alpha[temp]--;
            if(alpha[temp]==0) distinctCntr--;
            i++;
        }

        if(distinctCntr <= k) substrCntr += j-i+1;
        
        j++;
    }

    return substrCntr;

    
}

int countSubStrings(string str, int k) 
{
    return atMost(str, k) - atMost(str, k-1);
}
