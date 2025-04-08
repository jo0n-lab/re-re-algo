#include<iostream>
#include<utility>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

int n,m;
int num[100002];
long long cache[100002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cache[i]=num[i]+cache[i-1];
	}

	for(int k=0;k<m;k++){
		int i,j;
		cin>>i>>j;
		cout<<cache[j]-cache[i-1]<<"\n";
	}
}