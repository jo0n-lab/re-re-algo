#include<iostream>
#include<utility>
#include<vector>
using namespace std;

//#define __DEBUG__

#define X first
#define Y second

int board[10][10];
int cache[10][10];
int n,m;
int cam_dirs[6]={0,4,2,4,4,1};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<pair<int,int>> cam;

void print_config(string s){
	cout.width(30);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_cache(){
	print_config(__func__);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<cache[i][j]<<" ";
		}
		cout<<"\n";
	}
	print_config("");
}


void init_snapshot(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]==6) cache[i][j]=1;
			else cache[i][j]=0;
		}
	}
}

void rotate(pair<int,int> pos,int rot){
	int cam_type=board[pos.X][pos.Y];
	vector<int> dirs;
#ifdef __DEBUG__
	print_config("cam type: "+to_string(cam_type));
#endif
	if(cam_type==1) dirs={rot};
	else if(cam_type==2) dirs={rot,(rot+2)%4};
	else if(cam_type==3) dirs={rot,(rot+1)%4};
	else if(cam_type==4) dirs={rot,(rot+1)%4,(rot+2)%4};
	else if(cam_type==5) dirs={rot,(rot+1)%4,(rot+2)%4,(rot+3)%4};
	
	for(auto dir:dirs){
#ifdef __DEBUG__
	print_config("cur dir: "+to_string(dir));
#endif
	pair<int,int> cur=pos;
		while(true){
			if(cur.X>=n||cur.X<0||cur.Y>=m||cur.Y<0) break;
			if(board[cur.X][cur.Y]==6) break;
			cache[cur.X][cur.Y]=1;
			cur={cur.X+dx[dir],cur.Y+dy[dir]};
		}
	}
}

int get_gray(){
	int area=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cache[i][j]==0) area++;
		}
	}
	return area;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	int n_case=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int input;
			cin>>input;
			board[i][j]=input;
			if(input>0 && input<6){
				cam.push_back({i,j});
				n_case*=cam_dirs[input];
			}
		}
	}

	int ans=100;
	for(int c=0;c<n_case;c++){
		int cur_case=c;
		init_snapshot();
		for(auto cur:cam){
			int cam_type=board[cur.X][cur.Y];
			int rot=cur_case%cam_dirs[cam_type];
			cur_case/=cam_dirs[cam_type];
			rotate(cur,rot);
		}
		ans=min(ans,get_gray());
#ifdef __DEBUG__
		print_cache();
#endif
	}

	cout<<ans<<"\n";
}
