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

int N, K;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int tc; cin >> tc; // 1 to 85
   for(int i = 1; i <= tc; i++){
      cout << "Case #" << i << ": ";
      cin >> N >> K;
      vector<int> vec(N);
      for(int i = 0; i < N; i++){
         cin >> vec[i];
      }
      sort(all(vec));
      vector<int> vec_uniq(vec);
      vec_uniq.erase(unique(all(vec_uniq)),vec_uniq.end());
      // case 1
      if(N > 2*K){
         cout << "NO\n";
         continue;
      }
      bool more_than_two = false;
      for(auto a: vec_uniq){
         int cnt = upper_bound(all(vec),a) - lower_bound(all(vec),a);
         if(cnt > 2){
            more_than_two = true;
            break;
         }
      }
      if(!more_than_two){
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
}
