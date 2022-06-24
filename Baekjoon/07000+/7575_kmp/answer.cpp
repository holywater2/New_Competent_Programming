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

vector<int> getPi(vector<int> M){
   int m = (int)M.size();
   vector<int> pi(m,0);
   for(int i = 1, j = 0; i < m; i++){
      while(j > 0 && M[i] != M[j]) j = pi[j-1];
      if(M[i] == M[j]) pi[i] = ++j;
   }
   return pi;
}

bool kmp(vector<int> N, vector<int> M){
   auto pi = getPi(M);
   int n = (int)N.size(), m = (int)M.size();
   for(int i = 0, j = 0; i < n; i++){
      while(j > 0 && N[i] != M[j]) j = pi[j-1];
      if(N[i] == M[j]){
         if(j == m-1) return true;
         else j++;
      }
   }
   return false;
}

int main(){
   int N, K;
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> K;
   vector<vector<int>> data(N,vector<int>());
   int len;
   for(int i = 0; i < N; i++){
      cin >> len;
      data[i] = vector<int>(len,0);
      for(int j = 0; j < len; j++)
         cin >> data[i][j];
   }
   bool res = false;
   // pf1(data[0].size());
   for(int i = 0; i < data[0].size()-K+1; i++){
      if(res) break;
      vector<int> sub(data[0].begin()+i,data[0].begin()+i+K);
      vector<int> rev(all(sub));
      reverse(all(rev));
      int cnt = 0;
      for(int ll = 1; ll < N; ll++)
         if(kmp(data[ll],sub) || kmp(data[ll],rev)) cnt += 1;
      if(cnt == N-1) res = true;
   }
   if(res){pf1("YES");}
   else pf1("NO");
}
