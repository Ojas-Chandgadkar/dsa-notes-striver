/*

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.

Example 1:
    Input: k = 3, n = 7
    Output: [[1,2,4]]
    Explanation: 1 + 2 + 4 = 7. (There are no other valid combinations)
*/

class Solution {
public:

    void getCombination(int i, int target, int mustSize, vector<int> &path, vector<vector<int>> &res){
        if(target==0 && mustSize==0) res.push_back(path);
        if(target<=0 || mustSize<=0 || i==10) return; 

        path.push_back(i);
        getCombination(i+1, target-i, mustSize-1, path, res);
        path.pop_back();

        getCombination(i+1, target, mustSize, path, res);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        getCombination(1, n, k, path, res);

        return res;
    }
};