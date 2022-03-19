#include <bits/stdc++.h>

using namespace std;

int dp[100005][11][11];
int mx[100005][11][11];

int a[100005];

const int INF = 1000000007;

int main()
{

  int k1, k2;

  int N;
  scanf("%d%d%d", &N, &k1, &k2);

  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &a[i]);
  }

  sort(a + 1, a + 1 + N, greater<int>());

  memset(dp, 0, sizeof(dp));

  for (int i = 0; i <= N; i++)
  {
    for (int k = 0; k < k1; k++)
    {
      for (int j = 0; j < k2; j++)
      {
        mx[i][k][j] = -INF;
      }
    }
  }

  mx[0][0][0] = 0;
  dp[0][0][0] = 1;

  for (int i = 1; i <= N; i++)
  {
    for (int k = 0; k < k1; k++)
    {
      for (int j = 0; j < k2; j++)
      {
        int tmp_x = (k + a[i] % k1 + k1) % k1;
        int tmp_y = (j + a[i] % k2 + k2) % k2;

        if (mx[i - 1][k][j] != -INF)
        {
          // printf("%d %d\n",tmp_x, tmp_x);
          if (mx[i][tmp_x][tmp_y] < mx[i - 1][k][j] + a[i])
          {
            dp[i][tmp_x][tmp_y] = dp[i - 1][k][j];
            mx[i][tmp_x][tmp_y] = mx[i - 1][k][j] + a[i];
          }
          else if (mx[i][tmp_x][tmp_y] == mx[i - 1][k][j] + a[i])
          {
            dp[i][tmp_x][tmp_y] = dp[i][tmp_x][tmp_y] + dp[i - 1][k][j];
          }
        }
      }
    }

    for (int k = 0; k < k1; k++)
    {
      for (int j = 0; j < k2; j++)
      {
        if (mx[i - 1][k][j] != -INF)
        {
          if (mx[i][k][j] < mx[i - 1][k][j])
          {
            mx[i][k][j] = mx[i - 1][k][j];
            dp[i][k][j] = dp[i - 1][k][j];
          }
          else if (mx[i][k][j] == mx[i - 1][k][j])
          {
            dp[i][k][j] = dp[i][k][j] + dp[i - 1][k][j];
          }
        }
      }
    }
  }

  long long ans = 0;
  int maxl = -INF - 1;

  for (int i = 1; i < k2; i++)
  {
    maxl = max(maxl, mx[N][0][i]);
  }

  for (int i = 1; i < k2; i++)
  {
    if (maxl == mx[N][0][i])
    {
      ans = ans + dp[N][0][i];
    }
  }

  cout << ans << endl;

  return 0;
}