#include<bits/stdc++.h>
using namespace std;

int stringToInt(string s){
    
    int len = s.size();
    if(len==0) return 0;
    
    
    int currDigit = s[0] - '0';
    if(len==1) return currDigit;
    
    return currDigit*pow(10,len-1) + stringToInt(s.substr(1));
}
int main(){
  
    string s = "123";
    
    int res = stringToInt(s);
    cout << res;
    
    return 0;
}