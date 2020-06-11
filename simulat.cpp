#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    string s;
    vector<string>rec[64];

    double cnt=0,miss=0;
    while(getline(cin,s)){
        ++cnt;
        int set_number=0;
        string tag,set;
        for(int i=0;i<=19;i++){
            tag+=s[i];
        }
        for(int i=20;i<=25;i++){
            set+=s[i];
        }

        for(int i=20;i<=25;i++){
            set_number=set_number*2+(s[i]-'0');
        }

        bool flag=false;
        for(auto tmp:rec[set_number]){
            if(tmp==tag){
                flag=true;
            }
        }

        if(flag){
            for(auto it=rec[set_number].begin();it!=rec[set_number].end();it++){
                if(*it==tag){
                    rec[set_number].erase(it);
                    break;
                }
            }
            rec[set_number].push_back(tag);
        }
        else{
            ++miss;
            if(rec[set_number].size()<4){
                rec[set_number].push_back(tag);
            }
            else{
                rec[set_number].erase(rec[set_number].begin());
                rec[set_number].push_back(tag);
            }
        }
    }

    cout<<setprecision(10)<<miss*100/cnt<<"%"<<endl;
    
    return 0;
}