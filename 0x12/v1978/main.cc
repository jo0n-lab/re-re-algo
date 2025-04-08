#include<iostream>
using namespace std;

#define __DEBUG__

int cache[1002];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(cache,cache+1002,1);
	cache[0]=0;
	cache[1]=0;


	for(int i=2;i*i<=1000;i++){
		if(cache[i]==0) continue;
		for(int j=i*i;j<=1000;j+=i)
			cache[j]=0;
	}

	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		ans+=cache[input];
	}

	cout<<ans<<"\n";

}
			


