// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the same character, 
// but a character may map to itself. 

    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            
            map<char,char> mp;          // map s to t
            map<char,bool> used;        // mark t as used
            int sSize = s.size();
            int tSize = t.size();

            if(sSize!=tSize) return false;
            for(int i=0; i<sSize; i++){
                char ch1 = s[i];
                char ch2 = t[i];
                auto ch1Itr = mp.find(ch1);
                auto ch2Itr = used.find(ch2);

                if(ch1Itr==mp.end() && ch2Itr==used.end()){
                    mp[ch1] = ch2;
                    used[ch2] = true;
                }
                else if(ch1Itr->second!=ch2){
                    return false; 
                }
                else if(ch2Itr->second!=true){
                    return false;
                }
            }


            return true;
        }
    };