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

const int mod = 15746;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dp[1000001];
int N;

int solve(int n){
   int& res = dp[n];
   if(res != 0) return res %= mod;
   return res = (solve(n-1) + solve(n-2)) % mod;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   dp[1] = 1; dp[2] = 2;
   for(int i = 1; i*50000 < N-1; i++){
      solve(i*50000);
   }
   for(int i = 1; i <=1000000; i++)
      solve(i);
   cout << solve(N) << '\n';
}
