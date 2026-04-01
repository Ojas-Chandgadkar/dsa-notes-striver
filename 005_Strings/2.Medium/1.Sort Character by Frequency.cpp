class Solution {
public:
    string frequencySort(string s) {
        
        string res = "";

        int n = s.size();
        unordered_map<char,int> ump;
        priority_queue<pair<int,char>> maxHeap;

        for(int i=0; i<n; i++){
            ump[s[i]]++;
        }

        for(auto it=ump.begin(); it!=ump.end(); it++){
            char ch = it->first;
            int freq = it->second;

            maxHeap.push({freq,ch});
        }

        while(!maxHeap.empty()){
            int freq = maxHeap.top().first;
            char ch = maxHeap.top().second;
            maxHeap.pop();

            for(int i=0; i<freq; i++) res += ch;
        }

        return res;
    }
};


// ------------------------------My Solution ------------------------------
// Time -> O(n+mlogm), where m is the number of unique characters i 
// Space -> O(n)
// ------------------------------ Approach ------------------------------
//