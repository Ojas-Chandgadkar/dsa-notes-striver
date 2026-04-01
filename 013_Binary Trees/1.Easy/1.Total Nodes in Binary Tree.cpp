// Given integer 'N', determine the max number of nodes possible on 'N' th Level.
// For referenxe, The root is at Level 1 (N=1) .




int numberOfNodes(int N){
  
    return pow(2, N-1);
}