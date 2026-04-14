// Time  : O(2^N)
// Space : O(N)
// Where N is the string length
#include <bits/stdc++.h>
using namespace std;

void printSubsequenceHelper(string s, int i, string output){
    if(i==-1){
        cout << output << endl;
        return;
    } 
    
    printSubsequenceHelper(s, i-1, output+s[i]);
    printSubsequenceHelper(s, i-1, output);
}

void printSubsequence(string s){
    
    int size = s.size();
    string output = "";
    
    printSubsequenceHelper(s, size-1, output);
}



int main() 
{
  
    string s = "abc";
    printSubsequence(s);
    
    
    return 0;
}