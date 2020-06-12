#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    cout<<log(64)<<endl;
    cout<<log(2)<<endl;
    cout<<log(64)/log(2)<<endl;
    double b=log(double(64));
    double c=log(double(2));
    double a=b/c;
    cout<<setprecision(100)<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<setprecision(100)<<double(b)/c<<endl;
    return 0;
}