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
int MAX = 0;

vector<vector<int>> move(vector<vector<int>> inp, int dir, int depth = 0){
   vector<vector<int>> res = vector<vector<int>>(inp);
   if(dir == 0){
      for(int i = 0; i < N; i++){
         int k = 0;
         int agg = 0;
         for(int j = 0; j < N; j++){
            if(res[i][j] != 0){
               if(k != 0 && res[i][k-1] == res[i][j] && agg == 0){
                     res[i][k-1] *= 2;
                     res[i][j] = 0;
                     agg = 1;
                     if(MAX < res[i][k-1]) MAX = res[i][k-1];
                     k--;
               } else if(k != j){
                  res[i][k] = res[i][j];
                  res[i][j] = 0;
                  agg = 0;
               }
               k++;
         }
      }
      }
   } else if(dir == 1){
      for(int i = 0; i < N; i++){
         int k = N-1;
         int agg = 0;
         for(int j = N-1; j >= 0; j--){
            if(res[i][j] != 0){
               if(k != N-1 && res[i][k+1] == res[i][j] && agg == 0){
                  res[i][k+1] *= 2;
                  res[i][j] = 0;
                  agg = 1;
                  if(MAX < res[i][k+1]) MAX = res[i][k+1];
                  k++;
               } else if (k != j) {
                  res[i][k] = res[i][j];
                  res[i][j] = 0;
                  agg = 0;
               }
            k--;
            }
         }
      }
   } else if(dir == 2){
      for(int j = 0; j < N; j++){
         int k = 0;
         int agg = 0;
         for(int i = 0; i < N; i++){
             if(res[i][j] != 0){
               if(k != 0 && res[k-1][j] == res[i][j] && agg == 0){
                     res[k-1][j] *= 2;
                     res[i][j] = 0;
                     agg = 1;
                     if(MAX < res[k-1][j]) MAX = res[k-1][j];
                     k--;
               } else if(k != i){
                     res[k][j] = res[i][j];
                     res[i][j] = 0;
                     agg = 0;
               }
               k++;
            }
         }
      }
   } else if(dir == 3){
      for(int j = 0; j < N; j++){
         int k = N-1;
         int agg = 0; 
         for(int i = N-1; i >= 0; i--){
            if(res[i][j] != 0){
               if(k != N-1 && res[k+1][j] == res[i][j] && agg == 0){
                  res[k+1][j] *= 2;
                  res[i][j] = 0;
                  agg = 1;
                  if(MAX < res[k+1][j]) MAX = res[k+1][j];
                  k++;
               } else if(k != i){
                  res[k][j] = res[i][j];
                  res[i][j] = 0;
                  agg = 0;
               }
               k--;
            }
         }
      }
   }
   return res;
}

void solve(vector<vector<int>> inp, int depth){
   if(depth > 4) return;
   solve(move(inp,0),depth+1);
   solve(move(inp,1),depth+1);
   solve(move(inp,2),depth+1);
   solve(move(inp,3),depth+1);
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
      // freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<vector<int>> inp = vector<vector<int>>(N,vector<int>(N,0));
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         cin >> inp[i][j];
         if(inp[i][j] > MAX) MAX = inp[i][j];
      }
   }
   solve(inp,0);
   cout << MAX << '\n';

   inp = move(inp,3);
   inp = move(inp,1);
   inp = move(inp,3);
   inp = move(inp,1);
   inp = move(inp,3);
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         cout << inp[i][j] << ' ';
      }
      cout << '\n';
   }

}
