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
int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   vector<vector<int>> dist(N+1,vector<int>(N+1,INF));
   for(int i = 0; i < M; i++){
      int s,d;
      cin >> s >> d;
      dist[s][d] = 1;
      dist[d][s] = 1;
   }
   for(int i = 1; i <= N; i++) dist[i][i] = 0;

   for(int m = 1; m <= N; m++){
      for(int i = 1; i <= N; i++){
         for(int j = 1; j <= N; j++){
            dist[i][j] = min(dist[i][j],dist[i][m] + dist[m][j]);
         }
      }
   }
   int res = INF;
   int idx = -1;
   for(int i = 1; i <= N; i++){
      int lsum = 0;
      for(int j = 1; j <= N; j++){
         lsum += dist[i][j];
      }
      if(res > lsum){
         idx = i;
      }
      res = min(res,lsum);
   }
   pf1(idx);
}
