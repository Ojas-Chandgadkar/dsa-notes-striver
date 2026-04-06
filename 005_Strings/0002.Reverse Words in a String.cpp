class Solution {
public:
    string reverseWords(string s) {
        
        string res = "";

        int n = s.size();
        string currWord = "";

        for(int i=0; i<n; i++){
          if(s[i]!=' '){
            currWord += s[i];
          }
          else if(s[i]==' '){
            if(res ==""){
              res = currWord;
              currWord = "";
            }
            else if(currWord!=""){
              res = currWord + " " + res;
              currWord = "";
            }
          }
        } 

        if(currWord!=""){
            if(res=="") res = currWord;
            else res = currWord + " " + res;
        }

        return res;
    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
//Iterate the string and keep on adding to form a word
//If empty space is encountered then add the current word to the result
//If not empty string then add to the result(Last word is added)