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

// 완전 탐색 코드 O(N^2)

int Max(int a, int b){
   if(a > b) return a;
   else return b;
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<int> v(N,0);
   vector<int> check(N,1);
   for(int i = 0; i < N; i++)
      cin >> v[i];
   int gmax = 1;
   for(int i = 0; i < N; i++){
      int max = 0;
      for(int j = 0; j <i; j++){
         if(v[i] > v[j]){
            max = Max(max,check[j]);
         }
      }
      check[i] = max+1;
      gmax = Max(max+1,gmax);
   }
   cout << gmax << '\n';
}
