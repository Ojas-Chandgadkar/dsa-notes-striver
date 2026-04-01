bool isValidBST(vector<int> &order){
    
    int n = order.size();
    for(int i=0; i<n-1; i++){
        if(order[i] >= order[i+1]){
            return false;
        }
    }

    return true;
}
