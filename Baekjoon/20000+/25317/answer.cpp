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

ll armg[200000][3];
set<ll> hs;
vector<ll> dir;
vector<int> seg;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

void update(int node, int lo, int hi, int idx){
   if(idx < lo || idx > hi) return;
   if(lo == hi){
      seg[node] += 1;
      return;
   }
   update(node*2,lo,(lo+hi)/2,idx);
   update(node*2,(lo+hi)/2+1,hi,idx);
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
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   
   for(int i = 0; i < N; i++){
      cin >> armg[i][0];
      if(armg[i][0] == 1){
         cin >> armg[i][1] >> armg[i][2];
         if(armg[i][1] != 0){
            if(armg[i][2] % armg[i][1] == 0){
               hs.insert((ll)(armg[i][2]/armg[i][1]));
               // pf1(armg[i][2]/armg[i][1]);
            }
            
            dir.pb((ll)(ceil(armg[i][2]/(double)armg[i][1])));
         }
      } else {
         cin >> armg[i][1];
      }
   }

   sort(all(dir));
   dir.erase(unique(all(dir)),dir.end());

   int tree_size = (int)ceil(log2(dir.size()+2))*2+2;

   seg = vector<int>(tree_size);

   int dsize = dir.size();
   int sign = 1;

   for(int i = 0; i <dsize; i++){
      cout << dir[i] << ' ';
   } cout << '\n';

   int kkk = 1;
   for(int i = 0; i <tree_size; i++){
      cout << seg[i] << ' ';
      if(i%kkk == kkk-1){
         cout << '\n';
         kkk*=2;
      }
   } cout << '\n';

   for(int i = 0; i < N; i++){
      if(armg[i][0] == 1){
         if(armg[i][1] == 0){
            if(armg[i][2] == 0) sign = 0;
            else if(armg[i][2] < 0) sign *= -1;
         } else {
            if(armg[i][1] < 0) sign *= -1;
            auto idx = lower_bound(all(dir),(ll)ceil(armg[i][2]/(double)armg[i][1])) -dir.begin();
            pf2(idx,(ll)ceil(armg[i][2]/(double)armg[i][1]));
            update(1,0,dsize,idx+1);
            int kkk = 1;
            for(int i = 0; i <tree_size; i++){
               cout << seg[i] << ' ';
               if(i%kkk == kkk-1){
                  cout << '\n';
                  kkk*=2;
               }
            } cout << '\n';
         }
      } else {
         // if(hs.find(-armg[i][1]) == hs.end()){
         //    pf2(*hs.find(armg[i][1]),armg[i][1]);
         //    // pf2(*(hs.find(armg[i][1])-1),armg[i][1]);
         // }

         if(hs.find(-armg[i][1]) != hs.end()){
            cout << 0 << '\n';
         } else {
            long long mc = -armg[i][1];
            int res = 1;
            if(mc >= dir[0]){
               int idx = lower_bound(all(dir),mc)-dir.begin();
               pf1(idx);
               pf2(*lower_bound(all(dir),mc),mc);
               res = query(1,0,dsize,0,idx+1);
               pf2("res",res);
            }
            if(res*sign < 0){
               cout << '-' << '\n';
            } else {
               cout << '+' << '\n';
            }
         }
      }
   }

}
