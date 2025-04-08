#include<iostream>
#include<algorithm>
using namespace std;

int t;
int cache[12];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;

	cache[1]=1;
	cache[2]=2;
	cache[3]=1+2+1;

	for(int i=4;i<=10;i++){
		for(int j=1;j<=3;j++){
			cache[i]+=cache[i-j];
		}
	}

	for(int i=0;i<t;i++){
		int input;
		cin>>input;
		cout<<cache[input]<<"\n";
	}
}
