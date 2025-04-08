#include<iostream>
#include<algorithm>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int cost[1002][3];
// 3 stands for R,G,B
int cache[1002][3];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>cost[i][j];
		}
	}

	cache[1][0]=cost[1][0];
	cache[1][1]=cost[1][1];
	cache[1][2]=cost[1][2];

	for(int i=2;i<=n;i++){
		for(int j=0;j<3;j++){
			cache[i][j]=min(cache[i-1][(j+1)%3],cache[i-1][(j+2)%3])+cost[i][j];
		}
	}

	cout<<min({cache[n][0],cache[n][1],cache[n][2]})<<"\n";
}