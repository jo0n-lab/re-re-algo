#include<iostream>
#include<vector>
using namespace std;

//#define __DEBUG__
int cnt=0;

int n,m;
int vis[10];
vector<int> v;


void func(int cur){
	if(v.size()==m) {
		for(auto i:v) cout<<i<<" ";
		cout<<"\n";
#ifdef __DEBUG__
		cnt++;
#endif
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		v.push_back(i);
		func(i);
		v.pop_back();
		vis[i]=0;
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	func(1);
#ifdef __DEBUG__
	cout<<cnt<<"\n";
#endif
}

	
