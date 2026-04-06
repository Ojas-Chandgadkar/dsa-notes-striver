// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            char curr = s[i];

            if(curr=='(' || curr=='{' || curr=='['){
                st.push(curr);
            }
            else{
                if(st.empty()) return false;
                
                char top = st.top();

                if((s[i]==')' && top=='(') || 
                    (s[i]=='}' && top=='{') ||
                    (s[i]==']' && top=='[')){
                        st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};