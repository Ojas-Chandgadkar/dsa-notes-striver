/*
You are given an array 'arr' of length 'n' containing integers within the range '1' to 'x'.
Your task is to count the frequency of all elements from 1 to n.
*/

vector<int> countFrequency(int n, int x, vector<int> &nums){
    
    vector<int> count(n, 0);

    for(int i=0; i<n; i++){
        count[nums[i]-1]++;
    }


    return count;
}