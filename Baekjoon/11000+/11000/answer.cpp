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
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   priority_queue<pii,vector<pii>,greater<pii>> cl;
   multiset<int> ms;
   priority_queue<int,vector<int>,greater<int>> pq;
   for(int i = 0; i < N; i++){
      int s, f;
      cin >> s >> f;
      cl.push(pii(s,f));
   }
   for(int i = 0; i < N; i++){
      pii cur = cl.top();
      cl.pop();
      if(pq.empty()){
         pq.push(cur.second);
      } else {
         if(pq.top() <= cur.first){
            pq.pop();
         }
         pq.push(cur.second);
      }
   }
   cout << pq.size() << '\n';
}
