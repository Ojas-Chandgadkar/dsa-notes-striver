// x^n = m, find x

int power(int mid, int n, int m){
  long long res = 1;
  for(int i=0; i<n; i++){
    res *= mid;
    if(res>m) return 2;
  }
  if(res == m) return 0;
  else if(res<m) return 1;
}

int NthRoot(int n, int m) {

  int low = 0;
  int high = m;
  while(low <= high){
    int mid = low + (high-low)/2;

    int res = power(mid, n, m);
    if(res == 0)
      return mid;
      
    else if(res == 1)
      low = mid+1;

    else if(res == 2)
      high = mid-1;
  }

  return -1;
}