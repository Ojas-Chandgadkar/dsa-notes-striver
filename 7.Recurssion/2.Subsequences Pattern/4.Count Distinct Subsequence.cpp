/*
You are given two strings 'A' and 'B' of length 'N' and 'M' respectively.
Return the string that has more distinct subsequences, if both strings have the same number of distinct subsequences, then return 'A'.

For Example:
    'N' = 2, 'M' = 2, 'A' = "ab", 'B' = "dd".
    'A' has distinct subsequences = ["a", "b", "ab"].
    'B' has distinct subsequences = ["d", "dd"].
    So our answer is "ab".
*/


// NOT OPTIMAL ==============================================================================================================
void helper(string &str,int i, int N, string path, vector<string> &res){

    if(i == N){
        if(find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }
        return;
    }

    helper(str, i+1, N, path, res);

    path += str[i];
    helper(str, i+1, N, path, res);
    path = path.substr(0, i);
}

int getDistinct(string &str, int N){
    vector<string> res;
    string path;
    helper(str,0, N, path, res);

    return res.size();
}

string moreSubsequence(int n, int m, string a, string b)
{
    int distinct_a = getDistinct(a, n);
    int distinct_b = getDistinct(b, m);

    if(distinct_a >= distinct_b) return a;
    return b;
}


// OPTIMAL ==============================================================================================================
void helper(string &str, int i, int N, string path, unordered_map<string, bool> &distinct){

    if(distinct[path]) return;
    if(!distinct[path] && path!="") distinct[path] = true;
    if(i == N) return;

    path += str[i];
    helper(str, i+1, N, path, distinct);
    path.pop_back();

    helper(str, i+1, N, path, distinct);
    
}

int getDistinct(string &str, int N){
    unordered_map<string, bool> distinct;
    string path = "";

    helper(str, 0, N, path, distinct);

    return distinct.size();
}

string moreSubsequence(int n, int m, string a, string b)
{
    int distinct_a = getDistinct(a, n);
    int distinct_b = getDistinct(b, m);

    if(distinct_a >= distinct_b) return a;
    return b;
} 