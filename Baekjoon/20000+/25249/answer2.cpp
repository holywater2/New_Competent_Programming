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

// priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<pii> pq;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
int visited[100001];
int query[100001][2];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   int gmax = 0;
   for(int i = 0; i < M; i++){
      int a, b, c;
      cin >> a >> b >> c;
      query[i][0] = a;
      query[i][1] = b;
      pq.push({c,i});
      gmax = max(gmax,c);
   }
   int q; cin >> q;
   vector<int> vv(q);
   map<int, int> res;
   for(int i = 0; i < q; i++){
      cin >> vv[i];
      res[i] = 0;
   }
   vector<int> cp(vv);
   sort(all(cp));
   cp.erase(unique(cp.begin(),cp.end()),cp.end());

   // int smax = upper_bound(all(cp),gmax)-cp.begin();
   // for(int j = smax; j < cp.size(); j++){
   //    // pf3("here",j,cp[j]);
   //    res[cp[j]] = -1;
   // }
   int path = 0;
   int count = 0;
   for(int i = 0; i < cp.size(); i++){
      int weight = cp[cp.size()-i-1];
      while(!pq.empty()){
         auto cur = pq.top();
         if(weight > cur.first){
            break;
         }
         pq.pop();
         pf3(weight,cur.first,cur.second);
         int city = query[cur.second][0];
         int cost = query[cur.second][1];
         if(visited[city] == 0){
            count++;
            visited[city] = cost;
            path += cost;
         } else if(visited[city] > cost){
            path += cost - visited[city];
            visited[city] = cost;
         }
         pf2(path,count);
      }
      if(count == N-1){
         res[weight] = path;
      }
   }
   for(int i = 0; i < vv.size(); i++){
      if(res[vv[i]] == 0){
         cout << "impossible" << '\n';
      } else {
         // pf1(vv[i]);
         cout << res[vv[i]] << '\n';
      }
   }
}
