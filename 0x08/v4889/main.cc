#include<iostream>
#include<stack>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt=1;

	while(true){
		string input;
		cin>>input;
		if(input[0]=='-') break;

		stack<char> s;
		s.push('#');
		int ans=0;

		for(int i=0;i<input.length();i++){
			if(s.top()=='{' && input[i]=='}')
				s.pop();
			else
				s.push(input[i]);
		}

		while(s.top()!='#'){
			if(s.top()=='}') {
				ans++;
				s.pop();
				s.pop();
			}
			else {
				s.pop();
				if(s.top()=='{') ans++;
				else ans+=2;
				s.pop();
			}
		}

		cout<<cnt<<". "<<ans<<"\n";
		cnt++;
	}
}