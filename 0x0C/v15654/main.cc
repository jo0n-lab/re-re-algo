#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int ans[10];
int num[10];
int vis[10];

void func(int cnt){
	if(cnt==m){
		for(int i=0;i<m;i++) cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		ans[cnt]=num[i];
		func(cnt+1);
		vis[i]=0;
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++) cin >>num[i];
	sort(num,num+n);

	func(0);
}




