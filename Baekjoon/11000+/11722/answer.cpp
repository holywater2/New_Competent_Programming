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
int dp[1000001];
int arr[1000001];

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
      idx[i] = i;
   }
   vector<pii> res;
   vector<int> idx;

   res.pb({arr[0],0});
   idx.pb(0);
   for(int i = 1; i < N; i++){
      auto cur = {arr[i],i};
      if(res.back() < arr[i]){
         res.pb(arr[i]);
      } else if (res.front() >= arr[i]){
         res[0] = arr[i];
      } else {
         auto it = upper_bound(all(res), arr[i]);
         if(*(it-1) != arr[i]) *it = arr[i];
         else *(it-1) = arr[i];
      }
   }
   // for(int i : res)
   //    pf1(i);
   cout << res.size() << '\n';
}
