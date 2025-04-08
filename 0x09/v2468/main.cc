#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

#define X first
#define Y second

//#define __DEBUG__

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int board[102][102];
int result[102];
int n;

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
	print_config("-");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int h_max=0;

	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			h_max=max(h_max,board[i][j]);
		}
	}

	int ans=1;

	for(int h=h_max;h>0;h--){
		int h_result=0;
		int tmp=0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]<=h) continue;

				queue<pair<int,int>> Q;			
				Q.push({i,j});
				while(!Q.empty()){
					pair<int,int> cur=Q.front();
					Q.pop();
					for(int dir=0;dir<4;dir++){
						int nx=cur.X+dx[dir];
						int ny=cur.Y+dy[dir];
						if(nx>=n||nx<0||ny>=n||ny<0) continue;
						if(board[nx][ny]<=h) continue;
						board[nx][ny]=h;
						Q.push({nx,ny});
					}
				}
				tmp++;
			}
		}
#ifdef __DEBUG__
		print_board();
#endif
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
}