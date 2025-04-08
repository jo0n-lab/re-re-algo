#include<iostream>
#include<algorithm>
using namespace std;

//#define __DEBUG__

int n;
int stair[302];
int cache[302][2];
//0: skip previous step
//1: step previous step

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_cache(){
	print_config(__func__);
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			cout.width(3);
			cout.fill(' ');
			cout<<cache[i][j]<<" ";
		}
		cout<<"\n";
	}
	print_config("");
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stair[i];
	}

	cache[1][1]=stair[1];
	cache[1][0]=stair[1];
	cache[2][0]=stair[2];
	cache[2][1]=stair[1]+stair[2];

	for(int i=3;i<=n;i++){
		//skip prev step
		cache[i][0]=max(cache[i-2][0],cache[i-2][1])+stair[i];
		//step prev step
		cache[i][1]=cache[i-1][0]+stair[i];
	}

	cout<<max(cache[n][1],cache[n][0])<<"\n";

#ifdef __DEBUG__
	print_cache();
#endif
}