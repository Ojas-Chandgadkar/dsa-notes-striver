// Time  : O(2^N)
// Space : O(N)
// where N is 
class Solution {
public:

    void parGenerator(int i, int N, int cntLeftBrack, int cntRightBrack, vector<char> path, vector<string> &res){
        
        if(cntRightBrack > cntLeftBrack) return;
        if(i == N){
            if(cntLeftBrack == cntRightBrack){
                string str;
                for(auto ch : path) str += ch;
                res.push_back(str);
            }
            
            return;
        }

        path.push_back('(');
        parGenerator(i+1, N, cntLeftBrack+1, cntRightBrack, path, res);
        path.pop_back();

        path.push_back(')');
        parGenerator(i+1, N, cntLeftBrack, cntRightBrack+1, path, res);
        path.pop_back();
    }

    vector<string> generateParenthesis(int n) {

            vector<string> res;
            vector<char> path;
            parGenerator(0, 2*n, 0, 0, path, res);

            return res;
    }
};

/*
Output, 
For N = 3, 

((()))
(()())
(())()
()(())
()()()
*/