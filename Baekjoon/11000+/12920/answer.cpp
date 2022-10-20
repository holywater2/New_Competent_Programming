#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a
#define pf1(a)      cout << a << '\n'
#define pf2(a,b)    cout << a << ' ' << b << '\n'
#define pf3(a,b,c)  cout << a << ' ' << b << ' ' << c << '\n'
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF         987654321

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
// int V[101],C[101],K[101];
int dp[10001];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   for(int i = 0; i < N; i++){
      int v,c,k; cin >> v >> c >> k;
      for(int j = 1; k > 0; j <<= 1){
         int ix = min(j,k);
         for(int k = M; k >= ix*v; k--){
            dp[k] = max(dp[k-ix*v] + ix*c, dp[k]);
         }
         k -= ix;
      }
   }
   int res = 0;
   for(int i = 0 ; i <= M; i++){
      res = max(res,dp[i]);
   }
   cout << res << '\n';
}
