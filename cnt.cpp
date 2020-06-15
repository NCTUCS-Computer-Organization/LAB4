#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    unordered_map<int,int> m;
    int x;
    while(cin>>x){
        ++m[x];
    }

    for(auto &t:m){
        cout<<t.first<<" "<<t.second<<endl;
    }
    
    return 0;
}