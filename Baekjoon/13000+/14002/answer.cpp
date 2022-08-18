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
int dp[1001];
long arr[1001];
int idx[1001];

int N, M;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> arr[i];
   }
   for(int i = 0; i < N; i++){
      dp[i] = 1;
      idx[i] = i;
      for(int j = 0; j < i; j++){
         if(arr[j] < arr[i]){
            if(dp[i] < 1 + dp[j]){
               dp[i] = 1 + dp[j];
               idx[i] = j;
            }
         }
      }
   }
   int gmax = dp[0];
   int idxn = 0;
   for(int i = 0; i < N; i++){
      if(gmax < dp[i]){
         gmax = dp[i];
         idxn = i;
      }
   }
   cout << gmax << '\n';
   vector<int> v;
   v.pb(arr[idxn]);
   while(true){
      if(idxn == idx[idxn]) break;
      v.pb(arr[idx[idxn]]);
      idxn = idx[idxn];
   }
   int sz = v.size();
   for(int i = 0; i < sz; i++){
      cout << v[sz-1-i] << ' ';
   }
   cout << '\n';
}
