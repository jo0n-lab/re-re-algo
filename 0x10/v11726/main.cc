#include<iostream>

using namespace std;

int n;
int cache[1002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cache[1]=1;
	cache[2]=2;

	cin>>n;

	for(int i=3;i<=n;i++){
		for(int j=1;j<=2;j++){
			cache[i]+=cache[i-j];
			cache[i]%=10007;
		}
	}

	cout<<cache[n]<<"\n";
}