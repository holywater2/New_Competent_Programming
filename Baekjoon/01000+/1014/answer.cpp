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

int N, T, M;
string desk[11];
int dp[11][1025];

bool seat_check(string seats, int bitmask){
   for(int i = 0; i < seats.length(); i++){
      if(seats[i] == 'x' && (bitmask & (1 << i))) return false;
   }
   return true;
}

bool adj_check(int bitmask, int width){
   for(int i = 0; i < width-1; i++){
      if((bitmask & (3 << i)) == (3 << i)) return false;
   }
   return true;
}

bool bits_cehck(int back_bit, int front_bit, int width){
   for(int i = 0; i < width; i++){
      if((1 << i) & front_bit){
         if(i > 0 && (1 << (i-1) & back_bit)) return false;
         if((1 << (i+1) & back_bit)) return false;
      }
   }
   return true;
}

void solve(){
   int ans = 0;
   vector<pii> bits_set;
   memset(dp,0,sizeof(dp));
   for(int bit = 0; bit < (1<<M); bit++){
      if (adj_check(bit,M)){
         int cnt = 0;
         for (int i = 0; i < M; i++){
            if((1 << i) & bit) cnt++;
         }
         bits_set.push_back({bit,cnt});
      }
   }
   for (int i = 1; i <= N; i++){
      for (pii bit : bits_set){
         if(!seat_check(desk[i], bit.first)) continue;
         for(pii fbit: bits_set){
            if(bits_cehck(bit.first, fbit.first, M)){
               dp[i][bit.first] = max(dp[i][bit.first], dp[i-1][fbit.first] + bit.second);
               ans = max(ans, dp[i][bit.first]);
            }
         }
      }
   }
   cout << ans << '\n';
   return;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> T;
   while(T-->0){
      cin >> N >> M;
      for(int i = 1; i <= N; i++){
         cin >> desk[i];
      }
      solve();
   }

}
