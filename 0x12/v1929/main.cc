#include<iostream>
#include<algorithm>
using namespace std;

#define __DEBUG__

int cache[1000002];
int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n_size=1000000;
	fill(cache,cache+1000002,1);
	cache[1]=0;

	for(int i=2;i*i<=n_size;i++){
		if(cache[i]==0) continue;
		for(int j=i*i;j<=n_size;j+=i)
			cache[j]=0;
	}
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		if(cache[i]==1) cout<<i<<"\n";
	}
}
	
