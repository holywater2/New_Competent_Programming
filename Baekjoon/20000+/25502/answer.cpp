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
typedef pair<long,long> pll;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

// pll find_pll(ll a, ll b){
//    ll k = __gcd(a,b);
//    return {a/k,b/k};
// }
ll find_pll(ll a, ll b){
   if(a%b == 0) return a/b;
   return -1;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   vector<ll> v(N);
   map<ll,int> dif_map, rate_map;

   for(int i = 0; i < N; i++)
      cin >> v[i];
   for(int i = 0; i < N-1; i++){
      ll dif = v[i+1]-v[i];
      if(dif < 1) dif = 0;

      if(dif_map.count(dif) == 0){
         dif_map[dif] = 1;
      } else {
         dif_map[dif]++;
      }

      ll rate = find_pll(v[i+1],v[i]);
      
      if(rate_map.count(rate) == 0){
         rate_map[rate] = 1;
      } else {
         rate_map[rate]++;
      }
   }

   for(int i = 0; i < M; i++){
      ll idx, num;
      cin >> idx >> num;
      idx--;
      int res = 0;
      if(idx != N-1){
         ll dif = v[idx+1]-v[idx];
         if(dif < 1) dif = 0;
         
         dif_map[dif]--;
         if(dif_map[dif] == 0){
            dif_map.erase(dif);
         }

         dif = v[idx+1] - num;
         if(dif < 1) dif = 0;
         
         if(dif_map.count(dif) == 0){
            dif_map[dif] = 1;
         } else {
            dif_map[dif]++;
         }

         if(dif > 0 && (dif_map[dif] == N-1)) res = 1;
      }
      if(idx != 0){
         ll dif = v[idx]-v[idx-1];
         if(dif < 1) dif = 0;

         dif_map[dif]--;
         if(dif_map[dif] == 0){
            dif_map.erase(dif);
         }
         
         dif = num - v[idx-1];
         if(dif < 1) dif = 0;

         if(dif_map.count(dif) == 0){
            dif_map[dif] = 1;
         } else {
            dif_map[dif]++;
         }

         if(dif > 0 && (dif_map[dif] == N-1)) res = 1;
      }
      if(idx != N-1){
         ll dif = find_pll(v[idx+1],v[idx]);
         rate_map[dif]--;
         if(rate_map[dif] == 0){
            rate_map.erase(dif);
         }

         dif = find_pll(v[idx+1],num);
         
         if(rate_map.count(dif) == 0){
            rate_map[dif] = 1;
         } else {
            rate_map[dif]++;
         }

         if(dif != -1 && (rate_map[dif] == N-1)) res = 2;
      }
      if(idx != 0){
         ll dif = find_pll(v[idx],v[idx-1]);
         rate_map[dif]--;
         if(rate_map[dif] == 0){
            rate_map.erase(dif);
         }

         dif = find_pll(num,v[idx-1]);
         
         if(rate_map.count(dif) == 0){
            rate_map[dif] = 1;
         } else {
            rate_map[dif]++;
         }

         if(dif != -1 && (rate_map[dif] == N-1)) res = 2;
      }
      if(res == 0) pf1("?");
      else if (res == 1) pf1("+");
      else pf1("*");
      v[idx] = num;
   }
}
