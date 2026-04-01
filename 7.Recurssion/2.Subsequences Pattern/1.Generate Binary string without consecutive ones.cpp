// Time  : O(2^N)
// Space : O(N)
void stringGenerator(int N, vector<bool>& path, bool prev, vector<string>& res) {
    if (N == 0) {
        string result;
        for (bool bit : path) {
            result += bit ? '1' : '0';
        }
        res.push_back(result);
        return;
    }

    path.push_back(0);
    stringGenerator(N - 1, path, 0, res);
    path.pop_back();
    
    if (prev == 0) {
        path.push_back(1);
        stringGenerator(N - 1, path, 1, res);
        path.pop_back();
    }

}

vector<string> generateString(int N) {
    vector<string> res;
    vector<bool> path;
    stringGenerator(N, path, false, res);

    return res;
}

