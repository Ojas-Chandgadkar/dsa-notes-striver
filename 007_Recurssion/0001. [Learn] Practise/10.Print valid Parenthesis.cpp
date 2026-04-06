// Time  : O(2^N)
// Space : O(N)
#include<bits/stdc++.h>
using namespace std;

void printHelper(int start, int end, int cntLeftPar, int cntRightPar, string output){
    
    if(cntRightPar < cntLeftPar) return;
    if(start==end){
        if(cntRightPar==cntLeftPar) cout << output << endl;
        return;
    }
    
    printHelper(start+1, end, cntLeftPar, cntRightPar+1, output+'(');
    printHelper(start+1, end, cntLeftPar+1, cntRightPar, output+')');
    
}
void printValidParenthesis(int n){
    printHelper(0, 2*n, 0, 0, "");
}

int main(){
    
    int n = 3;
    printValidParenthesis(n);
  
    return 0;
}


/*
Output : 

((()))
(()())
(())()
()(())
()()()
*/