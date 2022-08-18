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
// int query[100000][2];

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
   priority_queue<int, vector<int>, greater<int>> pq2;
   for(int i = 0; i < N; i++){
      int a, b, c;
      cin >> a >> b >> c;
      pq.push({b,c});
   }
   pq2.push(pq.top().second);
   pq.pop();

   for(int i = 1; i < N; i++){
      auto cur = pq.top();
      pq.pop();

      if(pq2.top() <= cur.first){
         pq2.pop();
      }
      pq2.push(cur.second);
   }
   cout << pq2.size() << '\n';
}
