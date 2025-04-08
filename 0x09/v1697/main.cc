#include<iostream>
#include<queue>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int N,K;
int dist[100002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin>>N>>K;

	fill(dist,dist+100001,-1);
	dist[N]=0;

	queue<int> q;
	q.push(N);
	
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(cur==K) {
			cout<<dist[cur];
			break;
		}
		for(int next : { cur+1,cur-1,2*cur}){
			if(next>100000 || next<0) continue;
			if(dist[next]!=-1) continue;
			dist[next]=dist[cur]+1;
			q.push(next);
		}
	}
}
