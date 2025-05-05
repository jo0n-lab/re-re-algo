#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int num[10];
int ans[10];

void func(int cur,int cnt){
	if(cnt==m){
		for(int i=0;i<m;i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	for(int i=cur;i<n;i++){
		ans[cnt]=num[i];
		func(i+1,cnt+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num,num+n);

	func(0,0);
}