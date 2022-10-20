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
typedef long long ll;

ll argl[200000][3];
ll quest[200000];

set<ll> hs;
vector<ll> dir;
vector<int> seg;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

// Segment tree functions
void update(int node, int lo, int hi, int idx){
   if(idx < lo || idx > hi) return;
   if(lo == hi){
      seg[node] += 1;
      return;
   }
   update(node*2,lo,(lo+hi)/2,idx);
   update(node*2+1,(lo+hi)/2+1,hi,idx);
   seg[node] = seg[node*2] + seg[node*2+1];
}

int query(int node, int lo, int hi, int l, int r){
   if(hi < l || lo > r) return 0;
   if(l <= lo && hi <= r){
      return seg[node];
   }
   int lsum = query(node*2,lo,(lo+hi)/2,l,r);
   int rsum = query(node*2+1,(lo+hi)/2+1,hi,l,r);
   return lsum + rsum;
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N; // Number of Query Q

   // Part 1. data 전처리 구문
   // (1) 모든 쿼리를 받아들여서 저장을 함
   // (2) 1번 쿼리가 주어지면, b/a가 int이면 set hs에 넣고, double(b/a)를 quest에 저장함
   // (3) 2번 쿼리가 주어지면, c를 vector dir에 넣고, c가 set hs에 있으면 quest에 -1을 저장함
   for(int i = 0; i < N; i++){
      cin >> argl[i][0];
      if(argl[i][0] == 1){ // query 1
         cin >> argl[i][1] >> argl[i][2];
         // case 1: a == 0, do nothing
         // case 2: a != 0, preprocess -> make ceil(-b/a)
         if(argl[i][1] != 0){
            if(argl[i][2] % argl[i][1] == 0)
               hs.insert(argl[i][2]/argl[i][1]);
            quest[i] = (ll)floor(-argl[i][2]/(long double)argl[i][1]);
         }
      } else { // query 2
         cin >> argl[i][1];
         dir.pb(argl[i][1]);
         if(hs.count(-argl[i][1]) != 0){
            quest[i] = -1;
         }
      }
   }

   // Part 2. segment 트리 build 구문
   // (1) 좌표압축을 위해서 dir의 원소를 unique한 것만 남김
   // (2) dir의 원소를 가지고 segment 트리를 만듬
   sort(all(dir));
   dir.erase(unique(all(dir)),dir.end());
   // for(auto a: dir){
   //    cout << a << " ";
   // }
   // cout << '\n';

   int h = (int)ceil(log2(dir.size()));
   int tree_size = (1 << (h+1));
   seg = vector<int>(tree_size);

   int dsize = dir.size();
   int sign = 1;


   // Part 3. 쿼리 처리 구문
   // (1) 1번 쿼리에서 a == 0일 경우, a,b 둘 다 0이 되는 경우가 있을 수 있음. 이때는 나머지는 다 0
   //                               b != 0일 경우에는 b의 부호가 전체 부호에 영향을 미침
   // (2) 1번 쿼리에서 -b/a보다 작은 c의 위치를 찾음
   for(int i = 0; i < N; i++){
      if(argl[i][0] == 1){
         if(argl[i][1] == 0){ // x에 영향을 받지 않음 -> 부호만 바꿈
            if(argl[i][2] == 0) sign = 0;
            else if(argl[i][2] < 0) sign *= -1;
         } else {
            if(argl[i][1] < 0) sign *= -1; // a의 부호를 밖으로 빼줌
            double cur  = -(double)argl[i][2]/argl[i][1];
            // pf2(i,cur);
            if(cur >= dir.front()){
               auto it = lower_bound(all(dir),cur);
               int idx = it-dir.begin();
               if(it == dir.end()) idx--;
               update(1,0,dsize-1,idx);
            }
         }
      } else {
         if(quest[i] == -1 || sign == 0){
            cout << 0 << '\n';
         } else {
            int cidx = lower_bound(all(dir),argl[i][1])-dir.begin();
            // pf2(cidx,query(1,0,dsize-1,cidx,dsize-1));
            int res = (query(1,0,dsize-1,cidx,dsize-1)%2)*-2+1;
            // pf1(cidx);
            // pf2(res,sign);
            if(res*sign < 0){
               cout << '-' << '\n';
            } else {
               cout << '+' << '\n';
            }
         }
      }
   }
}
