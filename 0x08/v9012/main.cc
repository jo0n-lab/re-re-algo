#include <iostream>
#include <stack>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int T;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>T;

	for(int i=0;i<T;i++){
		string line;
		cin>>line;
		
		stack<char> s;
		s.push('#');

		for(int j=0;j<line.length();j++){
			if(line[j]=='(')
				s.push(line[j]);
			else if(line[j]==')'){
				if(line[j]==')' && s.top()=='(')
					s.pop();
				else
					s.push(line[j]);
			}
		}

		if(s.top()=='#') cout<<"YES";
		else cout<<"NO";
		cout<<"\n";
	}
}