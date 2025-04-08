#include<iostream>
#include<algorithm>
using namespace std;

//#define __DEBUG__
//#define __INPUT__

int A[52];
int B[52];
int n;

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_arr(){
	print_config(__func__);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<B[i]<<" ";
	cout<<"\n";
	print_config("");
}


bool compare(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];

#ifdef __INPUT__
	print_arr();
#endif


	sort(A,A+n);
	sort(B,B+n,compare);

	int ans=0;

	for(int i=0;i<n;i++)
		ans+=A[i]*B[i];

	cout<<ans<<"\n";

#ifdef __DEBUG__
	print_arr();
#endif
}