#define LOCAL

#include <iostream>
#include <vector>
#include <string>  
#include <queue>
#include <algorithm>
#include <cstring>  // memset(a,0,sizeof(a));

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

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   while(true){
      cin >> N;
      if(N == 0) break;
      M = N;
      int R = 0;
      while(M > 0){
         R *= 10;
         R += M%10;
         M /= 10;
      }
      if(R == N){
         cout << "yes" << '\n';
      } else {
         cout << "no" << '\n';
      }
   }
}
