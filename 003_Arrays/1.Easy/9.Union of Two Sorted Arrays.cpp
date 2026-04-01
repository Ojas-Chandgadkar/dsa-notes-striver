vector < int > sortedArray(vector < int > a, vector < int > b) {
    
    vector<int> res;

    int aN = a.size();
    int bN = b.size();

    int i = 0;
    int j = 0;

    int last;
    while(i<aN && j<bN){
        if(a[i]==last){
            i++;
            continue;
        }
        if(b[j]==last){
            j++;
            continue;
        }
        
        if(a[i] <= b[j]){
            last = a[i];
            res.push_back(a[i]);
            i++;
        }
        else{
            last = b[j];
            res.push_back(b[j]);
            j++;
        }
    }

    while(i < aN){
        if(last!=a[i]){
            last = a[i];
            res.push_back(a[i]);
        }
        i++;
    }
    
    while(j < bN){
        if(last!=b[j]){
            last = b[j];
            res.push_back(b[j]);
        }
        j++;
    }

    return res;
    
}

// ------------------------------My Solution ------------------------------
// Time ->  O(n+m) 
// Space -> O(n+m) 
// ------------------------------ Approach ------------------------------
// Initailize a 'res' vector for storing the union.
// Use two index pointer 'i' and 'j' for arrays 'a' and b.
// Keep a track of the last pushed element in res, to ensure that it is not repeated.
// Populate the 'res' vector using 'a' and 'b'.
// Return the 'res' vector