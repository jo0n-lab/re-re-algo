#include<iostream>
#include<algorithm>
using namespace std;

//#define __DEBUG__

int n,m;
int num[10];
int ans[10];
int tmp=0;

void func(int cur,int cnt){
	if(cnt==m) {
#ifdef __DEBUG__
		cout<<++tmp<<"\n";
#endif
		for(int i=0;i<m;i++) cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=cur;i<n;i++){
		ans[cnt]=num[i];
		func(i,cnt+1);
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

	
