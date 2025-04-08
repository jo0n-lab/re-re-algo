#include <iostream>
#include <stack>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int N;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	int ans=0;

	for(int i=0;i<N;i++){
		string input;
		cin>>input;

		stack<char> s;
		s.push('#');

		for(int j=0;j<input.length();j++){
			if(input[j]==s.top()) s.pop() ;
			else s.push(input[j]);
		}

		if(s.top()=='#') ans++;
	}

	cout<<ans<<"\n";
}









