#include<iostream>
#include<utility>
#include<queue>

#define X first
#define Y second

using namespace std;

//#define __DEBUG__

char board[14][8];
int vis[14][8];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cout<<board[i][j];
		}cout<<"\n";
	}
}

bool pop_puyo(int xpos,int ypos){
	queue<pair<int,int>> q;
	queue<pair<int,int>> tmp;
	char color=board[xpos][ypos];
#ifdef __DEBUG__
	print_config(string(1,color)+": "+to_string(xpos)+" "+to_string(ypos));
#endif

	vis[xpos][ypos]=1;
	
	q.push({xpos,ypos});
	tmp.push({xpos,ypos});

	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx<0||nx>=12||ny<0||ny>=6) continue;
			if(board[nx][ny]=='.'|| board[nx][ny]!=color) continue;
			if(vis[nx][ny]==1) {
#ifdef __DEBUG__
				print_config(to_string(nx)+" "+to_string(ny)+" visited");
#endif
				continue;
			}
			vis[nx][ny]=1;
			q.push({nx,ny});
			tmp.push({nx,ny});
		}
	}
	if(tmp.size()<4) {
#ifdef __DEBUG__
		print_config("nothing to do");
#endif
		return false;
	}
#ifdef __DEBUG__
	print_config(to_string(tmp.size())+" puyo pop");
#endif
	while(!tmp.empty()){
		pair<int,int> cur=tmp.front();
		tmp.pop();
		board[cur.X][cur.Y]='.';
	}
	return true;
}

void fall_puyo(){
	for(int j=0;j<6;j++){
		queue<char> tmp;
		for(int i=11;i>=0;i--){
			if(board[i][j]=='.') continue;
			tmp.push(board[i][j]);
			board[i][j]='.';
		}
		int pos=11;
		while(!tmp.empty()){
			char c=tmp.front();
			tmp.pop();
			board[pos][j]=c;
			pos--;
		}
	}
}

int clear_round_puyo(){
	int chain=0;
	fill_n(&vis[0][0],14*8,0);
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
#ifdef __DEBUG__
			string log=to_string(i)+" "+to_string(j);
#endif
			if(vis[i][j]==1) {
#ifdef __DEBUG__
				print_config(log+" visited");
#endif
				continue;
			}
			if(board[i][j]=='.') continue;
			if(pop_puyo(i,j)==true) chain++;
		}
	}
	if(chain==0) return 0;
	fall_puyo();
#ifdef __DEBUG__
	print_board();
#endif
	return chain;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin>>board[i][j];
		}
	}

#ifdef __DEBUG__
	print_config("input");
	print_board();
#endif

	int ans=0;
	int cnt=0;
	while(1){
#ifdef __DEBUG__
		print_config(to_string(++cnt)+"th round");
#endif
		if(clear_round_puyo()==0) break;
		ans++;
	}

#ifdef __DEBUG__
	print_config("final board");
	print_board();
#endif
	cout<<ans<<"\n";
}

