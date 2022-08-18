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
   vector<vector<pii>> vvi(N);
   for(int i = 0; i < M; i++){
      int u, v, w;
      cin >> u >> v >> w;
      vvi[u-1].push_back({v-1,w});
   }
   int st, fin;
   cin >> st >> fin;
   int dist[N];
   for(int i = 0; i < N; i++){
      dist[i] = INF;
   }
   dist[--st] = 0; 
   priority_queue<pii> pq;
   pq.push({0,st});
   while(!pq.empty()){
      auto cost = -pq.top().first;
      auto here = pq.top().second;
      pq.pop();
      
      if(dist[here] < cost) continue;

      for(int i = 0; i < vvi[here].size(); i++){
         int nextDist = cost + vvi[here][i].second;
         int there = vvi[here][i].first;

         if(dist[there] > nextDist){
            dist[there] = nextDist;
            pq.push({-nextDist,there});
         }
      }
   }
   pf1(dist[--fin]);
}
