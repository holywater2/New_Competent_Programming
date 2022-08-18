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
int arr[1001];
int inc[1001];
int ddec[1001];

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
      inc[i] = 1;
      for(int j = 0; j < i; j++){
         if(arr[j] < arr[i]){
            inc[i] = max(inc[i],inc[j]+1);
         }
      }
   }
   for(int i = N-1; i >=  0; i--){
      ddec[i] = 1;
      for(int j = N-1; j > i; j--){
         if(arr[j] < arr[i]){
            ddec[i] = max(ddec[i],ddec[j]+1);
         }
      }
   }
   int gmax = inc[0] + ddec[0] -1;
   for(int i = 0; i < N; i++){
      gmax = max(gmax,inc[i] + ddec[i] -1);
   }
   cout << gmax << '\n';
}
