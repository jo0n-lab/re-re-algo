#include<iostream>  
#include<utility>  
#include<vector>  
using namespace std;

#define X first  
#define Y second

#define __DEBUG__  
#ifdef __DEBUG__  
#define __U1__  
#define __U2__  
#endif

int n;  
int board[22][22];  
int stage[22][22];  
int dx[4]={1,-1,0,0};  
int dy[4]={0,0,1,-1};

void print_config(string s){  
  cout.width(30);  
  cout.fill('-');  
  cout<<s<<"\n";  
}

void print_board(){  
  print_config(__func__);  
  for(int i=0;i<n;i++){  
    for(int j=0;j<n;j++){  
      cout<<board[i][j]<<" ";  
    }  
    cout<<"\n";  
  }  
  print_config("");  
}

void print_stage(){  
  print_config(__func__);  
  for(int i=0;i<n;i++){  
    for(int j=0;j<n;j++){  
      cout<<stage[i][j]<<" ";  
    }  
    cout<<"\n";  
  }  
  print_config("");  
}

void init_stage(){  
  for(int i=0;i<n;i++){  
    for(int j=0;j<n;j++){  
      stage[i][j]=board[i][j];  
    }  
  }  
}

void move(int dir){

  switch(dir){  
    case 0: // 0: up  
      for(int j=0;j<n;j++){  
        vector<int> v;  
        v.push_back(-1);  
        for(int i=0;i<n;i++){  
          if(stage[i][j]==0) continue;  
          if(v.back()==stage[i][j]){  
            v.pop_back();  
            v.push_back(stage[i][j]*2);  
            continue;  
          }  
          v.push_back(stage[i][j]);  
        }

        int pos=1;  
        for(;pos<v.size();pos++)  
          stage[pos-1][j]=v[pos];  
        pos--;  
        for(;pos<n;pos++)  
          stage[pos][j]=0;  
      }  
      break;

    case 1:  
      for(int j=0;j<n;j++){  
        vector<int> v;  
        v.push_back(-1);  
        for(int i=n-1;i>=0;i--){  
          if(stage[i][j]==0) continue;  
          if(v.back()==stage[i][j]){  
            v.pop_back();  
            v.push_back(stage[i][j]*2);  
            continue;  
          }  
          v.push_back(stage[i][j]);  
        }

        int pos=1;  
        for(;pos<v.size();pos++)  
          stage[n-pos][j]=v[pos];  
        pos=n-pos;  
        for(;pos>=0;pos--)  
          stage[pos][j]=0;  
      }  
      break;

    default:  
      cout<<"wrong dir input"<<"\n";  
      break;  
  }  
}

int main(){  
  ios::sync_with_stdio(false);  
  cin.tie(NULL);

  cin>>n;  
  for(int i=0;i<n;i++){  
    for(int j=0;j<n;j++){  
      cin>>board[i][j];  
    }  
  }

#ifdef __DEBUG__  
  print_board();  
#endif

#ifdef __U1__  
  init_stage();  
  move(1);  
  print_stage();  
  move(1);  
  print_stage();  
#endif

//  int n_round=1<<(2*5);  
//  for(int r=0;r<n_round;r++){  
//    init_stage();  
//    int cur=r;  
//    for(int level=0;level<5;level++){  
//      move(cur%4);  
//      cur/=4;  
//    }  
//  }

}
