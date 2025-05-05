#include<iostream>
#include<algorithm>
using namespace std;

int num[10];
int ans[10];
int n,m;

void func(int cur,int cnt){
	if(cnt==m) {
		for(int i=0;i<m;i++) cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=cur;i<n;i++){
		ans[cnt]=num[i];
		func(cur,cnt+1);
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
