#include<iostream>
using namespace std;

int a,b,c;

int getRemain(int a,int b){
	if(b==1) return a%c;
	long long tmp=getRemain(a,b/2)%c;
	long long result=tmp*tmp%c;
	if(b%2!=0) result*=a%c;
	result%=c;
	return result;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b>>c;
	cout<<getRemain(a,b)<<"\n";

	return 0;
}
