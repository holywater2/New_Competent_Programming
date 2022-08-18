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

int N, M, K, X;

vector<vector<pii>> adj;
vector<int> route;
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
            route[there] = here;
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
   route = vector<int>(N,-1);
   for(int i = 0; i < M; i++){
      int dep,dst,cost;
      cin >> dep >> dst >> cost;
      adj[dep-1].push_back({dst-1,cost});
   }
   int dep, dst;
   cin >> dep >> dst;
   dep--;dst--;
   auto res = dijk(dep);
   vector<int> rr;
   rr.push_back(dst);
   while(true){
      int cur = rr.back();
      int next = route[cur];
      if(next == -1) break;
      rr.push_back(next);
   }
   cout << res[dst] << '\n';
   cout << rr.size() << '\n';
   for(int i = 0; i < rr.size(); i++){
      cout << rr[rr.size()-1-i]+1 << ' ';
   }
   cout << '\n';
}
