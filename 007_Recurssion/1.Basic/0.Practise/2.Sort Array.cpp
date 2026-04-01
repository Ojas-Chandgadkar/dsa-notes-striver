#include<bits/stdc++.h>
using namespace std;


void InsertInSortedManner(vector<int> &v, int val){
  if(v.size()==0 || v[v.size()-1] <= val){
    v.push_back(val);
    return;
  }
  
  int temp = v[v.size()-1];
  v.pop_back();
  
  InsertInSortedManner(v, val);
  v.push_back(temp);
}


void SortArr(vector<int> &v){
  if(v.size() == 0 || v.size() == 1) return;
  
  int val = v[v.size()-1];
  v.pop_back();
  SortArr(v);
  
  InsertInSortedManner(v, val);
}


void printArr(vector<int> &v, int index){
  
  if(index < 0) return;
  
  printArr(v, index-1);
  cout << v[index] << " ";
}


int main(){
  vector<int> v = {90,1,42,-10,54,76,12};
  int size = v.size();
  
  SortArr(v);
  printArr(v, size-1);
  
  return 0;
}