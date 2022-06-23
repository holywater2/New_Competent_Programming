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

typedef pair<string,int> psi;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;

map<string,int> sv;
int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   string str;
   for(int i = 0; i < N ;i++){
      sf1(str);
      sv.insert(makepair(str,i));
   }
   for(int i = 0; i < M; i++){
      sf1(str);
      if(str[0] <= '9' && str[0] >= '0'){
         int i = stoi(str);
         cout << sv[i-1] << '\n';
      } else {
         cout << find(all(sv),str) - sv.begin()+1 << '\n';
      }
   }
}
