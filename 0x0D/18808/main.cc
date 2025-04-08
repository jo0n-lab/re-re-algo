#include<iostream>
#include<utility>
#include<queue>

using namespace std;

#define __DEBUG__
#define __INPUT__
#ifdef __DEBUG__
#define __U1__
#define __U2__
#endif

int n,m,k;
int board[42][42];
struct stk{
   int r;
   int c;
   int shape[12][12];
};
stk sticker[102];

void print_config(string s){
   cout.width(30);
   cout.fill('-');
   cout<<s<<"\n";
}

void print_board(){
   print_config(__func__);
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cout<<board[i][j];
      }
      cout<<"\n";
   }
   print_config("");
}

void print_sticker(int idx){
   print_config(__func__);
   stk s=sticker[idx];
   for(int i=0;i<s.r;i++){
      for(int j=0;j<s.c;j++){
         cout<<s.shape[i][j];
      }
      cout<<"\n";
   }
   print_config("");
}

void rotate(int idx){
   stk src=sticker[idx];
   stk dst;
   int r=src.r;
   int c=src.c;
   for(int i=0;i<src.c;i++){
      for(int j=0;j<src.r;j++){
         dst.shape[i][j]=src.shape[
   

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin>>n>>m>>k;
   for(int t=0;t<k;t++){
      stk tmp;
      cin>>tmp.r>>tmp.c;
      for(int i=0;i<tmp.r;i++){
         for(int j=0;j<tmp.c;j++){
            cin>>tmp.shape[i][j];
         }
      }
      sticker[t]=tmp;
   }

#ifdef __INPUT__
   for(int t=0;t<k;t++)
      print_sticker(t);
#endif
}



