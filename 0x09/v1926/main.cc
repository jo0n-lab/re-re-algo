#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//#define __INPUT__
//#define __DEBUG__
//#define __PRINT__

#define X first
#define Y second

int n, m;
int board[502][502];
int vis[502][502];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	print_config("print_board");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	queue<pair<int,int>> init;
	
	int n_shape=0;
	int max_size=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int input; 
			cin>>input;
			if(input==1) init.push({i,j});
			board[i][j]=input;
		}
	}

#ifdef __PRINT__
	print_board();
	print_config(to_string(init.size()));
#endif

	while(!init.empty()){
		pair<int,int> init_pos=init.front();
		init.pop();
		if(vis[init_pos.X][init_pos.Y]==1) continue;
		vis[init_pos.X][init_pos.Y]=1;
		queue<pair<int,int>> q;
		q.push(init_pos);
		n_shape++;
		int tmp_size=0;
		
		while(!q.empty()){
			tmp_size++;
			pair<int,int> cur=q.front();
			q.pop();
			for(int dir=0;dir<4;dir++){
				int nx=cur.X+dx[dir];
				int ny=cur.Y+dy[dir];
				if(nx>=n || nx<0) continue;
				if(ny>=m || ny<0) continue;
				if(board[nx][ny]==0) continue;
				if(vis[nx][ny]==1) continue;
				vis[nx][ny]=1;
				q.push({nx,ny});
			}
		}
		max_size=max(tmp_size,max_size);
	}

	cout<<n_shape<<"\n"<<max_size<<"\n";
}