#define LOCAL

#include<bits/stdc++.h>
#include<algorithm>
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

typedef pair<int,int> pii;

bool compare(pii a, pii b){
   if(a.second == b.second){
      return a.first < b.first;
   }
   return a.second < b.second;
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<pii> pv = vector<pii> (N);
   for(int i = 0 ; i < N; i++){
      int a, b;
      cin >> a >> b;
      pv[i] = {a,b};
   }
   sort(all(pv),compare);
   int res = 0;
   vector<pii>::iterator iter = pv.begin();
   int cur = -1;
   while(iter != pv.end()){
      if(cur <= (*iter).first){
          cur = (*iter).second;
          res++;
      }
      iter++;
   }
   pf1(res);
}
