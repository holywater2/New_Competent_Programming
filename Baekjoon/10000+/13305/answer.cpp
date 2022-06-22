#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 1000000001   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ull N, M;

int main(){
   #ifdef LOCAL
      freopen("data/data2.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<ull> dist = vector<ull>(N-1);
   vector<ull> price = vector<ull>(N-1);
   for(int i = 0; i < N-1; i++)
      sf1(dist[i]);
   for(int i = 0; i < N-1; i++)
      sf1(price[i]);
   sf1(M); //버림
   M = INF;
   ull res = 0;
   for(int i = 0; i < N-1; i++){
      if(M > price[i]) M = price[i];
      res += M*dist[i];
   }
   cout << res << '\n';

}
