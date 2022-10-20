#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a
#define pf1(a)      cout << a << '\n'
#define pf2(a,b)    cout << a << ' ' << b << '\n'
#define pf3(a,b,c)  cout << a << ' ' << b << ' ' << c << '\n'
#define pf4(a,b,c,d)  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'
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

int N;

int hcube[10][10][10][10];

void addcube(int d[], int pos){
   if(pos == 4){
      pf4(d[3],d[2],d[1],d[0]);
      hcube[d[3]][d[2]][d[1]][d[0]]++;
      return;
   }
   int digit = d[pos];
   d[pos] = 0;
   addcube(d, pos+1);
   d[pos] = digit;
   addcube(d, pos+1);
}

void insert(int inp){
   int d[4];
   for(int i = 0; i < 4; i++){
      d[i] = inp%10;
      inp /= 10;
   }
   addcube(d,0);
}

// ll recursive(int d, int pos){
//    if(pos == 4) return 0;
//    int nd[] = {d[0],d[1],d[2],d[3]};
//    for(int i = 0; i < pos; i++){
//       nd[i] = 0;
//    }
//    ll res = hcube[d[3]][d[2]][d[1]][d[0]];
//    nd[] = {d[0],d[1],d[2],d[3]};
   
//    nd[pos] = 0;
//    res += recursive(d, pos + 1);
//    nd[pos] = d[pos];
//    res -= recursive(d, pos + 1);
//    return res;
// }

ll recur2(vector<vector<bool>>& v,int d[], int pos){
   if(pos == 4) return hcube[d[3]][d[2]][d[1]][d[0]];
   ll res = 0;
   int nd[] = {d[3],d[2],d[1],d[0]};
   for(int i = 1; i < 10; i++){
      if(!v[pos][i]){
         nd[pos] = i;
         res += recur2(v,nd,pos+1);
      }
   }
   return res;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   vector<int> v(3);
   cin >> N;
   int inp;
   vector<int> inps(N);
   for(int i = 0; i < N; i++){
      cin >> inps[i];
      insert(inps[i]);
   }
   for(int i = 0; i < N; i++){
      for(int j = i+1; j < N; j++){
         vector<vector<bool>> vv(4,vector<bool>(10));
         int cur = inps[i], next = inps[j];
         for(int k = 0; k < 4; k++){
            if(cur % 10 == next % 10){
               vv[k][cur % 10] = true;
            } else {
               vv[k][]
            }
         }
      }
   }
}
