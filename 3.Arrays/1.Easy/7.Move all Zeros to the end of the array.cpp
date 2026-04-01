
vector<int> moveZeros(int n, vector<int> a) {
    
    int back = -1;
    int front = 0;

    for(int i=0; i<n; i++){
        if(a[i]==0){
            back = i;
            break;
        }
    }
    if(back==-1) return a;

    for(front=back+1; front<n; front++){
        if(a[front]!=0){
            swap(a[front], a[back]);
            back++;
        }
    }
    
    return a;

}


// ------------------------------My Solution ------------------------------
// Time ->  O(n)
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intialize two index pointer 'back' and front'
// Itertate through array to find first zero, if not found return the array as it is.
// 'back' points to first zero
// 'front' points to first non-zero
//  keep swapping them til front<n
//  Return the array.