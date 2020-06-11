#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    // Let us simulate 4KB cache with 16B blocks
	FILE *fp = fopen("LU.txt","r");

    unsigned int x;
    while(fscanf(fp,"%x", &x)!= EOF){
        for(int i=31;i>=0;i--){
            if(x>=pow(2,i)){
                cout<<1;
                x-=pow(2,i);
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
	
	fclose(fp);

    
    return 0;
}