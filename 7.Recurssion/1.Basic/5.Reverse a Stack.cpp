// Time  : O(N)
// Space : O(N)
// where N is stack size
#include<bits/stdc++.h>
using namespace std;

void InsertAt_StackBottom(stack<int> &st, int val){
  if(st.empty()){
    st.push(val);
    return;
  }
  
  int temp = st.top();
  st.pop();
  
  InsertAt_StackBottom(st, val);
  st.push(temp);
}

void Reverse_Stack(stack<int> &st){
  if(st.empty()) return;
  
  int val = st.top();
  st.pop();
  
  Reverse_Stack(st);
  InsertAt_StackBottom(st, val);
}


void printStack(stack<int> &st){
  if(st.empty()) return;
  
  int val = st.top();
  st.pop();
  cout << val << " ";
  
  printStack(st);
  st.push(val);
}

int main(){
  
  stack<int> st;
  st.push(0);
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  
  cout << "\nBefore Reversing : ";
  printStack(st);
  
  Reverse_Stack(st);
  
  cout << "\nAfter Reversing  : ";
  printStack(st);
  
  return 0;
}