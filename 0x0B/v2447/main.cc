#include<iostream>
using namespace std;

char board[6600][6600];
char unit[3][3]={
	{'*','*','*'},
	{'*',' ','*'},
	{'*','*','*'}
};
int n;

void draw(int d,int xpos,int ypos){
	if(d==3){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				board[xpos+i][ypos+j]=unit[i][j];
			}
		}
		return;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==1 && j==1) continue;
			draw(d/3,xpos+i*d/3,ypos+j*d/3);
		}
	}
	return;
}

void print_board(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j];
		}cout<<"\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill_n(&board[0][0],6600*6600,' ');
	cin>>n;

	draw(n,0,0);

	print_board();
}

