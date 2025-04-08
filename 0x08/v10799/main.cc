#include<iostream>
#include<stack>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string bar;
	cin>>bar;

	stack<char> s;

	int ans=0;

	s.push(bar[0]);
	for(int i=1;i<bar.length();i++){
		if(bar[i]=='(') s.push('(');
		else if(bar[i-1]=='('){
			s.pop();
			ans+=s.size();
		}
		else {
			s.pop();
			ans++;
		}
	}

	cout<<ans<<"\n";
}

