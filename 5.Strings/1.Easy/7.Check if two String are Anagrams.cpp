// Anagram : A word/phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

class Solution {
public:
    bool isAnagram(string s, string t) {
    
        vector<int> alphabet_count(27);
        int s_size = s.size();
        int t_size = t.size();

        for(int i=0; i<s_size; i++){
            alphabet_count[s[i]-96]++;
        }

        for(int i=0; i<t_size; i++){
            alphabet_count[t[i]-96]--;
        }

        for(auto i : alphabet_count){
            if(i!=0) return false;
        }

        return true;
    }
};