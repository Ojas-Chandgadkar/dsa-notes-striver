// Time  : O(N)
// Space : O(N)
#include<bits/stdc++.h>
using namespace std;

string removeAllOfChar(string s, char x){
    
    int len = s.size();
    if(len==0) return s;
    
    if(s[0]==x) return removeAllOfChar(s.substr(1), x);                     // skips current char
    else return s[0] + removeAllOfChar(s.substr(1), x);                     // includes current char
}

int main(){
    
    string s = "cabcca";
    
    string res = removeAllOfChar(s, 'c');
    cout << res;
    
    return 0;
}