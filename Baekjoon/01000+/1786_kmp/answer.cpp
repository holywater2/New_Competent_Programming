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

string N, M;

vector<int> getPi(string M){
   int m = (int)M.size(), j = 0;
   vector<int> res(m,0);
   // res[0] = 0;
   for(int i = 1; i < m; i++){
      while(j > 0 && M[i] != M[j]){
         j = res[j-1];
      }
      if(M[i] == M[j]){
         res[i] = ++j;
      }
   }
   return res;
}

vector<int> kmp(string N, string M){
   auto pi = getPi(M);
   vector<int> res;
   int n = (int)N.size(), m = (int)M.size();
   for(int i = 0, j = 0; i < n; i++){
      while(j > 0 && N[i] != M[j]){
         j = pi[j-1];
      }
      if(N[i] == M[j]){
         if(j == m-1){
            res.push_back(i-j);
            j = pi[j];
         } else {
            j++;
         }
      }
   }
   return res;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data2.txt", "r", stdin);
      freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   getline(cin,N);
   getline(cin,M);
   auto res = kmp(N,M);
   cout << res.size() << '\n';
   for(int i = 0; i < res.size(); i++){
      cout << res[i] + 1 << ' ';
   }
   cout << '\n';
}
