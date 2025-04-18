#include<iostream>
using namespace std;

int num;
string ans="";

int hanoi(int n,int src,int dst){
	if(n==1) {
		ans+=to_string(src)+" "+to_string(dst)+"\n";
		return 1;
	}
	int pos;
	if(src+dst==3) pos=3;
	if(src+dst==4) pos=2;
	if(src+dst==5) pos=1;
	int cnt=0;
	cnt+=hanoi(n-1,src,pos)+1;
	ans+=to_string(src)+" "+to_string(dst)+"\n";
	cnt+=hanoi(n-1,pos,dst);
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>num;

	cout<<hanoi(num,1,3)<<"\n"<<ans;
}



