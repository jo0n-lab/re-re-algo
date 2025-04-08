#include<iostream>
#include<algorithm>
using namespace std;

int n;
int cache[1000002];

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	cache[2]=1;
	cache[3]=1;

	for(int i=4;i<=n;i++){
		cache[i]=min({cache[i/2]+i%2,cache[i/3]+i%3,cache[i-1]})+1;
	}

	cout<<cache[n]<<"\n";
}






