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

int T, Q; // Q max 1e6

bool deleted[1000001];

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> T;
   while(T-- > 0){
      cin >> Q;
      priority_queue<pii> pq_max;
      priority_queue<pii,vector<pii>, greater<pii>> pq_min;
      memset(deleted, false, 1000001);
      for(int i = 0; i < Q; i++){
         string query;
         int num;
         cin >> query >> num;
         if(query == "I"){
            pq_max.push(pii(num,i));
            pq_min.push(pii(num,i));
         } else {
            if(num == 1){
               while(!pq_max.empty() && deleted[pq_max.top().second]){
                  pq_max.pop();
               }
               if(!pq_max.empty()){
                  deleted[pq_max.top().second] = true;
                  pq_max.pop();
               }
            } else {
               while(!pq_min.empty() && deleted[pq_min.top().second]){
                  pq_min.pop();
               }
               if(!pq_min.empty()){
                  deleted[pq_min.top().second] = true;
                  pq_min.pop();
               }
            }
         }
      }
      while(!pq_max.empty() && deleted[pq_max.top().second]){
         pq_max.pop();
      }
      while(!pq_min.empty() && deleted[pq_min.top().second]){
         pq_min.pop();
      }
      if(pq_max.empty()){
         cout << "EMPTY\n";
      } else {
         cout << pq_max.top().first << ' ' << pq_min.top().first << '\n';
      }
   }
}
