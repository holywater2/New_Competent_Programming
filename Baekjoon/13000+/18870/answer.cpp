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

set<int> s;
vector<int> v;
int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   v = vector<int>(N);
   for(int i = 0; i < N; i++){
      int temp;
      cin >> temp;
      s.insert(temp);
      v[i] = temp;
   }
   vector<int> sv(all(s));
   for(int i = 0; i < N; i++){
      cout << lower_bound(all(sv),v[i]) - sv.begin() << " ";
   }
   cout << '\n';
}
