#include<iostream>
using namespace std;

int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	if(n==1) return 0;

	int tmp=n;
	int res=2;
	while(tmp!=1){
		if(tmp%res==0) {
			tmp/=res;
			cout<<res<<"\n";
		}
		else res++;
	}
}


