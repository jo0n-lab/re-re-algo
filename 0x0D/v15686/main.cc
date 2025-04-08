#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

#define X first
#define Y second

//#define __DEBUG__

void print_config(string s){
   cout.width(30);
   cout.fill('-');
   cout<<s<<"\n";
}

vector<pair<int,int>> house;
vector<pair<int,int>> chick;
int n,m;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin>>n>>m;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         int input;
         cin>>input;
         if(input==1) house.push_back({i,j});
         if(input==2) chick.push_back({i,j});
      }
   }

   int ans=0x7f7f7f7f;
   vector<int> temp(chick.size(),0);
   fill(temp.begin(),temp.begin()+m,1);

#ifdef __DEBUG__
      print_config("print temp");
      for(auto t:temp)
      cout<<t<<" ";
   cout<<"\n";
   print_config("");
#endif

   do{
      int dist=0;
      vector<pair<int,int>> sel;
      for(int i=0;i<temp.size();i++){
         if(temp[i]==0) continue;
         sel.push_back(chick[i]);
      }
      for(auto h:house){
         int tmp=0x7f7f7f7f;
         for(auto c:sel){
            tmp=min(tmp,abs(h.X-c.X)+abs(h.Y-c.Y));
         }
         dist+=tmp;
      }

      ans=min(ans,dist);
   }while(prev_permutation(temp.begin(),temp.end()));
   cout<<ans<<"\n";
}
