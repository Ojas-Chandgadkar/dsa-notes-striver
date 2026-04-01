//  *  *  *  * 
//  *  *  *  * 
//  *  *  *  * 
//  *  *  *  * 
int n = 4;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cout << " * ";
    }
    cout << endl;
}


//  * 
//  *  * 
//  *  *  * 
//  *  *  *  * 
//  *  *  *  *  * 
int n = 5;
for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        cout << " * ";
    }
    cout << endl;
}


// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 
int n = 5;
for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        cout << j+1 << " ";
    }
    cout << endl;
}


// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5 
int n = 5;
for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        cout << i+1 << " ";
    }
    cout << endl;
}


//  *  *  *  *  * 
//  *  *  *  * 
//  *  *  * 
//  *  * 
//  * 
int n = 5;
for(int i=n; i>=0; i--){
    for(int j=0; j<i; j++){
        cout << " * ";
    }  
    cout << endl;
}


// 1 2 3 4 5 
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 
int n = 5;
for(int i=0; i<n; i++){
    for(int j=0; j<n-i; j++){
        cout << j+1 << " ";
    }
    cout << endl;
}
  

//             * 
//          *  *  * 
//       *  *  *  *  * 
//    *  *  *  *  *  *  * 
// *  *  *  *  *  *  *  *  * 
int n =5;
for(int i=0; i<n; i++){
    for(int sp=0; sp<n-i-1; sp++){
        cout << "   ";
    }
    for(int j=0; j<=i*2; j++){
        cout << " * ";
    }
    cout << endl;
}


//  *  *  *  *  *  *  *  *  * 
//     *  *  *  *  *  *  * 
//        *  *  *  *  * 
//           *  *  * 
//               int n = 5;
for(int i=n; i>0; i--){
    for(int sp=0; sp<n-i; sp++){
        cout << "   ";
    }
    for(int j=0; j<2*i-1; j++){
        cout << " * ";
    }
    cout << endl;
}


//              * 
//           *  *  * 
//        *  *  *  *  * 
//     *  *  *  *  *  *  * 
//  *  *  *  *  *  *  *  *  * 
//  *  *  *  *  *  *  *  *  * 
//     *  *  *  *  *  *  * 
//        *  *  *  *  * 
//           *  *  * 
//              * 
int n = 5;
for(int i=0; i<n; i++){
    for(int sp=0; sp<n-i-1; sp++){
        cout << "   ";
    }
    for(int j=0; j<2*i+1; j++){
        cout << " * ";
    }
    cout << endl;
}
for(int i=n; i>0; i--){
    for(int sp=0; sp<n-i; sp++){
        cout << "   ";
    }
    for(int j=0; j<2*i-1; j++){
        cout << " * ";
    }
    cout << endl;
}


//  * 
//  *  * 
//  *  *  * 
//  *  *  *  * 
//  *  *  *  *  * 
//  *  *  *  * 
//  *  *  * 
//  *  * 
//  * 
int n = 5;
for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
        cout << " * ";
    }
    cout << endl;
}
for(int i=n-1; i>0; i--){
    for(int j=i; j>0; j--){
        cout << " * ";
    }
    cout << endl;
}


// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 
int n = 5;
for(int i=0; i<n; i++){
    bool startbit;
    if(i%2==0) startbit = true;
    else if(i%2!=0) startbit = false;
    
    for(int j=0; j<i+1; j++){
        cout << startbit << " ";
        startbit = !startbit;
    }
    cout << endl;
}


// 1      1
// 12    21
// 123  321
// 12344321
int n = 4;
for(int i=1; i<=n; i++){
    for(int x=1; x<=i;x++){
        cout << x << "";
    }
    for(int sp=0; sp<2*(n-i); sp++){
        cout << " ";
    }
    for(int y=i; y>0; y--){
        cout << y << "";
    }
    cout << endl;
}


// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 
int n = 5;
int val = 1;
for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        cout << val++ << " ";
    }
    cout << endl;
}


// A 
// A B 
// A B C 
// A B C D 
// A B C D E 
int n = 5;
for(int i=0; i<n; i++){
    char ch = 'A';
    for(int j=0; j<=i; j++){
        cout << ch++ << " ";
    }
    cot << endl;
}


// A B C D E 
// A B C D 
// A B C 
// A B 
// A 
int n = 5;
for(int i=0; i<n; i++){
    char ch = 'A';
    for(int j=0; j<n-i; j++){
        cout << ch++ << " ";
    }
    cout << endl;
}
  

// A 
// B B 
// C C C 
// D D D D 
// E E E E E 
int n = 5;
for(int i=0; i<n; i++){
    char ch = 'A' + i;
    for(int j=0; j<=i; j++){
        cout << ch << " ";
    }
    cout << endl;
}


//    A
//   ABA
//  ABCBA
// ABCDCBA
int n = 4;
for(int i=0; i<n; i++){
    char ch = 'A';
    for(int sp=0; sp<n-i-1; sp++){
        cout << " ";
    }
    for(int x=0; x<2*i+1; x++){
      if(x < 2*i/2) cout << ch++;
      else if(x==2*i/2) cout << ch;
      else cout << --ch;
    }
    cout << endl;
}


// E 
// D E 
// C D E 
// B C D E 
// A B C D E 
int n = 5;
for(int i=5; i>0; i--){
    char ch = 'A' + i-1;
    for(int j=1; j<=n-i+1; j++){
        cout << ch++ << " ";
    }
    cout << endl;
}


// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
int n = 5;
for(int i=n; i>0; i--){
    for(int x=1; x<=i; x++){
        cout << "*";
    }
    for(int sp=1; sp<=2*n-2*i; sp++){
        cout << " ";
    }
    for(int y=1; y<=i; y++){
        cout << "*";
    }
    cout << endl;
}
for(int i=1; i<=n; i++){
    for(int x=1; x<=i; x++){
        cout << "*";
    }
    for(int sp=1; sp<=2*n-2*i; sp++){
        cout << " ";
    }
    for(int y=1; y<=i; y++){
        cout << "*";
    }
    cout << endl;
}


// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
int n = 5;
for(int i=1; i<=n; i++){
    for(int x=1; x<=i; x++){
        cout << "*";
    }
    for(int sp=1; sp<=2*n-2*i; sp++){
        cout << " ";
    }
    for(int y=1; y<=i; y++){
        cout << "*";
    }
    cout << endl;
}
for(int i=n-1; i>0; i--){
    for(int x=1; x<=i; x++){
        cout << "*";
    }
    for(int sp=1; sp<=2*n-2*i; sp++){
        cout << " ";
    }
    for(int y=1; y<=i; y++){
        cout << "*";
    }
    cout << endl;
}


// ****
// *  *
// *  *
// ****
int n = 4;
for(int i=n; i>=1; i--){
    if(i==n || i==1){
      for(int x=1; x<=n; x++){
          cout << "*";
      }
    }
    else{
        cout << "*";
        for(int sp=1; sp<=n-2; sp++){
            cout << " ";
        }
        cout << "*";
    }
    cout << endl;
}




