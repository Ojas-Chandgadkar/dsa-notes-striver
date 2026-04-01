string read(int n, vector<int> book, int target)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(book[i]+book[j] == target){
                return "YES";
            }
        }
    }
    return "NO";
}



// ------------------------------My Solution ------------------------------
// Time -> O(n^2) 
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Check for addition of every element to other elements if it gives addition as 'target'
// Return 'YES' if there exists, else 'NO' by deafult if not.
