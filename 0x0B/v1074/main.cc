#include<iostream>
#include<utility>

using namespace std;

#define X first
#define Y second

//#define __DEBUG__

int n,r,c;

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

int getCnt(int a,int b,int depth){
	if(depth==1) return (a%2)*2+(b%2);
	int d=1<<(depth-1);
	int s=d*d;
#ifdef __DEBUG__
	print_config("depth: "+to_string(depth)+" side: "+to_string(s));
#endif
	return 2*s*(a/d)+s*(b/d)+getCnt(a%d,b%d,depth-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>r>>c;

	cout<<getCnt(r,c,n)<<"\n";
}
