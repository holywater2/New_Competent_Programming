#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

int Gear[4][8];
int stat[4];

// cl : clock num, dir: rotation direction
void rotate(int cl, int dir){
   if(dir == -1){
      stat[cl]++;
      if(stat[cl] == 8) stat[cl] = 0;
   } else if(dir == 1){
      stat[cl]--;
      if(stat[cl] == -1) stat[cl] = 7;
   }
}

// 1 -> 2 -> 3-> 4;
// 2 -> 1, 2->3->4;
// pr 이전게 돌았는지 여부
void solve(int cl, int pole, int lr, int dir){
   if(cl == -1 || cl == 5) return;
   if(pole == 0){
      solve(cl+1,Gear[cl][(stat[cl]+2)%8],1,dir*-1);                        
      solve(cl-1,Gear[cl][(stat[cl]+8-2)%8],-1,dir*-1);
      rotate(cl,dir);
   } else if(pole*-1 == Gear[cl][(stat[cl]+8-2*lr)%8]){
      solve(cl+lr,Gear[cl][(stat[cl]+8+2*lr)%8],lr,dir*-1);                        
      rotate(cl,dir);
   }          
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   string inp;
   for(int i = 0; i < 4; i++){
      getline(cin,inp);
      for(int j = 0; j < 8; j++){
         if(inp[j] == '1'){
            Gear[i][j] = 1;
         } else{
            Gear[i][j] = -1;
         }
      }
   }
   cin >> N;
   int a,b;
   for(int i = 0; i < N; i++){
      cin >> a >> b;
      solve(a-1,0,0,b);
   }
   int res = 0;
   int t = 1;
   for(int i = 0; i < 4; i++){
      res += (Gear[i][stat[i]]+1)*t/2;
      t *= 2;
   }
   cout << res << '\n';

}
