/*
Problem Statement: 
Given an array, print all the elements which are leaders (in ascending order).
A Leader is an element that is greater than all of the elements on its right side in the array.
*/

vector<int> superiorElements(vector<int>&a) {
    
    int N = a.size();
    vector<int> res;

    int max = INT_MIN;
    for(int i=N-1; i>=0; i--){
        if(a[i] > max){
            res.push_back(a[i]);
            max = a[i];
        }
    }

    return res;
}


// ------------------------------My Solution ------------------------------
// Time -> O(n) 
// Space -> O(n)
// ------------------------------ Approach ------------------------------
// Intialize 'vector<int> res' to store the leaders in sorted manner.
// Intialize 'max=INT_MIN' to keep track of the maximum element.
// Reverse iterate the vector 'a', 
//      Check if the current element is an leader 
//      If yes, add it to result, and update max.
// The res vector in this fashion is already sorted.
// Return the 'res'