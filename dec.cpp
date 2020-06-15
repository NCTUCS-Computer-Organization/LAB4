#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    unsigned int x;
    unordered_map<unsigned,int> s;
    while(cin>>hex>>x){
        ++s[x];
    }

    for(auto &tmp:s){
        cout<<tmp.first<<" "<<tmp.second<<endl;
    }
    
    return 0;
}