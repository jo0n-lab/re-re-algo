#include<iostream>
#include<queue>
#include<utility>
using namespace std;

//#define __DEBUG__
//#define __PRINT__
//#define __INPUT__

#define X first
#define Y second

int n,m;
int board[1002][1002];
int dist[1002][1002];
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
			cout.width(3);
			cout.fill(' ');
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
			cout.width(3);
			cout.fill(' ');
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	print_config("");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<pair<int,int>> q;

	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
			if(board[i][j]==1) 
				q.push({i,j});
			else if(board[i][j]==0)
				dist[i][j]=-1;
			//if dist==0,1,2,,, regard as visited but will visit at first time
		}
	}

#ifdef __DEBUG__
	print_dist();
#endif

	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx>=n || nx<0 || ny>=m || ny<0) continue;
			if(dist[nx][ny]>=0) continue;
			dist[nx][ny]=dist[cur.X][cur.Y]+1;
			q.push({nx,ny});
		}
	}

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist[i][j]==-1) {
				cout << -1<<"\n";
				return 0;
			}
			ans=max(ans,dist[i][j]);
		}
	}
	cout<<ans<<"\n";

#ifdef __DEBUG__
	print_board();
	print_dist();
#endif
			
}

			


		







	


