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

priority_queue<ll, vector<ll>,greater<ll>> pq;
map<ll, bool> check;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   vector<ll> v = vector<ll>(N);
   for(int i = 0; i < N; i++){
      cin >> v[i];
      pq.push(v[i]);
   }
   ll cmax = v[N-1];
   for(int i = 0; i < M-1; i++){
      ll cur = pq.top();
      pq.pop();
      for(int j = 0; j < N; j++){
         ll next = v[j]*cur;
         if(check.count(next)) continue;
         if(pq.size() >= M){
            if(next < cmax){
               pq.push(next);
               check[next] = true;
            }
         } else{
            cmax = max(cmax,next);
            pq.push(next);
            check[next] = true;
         } 
      }
   }
   cout << pq.top() << '\n';
}
