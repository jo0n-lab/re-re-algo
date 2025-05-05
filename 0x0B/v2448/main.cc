#include<iostream>
using namespace std;

int n;
char board[6*1030][6*1030];
char unit[3][5]={
	{' ',' ','*',' ',' '},
	{' ','*',' ','*',' '},
	{'*','*','*','*','*'}
};

void draw(int d,int xpos,int ypos){
	if(d==1) {
		for(int i=0;i<3;i++){
			for(int j=0;j<5;j++){
				board[xpos+i][ypos+j]=unit[i][j];
			}
		}
		return;
	}
	draw(d/2,xpos,ypos+6*d/4);
	draw(d/2,xpos+3*d/2,ypos);
	draw(d/2,xpos+3*d/2,ypos+12*d/4);
	return;
}

void print_board(){
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n;j++){
			cout<<board[i][j];
		}cout<<"\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill_n(&board[0][0],6*1030*6*1030,' ');

	cin>>n;
	draw(n/3,0,0);
	print_board();
}