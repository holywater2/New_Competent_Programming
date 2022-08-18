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
long dp[101];
int N, M;

long solve(int n){
   long& res = dp[n];
   if(res != 0) return res;
   return res = solve(n-1) + solve(n-5);
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5]  = 2;
   dp[6] = 3; dp[7] = 4; dp[8] = 5; dp[9] = 7; dp[10] = 9;
   while(N-- > 0){
      cin >> M;
      cout << solve(M) << '\n';
   }
}
