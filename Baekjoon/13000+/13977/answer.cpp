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

ll mod = 1e9 + 7;
ll fact[4000001];

ll pomod(ll a, ll b){
   if (b == 1)
      return a % mod;
   
   if (b & 1)
      return pomod(a, b - 1) * a % mod;
   
   return pomod(a * a % mod, b / 2);
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   fact[0] = fact[1] = 1;
   
   for (int i = 2; i <= 4000000; ++i)
      fact[i] = fact[i - 1] * i % mod;
      
   int t; cin >> t;
   while (t-->0)
   {
      int a, b; cin >> a >> b;
      cout << fact[a] * pomod(fact[a - b] * fact[b] % mod, mod - 2) % mod << '\n';
   }
}
