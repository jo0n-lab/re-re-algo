#include<iostream>
#include<queue>
#include<utility>
using namespace std;

#define X first
#define Y second

//#define __INPUT__
//#define __DEBUG__
//#define __PRINT__

int n,m;
int board[102][102];
int dist[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	print_config(__func__);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	print_config("");
}

void print_dist(){
	print_config(__func__);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	print_config("");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dist[0][0]=1;

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char input;
			cin>>input;
			board[i][j]=int(input) - int('0');
		}
	}

#ifdef __INPUT__
	print_board();
	print_dist();
#endif

	queue<pair<int,int>> q;
	q.push({0,0});

	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();

		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx>=n || nx<0 || ny>=m || ny<0) continue;
			if(board[nx][ny]==0 || dist[nx][ny]>=1) continue;
			if(nx==n-1 && ny==m-1) {
				cout<<dist[cur.X][cur.Y]+1<<"\n";
				return 0;
			}
			dist[nx][ny]=dist[cur.X][cur.Y]+1;
			q.push({nx,ny});
		}
	}

#ifdef __DEBUG__
	print_dist();
#endif
}





