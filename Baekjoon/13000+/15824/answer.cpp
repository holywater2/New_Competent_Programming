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

ll modpow(ll x, ll y, ll mod){
   ll res = 1;
   ll pow = x%mod;
   while(y){
      if(y & 1) res = res * pow % mod;
      pow = pow * pow % mod;
      y >>= 1;
   }
   return res;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<ll> v(N);
   for(int i = 0; i < N; i++){
      cin >> v[i];
   }
   sort(all(v));
   ll mod = 1000000007;

   vector<ll> vsum(N+1);
   for(int i = 0; i < N; i++){
      vsum[i+1] = (vsum[i] + v[i]) % mod; 
   }
   ll res = 0;
   for(int i = 1; i <= N-1; i++){
      res = (res + (vsum[N]-vsum[N-i]-vsum[i])*modpow(2,i-1,mod)) % mod;
      if(res < 0) res += mod;
   }
   cout << res << '\n';
}
