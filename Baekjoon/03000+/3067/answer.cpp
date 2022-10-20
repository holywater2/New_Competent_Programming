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

int dp[10001];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int T; cin >> T;
   for(int i = 0; i < T; i++){
      cin >> N;
      memset(dp,0,sizeof(dp));
      vector<int> coins(N);
      for(int j = 0; j < N; j++){
         cin >> coins[j];
      }
      int M; cin >> M;
      dp[0] = 1;
      for(int j = 0; j < N; j++){
         for(int l = coins[j]; l <= M; l++){
               dp[l] += dp[l-coins[j]];
         }
      }
      cout << dp[M] << '\n';
   }
}
