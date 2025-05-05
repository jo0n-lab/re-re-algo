#include<iostream>
#include<algorithm>
using namespace std;

//#define __DEBUG__

int n,s;
int num[22];
int ans=0;
int cur=0;

int cnt=0;

void checksum(int id){
	if(id>=n) return;
	cnt++;
	if(cur+num[id]==s) ans++;
	cur+=num[id];
	for(int i=id+1;i<n;i++)
		checksum(i);
	cur-=num[id];
	return;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}

	sort(num,num+n);

	for(int i=0;i<n;i++)
		checksum(i);
	cout<<ans<<"\n";

#ifdef __DEBUG__
	cout<<cnt<<"\n";
	for(int i=0;i<n;i++)
		cout<<num[i]<<" ";
#endif

}
