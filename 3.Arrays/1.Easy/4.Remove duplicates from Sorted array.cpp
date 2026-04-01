#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}


// ------------------------------My Solution ------------------------------
// Time ->  O(n) with single pass
// Space -> O(1)
// ------------------------------ Approach ------------------------------
// Intitalize i=0 and j=1;
// Loop j for j<n, and check if(a[i]!=a[j])
// At the end return i+1, which is the size of the new arr without duplciates
