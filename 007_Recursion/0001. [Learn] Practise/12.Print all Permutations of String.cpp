
// UNOPTIMIZD ------------------------------------------------------------------------------------------------------- 
//      Here at every node we maintain a 'visited' and 'path' vector.
// ------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void printHelper(string s, int size, vector<char> path, vector<bool> visited){
    
    if(path.size() == size){
        for(auto val : path) cout << val << " ";
        cout << endl;
        return;
    };

    for(int i=0; i<size; i++){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(s[i]);
            printHelper(s, size, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
}

void printPermutations(string s){
    int size =  s.size();
    vector<char> path;
    vector<bool> visited(size, false);
    
    printHelper(s, size, path, visited);
}

int main() 
{
    string s = "abc";
    printPermutations(s);
    
    return 0;
}



// OPTIMIZEZD : -------------------------------------------------------------------------------------------------------
//      Here at every node just swap.
// ------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

void printHelper(vector<int>& arr, int index, vector<vector<int>> &res){
    
    if(index == arr.size()){
        res.push_back(arr);
        return;
    }
    
    for(int i=index; i<arr.size(); i++){
        swap(arr[i], arr[index]);
        printHelper(arr, index+1, res);
        swap(arr[i], arr[index]);
    }
}


void printPermutations(vector<int> &arr){
    
    vector<vector<int>> res;
    printHelper(arr, 0, res);
    
    for(auto vec : res){
      for(auto val : vec) cout << val << " ";
      cout << endl;
    }
}

int main(){
    
    vector<int> arr = {1,2,3};
    printPermutations(arr);
    
    return 0;
}




/*
Output :
a b c 
a c b 
b a c 
b c a 
c a b 
c b a 

*/