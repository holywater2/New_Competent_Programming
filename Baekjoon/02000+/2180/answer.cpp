#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

typedef pair<int,int> pii;

bool compare(pii a, pii b){
   if(a.first == 0 && b.first == 0){
      return a.second < b.second;
   }
   if(a.first == 0){
      return false; // a > b
   } else if(b.first == 0){
      return true; // b < a
   }
   if(a.second == 0 && b.second == 0) return a.first < b.first;

   return (a.first)*b.second > (b.first)*a.second;
}

vector<pii> vp;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
      freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vp = vector<pii>(N);
   for(int i = 0; i < N; i++){
      cin >> vp[i].first >> vp[i].second;
   }
   sort(all(vp),compare);
   int res = 0;
   int cum_time = 0;
   for(int i = 0; i < N; i++){
      // pf2(vp[i].first, vp[i].second);
      cum_time = res*vp[i].first;
      cum_time %= 40000;
      cum_time += vp[i].second;
      cum_time %= 40000;
      res += cum_time;
      res %= 40000;
   }
   cout << res << '\n';
}
