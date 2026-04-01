/*
Removing outermost paranthesis for every valid primitive parenthesis, like,
Input:: "(()())(())"
Output: "()()()"
Explaination : The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
*/ 


class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res = "";
        int n = s.size();

        int runningBracketCount = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') runningBracketCount++;
            else if(s[i]==')') runningBracketCount--;
            
            if((runningBracketCount!=1 || s[i]!='(') && runningBracketCount!=0){
                res += s[i];
            }
        }

        return res;

    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize 'res=""', which will store the answer.
// Intialize 'runningBracketCount=0', which keeps track brackets.
// We must not include outer brackets after primititive decomposition.
// The 'runningBracketCount' must be updated for every char.
// For every char the 'runningBracketCount' has some hidden info in it :
//		if(runningBracketCount==0), it is the outmost ( bracket, which must not be considered in 'res'
//		if(runningBracketCount==1 && s[i]!='('),it is the outmost ) bracket, which must not be considered in 'res'
// Everything else besides the above, will be added in 'res'.
// Return 'res' at end.