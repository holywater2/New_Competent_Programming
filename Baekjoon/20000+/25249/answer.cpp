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

priority_queue<pii, vector<pii>, greater<pii>> pq[100000];

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
   int gmax = 0;
   for(int i = 0; i < M; i++){
      int a, b, c;
      cin >> a >> b >> c;
      pq[a].push({b,c});
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

   int smax = upper_bound(all(cp),gmax)-cp.begin();
   for(int j = smax; j < cp.size(); j++){
      // pf3("here",j,cp[j]);
      res[cp[j]] = -1;
   }
   for(int i = 1; i < N; i++){
      int idx = 0; // idx < cp.size();
      while(!pq[i].empty() && idx < smax){
         auto cur = pq[i].top();
         pq[i].pop();
         // pf2(cur.first,cur.second);
         while(idx < smax){
            // pf3(idx,cp[idx],cur.second);
            if(cp[idx] <= cur.second){
               res[cp[idx]] += cur.first;
               idx++;
            } else {
               break;
            }
         }
      }
      if(idx != smax){
         for(int j = idx; j < smax; j++){
            // pf3("here",j,cp[j]);
            res[cp[j]] = -1;
         }
         smax = idx;
      }
   }
   for(int i = 0; i < vv.size(); i++){
      if(res[vv[i]] == -1){
         cout << "impossible" << '\n';
      } else {
         // pf1(vv[i]);
         cout << res[vv[i]] << '\n';
      }
   }
}
