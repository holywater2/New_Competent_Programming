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


int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   vector<int> v(3);
   cin >> v[0] >> v[1] >> v[2];
   sort(all(v));
   ll res = 0;
   for(int i = 1; i <= v[0]; i++){
      ll temp = (v[2]-v[1]) * 6;
      ll temp2 = 
      // ll temp = max(0,min(v[2]-2*i,v[1]-i));
      // res += max(0,min(v[2]-2*i,v[1]-i));
   }

   if(res < 0) res = 0;
   cout << res << '\n';
}
