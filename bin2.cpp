#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    string s;
    while(cin>>s){
        for(int i=17;i<=25;i++){
            cout<<s[i];
        }
        cout<<" ";
        for(int i=0;i<=16;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    
    return 0;
}