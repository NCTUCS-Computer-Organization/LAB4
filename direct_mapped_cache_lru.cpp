#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <cstring>
#include <iomanip>

using namespace std;

struct cache_content
{
	//bool v=false;
	unsigned int tag;
    // unsigned int	data[16];
};

const int K = 1024;

double log2(double n)
{  
    // log(n) / log(2) is log2.
    return log(n) / log(double(2));
}


void simulate(int cache_size, int block_size, const char * file_name)
{
	unsigned int tag, index, x;

	int offset_bit = (int)log2(block_size);
	int index_bit = (int)log2(cache_size / block_size);
	int line = cache_size >> (offset_bit);

	list <cache_content> cache[line];
    int size_of_set= block_size >> 2; 

    //cout << "cache line: " << line << endl;
    cout << "cache size: " << cache_size/K << "K " << "block size: " << block_size << " Miss Rate:";
    
    FILE *fp = fopen(file_name, "r");  // read file
	
    int count=0,miss=0;
	while(fscanf(fp, "%x", &x) != EOF)
    {
		
		index = (x >> offset_bit) & (line - 1);
		tag = x >> (index_bit + offset_bit);
        bool flag=false;
        for(auto it=cache[index].begin();it!=cache[index].end();it++){
            if(it->tag == tag){
                cache[index].insert(cache[index].begin(),*it);
                it=cache[index].erase(it);
                flag=true;
                break;
            }
        }
        if(!flag){
            miss++;
            cache_content temp;
            temp.tag=tag;
            cache[index].push_front(temp);
            if(cache[index].size()>size_of_set)cache[index].pop_back();
        }
        count++;
	
    }
	fclose(fp);
    
    cout<<setprecision(10)<<double(miss)*100/count<<"%"<<endl;
	
}
	
int main()
{
	// Let us simulate 4KB cache with 16B blocks
    cout<<"radix"<<endl;            
    for(int i=4;i<=256;i*=4){
        for(int j=16;j<=256;j*=2){
	        simulate(i * K, j,"RADIX.txt");
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"lu"<<endl;

    for(int i=4;i<=256;i*=4){
        for(int j=16;j<=256;j*=2){
	        simulate(i * K, j,"LU.txt");
        }
        cout<<endl;
    }

}
