//DAA 1 
//Title:  Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyse their time and space complexity .


//#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

int fibonacci(int n) { 
 if (n <= 1) {
   return n;
 }
 return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    
 int i, n, t1 = 0, t2 = 1, nT;
 cout<< "Fibonacci Series in C++ Without Using Recursion ";
 cout<< "\nEnter any number:";
 cin >> n;

 for (i = 1; i <= n; ++i) {
    cout << t1 << " ";
    nT = t1 + t2; 
    t1 = t2;
    t2 = nT;
 }

 cout<< "\n\nFibonacci Series in C++ Using Recursion"; 
 cout<< "\nEnter any number:";
 int p; cin>>p;
 cout << fibonacci(p);

}
