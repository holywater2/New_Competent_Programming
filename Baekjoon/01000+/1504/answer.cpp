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
vector<vector<pii>> adj;


vector<int> dijk(int dep){
   vector<int> dist(N,INF);
   dist[dep] = 0;
   priority_queue<pii> pq;
   pq.push({0,dep});
   while(!pq.empty()){
      int cost = -pq.top().first;
      int here = pq.top().second;
      pq.pop();
      if(dist[here] < cost) continue;

      for(auto next : adj[here]){
         int nextDist = cost + next.second;
         int there = next.first;

         if(nextDist < dist[there]){
            dist[there] = nextDist;
            pq.push({-nextDist,there});
         }
      }
   }
   return dist;
}


int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   adj = vector<vector<pii>>(N);
   for(int i = 0; i < M; i++){
      int s,f,c;
      cin >> s >> f >> c;
      adj[s-1].push_back({f-1,c});
      adj[f-1].push_back({s-1,c});
   }
   int pa,pb;
   cin >> pa >> pb;
   pa--;pb--;
   auto dd = dijk(0);
   int ad = dd[pa]; // 0 to a
   int bd = dd[pb]; // 0 to b
   dd = dijk(pa);
   int ab = dd[pb]; // a to b

   int al = dd[N-1]; // a to N
   int bl = dijk(pb)[N-1]; // b to N
   int path1 = ad + ab + bl;
   if(ad == INF || ab == INF || bl == INF){
      path1 = INF;
   }
   int path2 = bd+ab+al;
   if(bd == INF || ab == INF || al == INF){
      path2 = INF;
   }
   int res = min(path1,path2);
   if(res >= INF) pf1(-1);
   else pf1(res);
}
