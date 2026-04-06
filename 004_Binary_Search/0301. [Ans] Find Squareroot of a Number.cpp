int floorSqrt(int n)
{
    int res = 1;

    int low =  1;
    int high = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(mid*mid == n){
            res = max(res, mid);
            break;
        }
        else if(mid*mid < n){
            res = max(res, mid);
            low = mid + 1;
        }
        else if(mid*mid > n){
            high = mid-1;
        }
    }
    
    return res;     
}
