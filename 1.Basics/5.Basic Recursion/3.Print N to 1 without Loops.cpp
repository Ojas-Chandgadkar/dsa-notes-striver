void get_res(int x, vector<int> &res){
    if(x<=0) return;

    res.push_back(x);
    get_res(x-1, res);
}

vector<int> printNos(int x) {
    vector<int> res;
    get_res(x, res);

    return res;
}