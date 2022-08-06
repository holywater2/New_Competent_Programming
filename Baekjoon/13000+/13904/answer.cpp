#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;
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
   // priority_queue<pii,vector<pii>,greater<pii>> pq;
   priority_queue<pii> pq;
   priority_queue<pii> pq2;
   cin >> N;
   for(int i = 0; i < N; i++){
      int d,w;
      cin >> d >> w;
      pq.push({d,w});
   }
   int res = 0;
   int d = pq.top().first;
   while(d > 0){
      while(!pq.empty()){
         pii cur = pq.top();
         if(cur.first < d){
            break;
         }
         pq.pop();
         pq2.push({cur.second,cur.first});
      }
      if(!pq2.empty()){
         pii cur = pq2.top();
         pq2.pop();
         // d: 현재 날짜
         // 만약에 지금 최대 weight 숙제의 due가 현재 날짜보다 앞선다면 pop
         // 만약 지금 숙제의 듀가 아직 남았다면 가능
         res += cur.first;
      }
      // pf2(cur.first,cur.second);
      // pf1(d);
      d--;
   }
   cout << res << '\n';
}
// 60 4/ 50 2/ 40 4/ 30 3/ 20 1/ 10 4/ 5 6/
// 2 5 7 제일 작은 수: 2
// 5 7 10 14 그 다음 작은 수 4
// 5 7 10 14 8 20 28

