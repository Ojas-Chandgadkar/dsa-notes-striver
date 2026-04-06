class Solution {
public:
    bool rotateString(string s, string goal) {
    
        if(s.size()!=goal.size()) return false;
        
        s = s + s;
        int n = s.size();
        int g = goal.size();
        
        for(int i=0; i<n; i++){
            if(s[i] == goal[0]){
                int iTemp = i;
                bool matched = true;
                for(int j=0; j<g; j++){
                    if(s[iTemp]!=goal[j]){
                        matched = false;
                        break;
                    }
                    iTemp++;
                }
                if(matched) return true;
            }
        }

        return false;
        
    }
};