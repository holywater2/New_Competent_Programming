#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
int dp[1000001];
int dp2[1000001];


int solve(int n){
   // pf1(n);
   if(n == 1 || n == 0) return 0;
   int& res = dp[n];
   if(res != -1) return res;
   int min = INF;
   if(n % 3 == 0 & min > solve(n/3)){
      min = dp[n/3];
      dp2[n] = n/3;
   }
   if(n % 2 == 0 & min > solve(n/2)){
      min = dp[n/2];
      dp2[n] = n/2;
   }
   if(min > solve(n-1)){
      min = dp[n-1];
      dp2[n] = n-1;
   }
   return res = min + 1;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   memset(dp,-1,sizeof(dp[0])*(N+1));
   dp[1] = 0;
   int t = 100000;
   while(t < N){
      solve(t);
      t += 100000;
   }
   solve(N);
   cout << dp[N] << '\n';
   cout << N;

   while(N != 1){
      N = dp2[N];
      cout << ' ' << N;
   }
   cout << '\n';
}
