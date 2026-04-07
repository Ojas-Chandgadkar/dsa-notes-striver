void get_res(int x, vector<int> &res){
    if(x<=0) return;

    get_res(x-1, res);
    res.push_back(x);
}

vector<int> printNos(int x) {
    
    vector<int> res;
    get_res(x, res);

    return res;
}