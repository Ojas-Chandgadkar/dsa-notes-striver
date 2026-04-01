class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, bool> TreeTypeMap;
        int size = fruits.size();

        int maxi = 0;
        int i = 0;
        int j = 0;
        

        for(int j=0; j<size; j++){
            int currTree = fruits[j];

            if(TreeTypeMap.size()<2 && !TreeTypeMap[currTree]){
                TreeTypeMap[currTree] = true;
                maxi = max(maxi, j-i+1);
            }
            else if(TreeTypeMap[currTree]){
                maxi = max(maxi, j-i+1);
            }
            else if(!TreeTypeMap[currTree]){
                TreeTypeMap.clear();
                TreeTypeMap[currTree] = true;
                TreeTypeMap[fruits[j-1]] = true;
                i = j-1;
                while((fruits[i]==fruits[i-1]) && i>0){
                    i--;
                }
                maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
}