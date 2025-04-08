#include <iostream>

#define __DEBUG__
#define __PRINT__
#define __INPUT__

using namespace std;

int N, K;
int coin[11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> coin[i];
  }

  int cur = K;
  int pos = N;
  int ans = 0;

  while (cur != 0 && pos >= 0) {
    ans += cur / coin[pos];
    cur %= coin[pos--];
  }

  cout << ans;
}
