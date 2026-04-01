// Time  : O(N)
// Space : O(N)
// Where N is the string length

#include <iostream>
using namespace std;

string starInserter(string s) {
    if (s.size() <= 1)
        return s;

    if (s[0] == s[1])
        return s.substr(0, 1) + "*" + starInserter(s.substr(1));
    else
        return s.substr(0, 1) + starInserter(s.substr(1));
}

int main() {
    string s1 = "aabb";
    string s2 = "xxxy";

    cout << "Input: " << s1 << "\nOutput: " << starInserter(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << starInserter(s2) << "\n";

    return 0;
}

