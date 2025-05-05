#include<iostream>
using namespace std;

//#define __DEBUG__

int n,m;
int num[9];
int tmp=0;

void func(int cnt){
	if(cnt==m) {
		for(int i=0;i<m;i++) cout<<num[i]<<" ";
		cout<<"\n";
#ifdef __DEBUG__
		tmp++;
		cout.width(30);
		cout.fill('-');
		cout<<to_string(tmp)+" th run\n";
#endif
		return;
	}
	for(int i=1;i<=n;i++){
		num[cnt]=i;
		func(cnt+1);
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
   func(0);

}
