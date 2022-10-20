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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N;
int arr[20][20];
int rmin, sum;

void comb(int v[], int rr[],int idx, int depth, int n, int r){
   if(idx == r){
      int res = 0;
      for(int i = 0; i < N/2; i++)
         cout << rr[i];
      cout << '\n';
      for(int i = 0; i < N/2; i++){
         for(int j = i+1; j < N/2; j++){
            res += arr[rr[i]][rr[j]] + arr[rr[j]][rr[i]];
         }
      }
      int rr2[N/2];
      for(int i = 0; i < N/2; i++){
         int num = i;
         rr2[i] =
      }
      int res2 = 0;
      pf2(res2,res);
      rmin = min(rmin,abs(res2-res));
   }
   for(int i = depth; i < n; i++){
      rr[idx] = v[i];
      comb(v,rr,idx+1, i + 1, n, r);
   }
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         cin >> arr[i][j];
         sum += arr[i][j];
      }
   }
   rmin = INF;
   int vec[N];
   for(int i = 0; i < N; i++){
      vec[i] = i;
   }
   int rr[N/2];
   comb(vec,rr,0,0,N,N);

   cout << rmin << '\n';
}
