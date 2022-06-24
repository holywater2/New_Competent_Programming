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


vector<int> getPi(string M){
   int m = (int)M.size();
   vector<int> pi(m,0);
   for(int i = 1, j = 0; i < m; i++){
      while(j > 0 && M[i] != M[j]){
         j = pi[j-1];
      }
      if(M[i] == M[j]){
         pi[i] = ++j;
      }
   }
   return pi;
}

bool kmp(string N, string M){
   auto pi = getPi(M);
   int n = (int)N.size(), m = (int)M.size();
   for(int i = 0, j = 0; i < n; i++){
      while(j > 0 && N[i] != M[j]){
         j = pi[j-1];
      }
      if(N[i] == M[j]){
         if(j == m-1){
            return true;
         } else {
            j++;
         }
      }
   }
   return false;
}

int main(){
   string N, M;

   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
      freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   cout << kmp(N,M) << '\n';
}
