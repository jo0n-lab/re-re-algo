#include<iostream>
#include<queue>
#include<utility>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

#define X first
#define Y second

int n,m;
char board[1002][1002];
int dist[2][1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
pair<int,int> cur;

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

	fill(dist,dist+1002*1002*2,-1);
	queue<pair<int,int>> q[2];

   cin>>n>>m;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>board[i][j];
         if(board[i][j]=='J'){
            q[0].push({i,j});
				dist[0][i][j]=0;
			}
			if(board[i][j]=='#'){
				q[1].push({i,j});
				dist[1][i][j]=0;
			}
      }
   }

#ifdef __INPUT__
   print_board();
#endif

	for(int i=0;i<2;i++){
		while(!q[i].empty()){
			pair<int,int> cur=q[i].front();
			if(cur.X==n-1 || cur.Y==m-1) break;
			q[i].pop();
			for(int dir=0;dir<4;dir++){
				int nx=cur.X+dx[dir];
				int ny=cur.Y+dy[dir];
				if(nx>=nx || nx<0 || ny>=m || ny<0) continue;
				if(board[nx][ny]=='#') continue;
				if(dist[i][nx][ny]>=0) continue;
				dist[i][nx][ny]=dist[i][cur.X][cur.Y]+1;
				q[i].push({nx,ny});
			}
		}
	}
	if(


}



