// Time  : O(N^2)
// Space : O(N)
#include<bits/stdc++.h>
using namespace std;

void Insert_inOrder(stack<int> &st, int val){
  if(st.empty() || st.top()<=val){
    st.push(val);
    return;
  }
  
  int temp = st.top();
  st.pop();
  
  Insert_inOrder(st, val);
  st.push(temp);
}


void Sort_Stack(stack<int> &st){
  if(st.empty())  return;
  
  int val = st.top();
  st.pop();
  
  Sort_Stack(st);
  Insert_inOrder(st,val);
}


void printStack(stack<int> st){
  if(st.empty()) return;
  
  int val = st.top();
  st.pop();
  
  printStack(st);
  cout << val << " ";
}


int main(){
  stack<int> st;

  st.push(10);
  st.push(0);
  st.push(44);
  st.push(54);
  st.push(76);
  st.push(12);
  
  cout << "Original Stack: ";
  printStack(st);
  
  Sort_Stack(st);
  
  cout << "\nSorted Stack: ";
  printStack(st);
  return 0;
}
