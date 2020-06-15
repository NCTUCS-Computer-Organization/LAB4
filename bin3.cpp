#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    string s1,s2;
    unordered_map<string,int> m;
    set<string> rec;

    while(cin>>s1>>s2){
            ++m[s1+s2];
    }

    for(auto &t:m){
        cout<<t.first<<" "<<t.second<<endl;
    }
    
    return 0;
}