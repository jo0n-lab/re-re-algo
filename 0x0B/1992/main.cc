#include<iostream>
#include<vector>
using namespace std;

#define __INPUT__
#define __DEBUG__

int n;
char board[66][66];
vector<char> v;

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	print_config(__func__);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void distill(int d,int xpos,int ypos){
	int flag=1;
	if(d==0) {
		char c=board[xpos][ypos];
		if(v.back()=='(') v.push_back(c);
		else if(v.back()!=c) flag=0;
		if(flag==0) v.push_back(c);
		return;
	}
	int dx[4]={0,0,d,d};
	int dy[4]={0,d,0,d};
	v.push_back('(');
	for(int dir=0;dir<4;dir++){
		distill(d/2,xpos+dx[dir],ypos+dy[dir]);
	}
	v.push_back(')');
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		string line;
		cin>>line;
		for(int j=0;j<n;j++)
			board[i][j]=line[j];
	}

#ifdef __INPUT__
	print_board();
#endif

	distill(n,0,0);

	for(auto c:v) cout<<c;

}





