#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v, int i){         // print using reccursion
    if(i<0) return;
    
    cout << v[i] << " ";
    printArray(v, i-1);
}

int sumArray(vector<int> &v, int i){            // sum using reccursion
    if(i<0) return 0;
    return v[i] + sumArray(v, i-1);
}

int main() {
	vector<int> v = {1, 3, 6, 2, 10};
	int size = v.size();
	
	printArray(v, size-1);
	cout << endl;

	cout << sumArray(v, size-1);

}
