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

ll N, M;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   ll res = 0;
   ll Nres = 0;
   ll count = 2;
   N -= 1;
   while(M >= count/2){
      if(N >= count/2){
         res -= (N/count)*(count/2);
         ll temp = (N%count) - (count-1)/2;
         if(temp > 0)
            res -= temp;
      }
      res += (M/count)*(count/2);
      ll temp = (M%count) - (count-1)/2;
      if(temp > 0)
         res += temp;
      count *= 2;
   }
   // cout << Nres << ' ' << res << '\n';
   pf1(res);
}
