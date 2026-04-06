/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.A mapping of digits to letters (just like on the telephone buttons) is given below. (google --> keypad image)
Note that 1 does not map to any letters.

Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/
class Solution {
public:

    void helper(string &num, int i, int &N, string &path, unordered_map<int, vector<char>> &mp, vector<string> &res){
        if(i==N){
            res.push_back(path);
            return;
        }

        for(int index=0; index<mp[num[i]-'0'].size(); index++){
            path += mp[num[i]-'0'][index];
            helper(num, i+1, N, path, mp, res);
            path = path.substr(0, path.size()-1);
        }
    }

    void get_combinations(string &num, unordered_map<int, vector<char>> &mp, vector<string> &res){

        int N = num.size();
        if(N == 0) return;
        string path;

        helper(num, 0, N, path, mp, res);
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        unordered_map<int, vector<char>> keyMap;
        keyMap[2] = {'a', 'b', 'c'};
        keyMap[3] = {'d', 'e', 'f'};
        keyMap[4] = {'g', 'h', 'i'};
        keyMap[5] = {'j', 'k', 'l'};
        keyMap[6] = {'m', 'n', 'o'};
        keyMap[7] = {'p', 'q', 'r', 's'};
        keyMap[8] = {'t', 'u', 'v'};
        keyMap[9] = {'w', 'x', 'y', 'z'};

        get_combinations(digits, keyMap, res);
        return res;
    }
};