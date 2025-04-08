#include <iostream>
#include <stack>

using namespace std;
//#define __INPUT__
//#define __DEBUG__
//#define __PRINT__

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true){
		string line;
		getline(cin,line);
		if(line==".")
			break;

#ifdef __PRINT__
		cout<<line<<"\n";
#endif

		stack<char> s;
		s.push('#');

		for(int i=0;i<line.length();i++){
			if(line[i]=='[' || line[i]=='(')
				s.push(line[i]);

			else if(line[i]==']' || line[i]==')'){
				if(s.top()=='[' && line[i]==']')
					s.pop();
				else if(s.top()=='(' && line[i]==')')
					s.pop();
				else
					s.push(line[i]);
			}
		}

		if(s.top()!='#') cout<<"no";
		else cout<<"yes";

		cout<<"\n";
	}
}






