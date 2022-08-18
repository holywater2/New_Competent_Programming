#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
int dp[41];

int solve1(int n){
   if(n == 1 | n == 2){
      return 1;
   } else return solve1(n-1) + solve1(n-2);
}

int solve2(int n){
   if(n == 1 | n == 2){
      return 0;
   } else if(dp[n] == 0){
      dp[n] = 1;
      return 1 + solve2(n-1) + solve2(n-2);
   } else {
      return 0;
   }
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   dp[1] = 1;
   dp[2] = 1;
   cout << solve1(N) << " " << solve2(N) << '\n';


}
