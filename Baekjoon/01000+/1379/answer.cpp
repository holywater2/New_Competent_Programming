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
int query[100000][3];

int N, M;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   priority_queue<pii, vector<pii>, greater<pii>> pq;
   priority_queue<pii, vector<pii>, greater<pii>> pq2;
   for(int i = 0; i < N; i++){
      int a, b, c;
      cin >> a >> b >> c;
      query[i][0] = a;
      query[i][1] = b;
      query[i][2] = c;

      pq.push({b,i});
   }
   vector<int> v(N+1);
   pq2.push({query[pq.top().second][2],1});
   v[query[pq.top().second][0]] = 1;

   pq.pop();

   for(int i = 1; i < N; i++){
      auto cur = pq.top();
      pq.pop();
      // pf2(pq2.top().first,cur.first);
      if(pq2.top().first <= cur.first){
         auto next = pq2.top();
         pq2.pop();
         // pf2(query[cur.second][0],next.first);
         // pf2(query[cur.second][0],next.second);
         pq2.push({query[cur.second][2],next.second});
         v[query[cur.second][0]] = next.second;
      } else{
         pq2.push({query[cur.second][2],pq2.size()+1});
         v[query[cur.second][0]] = pq2.size();
         // pf2(query[cur.second][0], pq2.size());
      }
   }
   cout << pq2.size() << '\n';
   for(int i = 1; i <= N; i++){
      cout << v[i] << '\n';
   }
}
