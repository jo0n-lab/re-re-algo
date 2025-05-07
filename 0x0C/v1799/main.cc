#include <iostream>
using namespace std;

//#define __DEBUG__

int board[12][12];
int diag1[24];
int diag2[24];
int n;
int tmp = 0;
int ans = 0;

int max(int a, int b) {
  if (a >= b)
    return a;
  return b;
}

void print_config(string s) {
  cout.width(30);
  cout.fill('-');
  cout << s << "\n";
}

void print_board() {
  print_config(__func__);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0)
        cout << "#";
      else if (board[i][j] == -1)
        cout << "1";
      else
        cout << "0";
      cout << " ";
    }
    cout << "\n";
  }
}

void bishop(int d1) {
  if (d1 == 2 * n - 1) return;
  int flag=0;
  for (int d2 = (d1 + n - 1) % 2; d2 < 2 * n - 1; d2 += 2) {
    int i = (d1 - d2 + n - 1) / 2;
    int j = (d1 + d2 - n + 1) / 2;
    if (i < 0 || i >= n || j < 0 || j >= n) continue;
    if (board[i][j] == 0) continue;
    if (diag2[d2] == 1) continue;
    flag=1;
    diag2[d2] = 1;
    tmp++;
    ans = max(tmp, ans);
#ifdef __DEBUG__
    board[i][j] = -1;
    print_config(to_string(tmp) + " case");
    print_board();
#endif
    bishop(d1 + 1);
    tmp--;
    diag2[d2] = 0;
#ifdef __DEBUG__
    board[i][j] = 1;
#endif
  }
  if(flag==0) bishop(d1+1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

#ifdef __DEBUG__
   print_board();
#endif

   bishop(0);
   cout << ans << "\n";
}
