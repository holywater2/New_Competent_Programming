#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF (1e9+1)   

using namespace std;

typedef unsigned long long ull;
typedef vector<long long> vll;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M, K;

vll arr;
vll seg;

void seginit(vll& arr , vll &seg, int node, int start, int end){
   if(start == end){
      seg[node] = arr[start];
   } else{   
      seginit(arr,seg,node*2,start,(start+end)/2);
      seginit(arr,seg,node*2+1,(start+end)/2+1,end);
      seg[node] = min(seg[node*2],seg[node*2+1]);
   }
}

long long query(vll& seg, int node, int start, int end, int left, int right){
   if(start > right || end < left){
      return INF;
   }
   if(left <= start && end <= right){
      return seg[node];
   }
   long long lsum = query(seg,node*2,start,(start+end)/2,left,right);
   long long rsum = query(seg,node*2+1,(start+end)/2+1,end,left,right);
   return min(lsum,rsum);
}

void update3(vll& arr, vll& seg, int node, int start, int end, int idx, long long val){
   if(idx < start || idx > end) return;
   if(start == end){
      seg[node] = val;
      arr[idx] = val;
      return;
   }
   update3(arr,seg,node*2,start,(start+end)/2,idx,val);
   update3(arr,seg,node*2+1,(start+end)/2+1,end,idx,val);
   seg[node] = min(seg[node*2],seg[node*2+1]);
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   arr = vll(N);
   int h = (int)ceil(log2(N));
   int tree_size = (1 << (h+1));
   seg = vll(tree_size,INF);
   for(int i = 0; i < N; i++){
      cin >> arr[i];
   }
   seginit(arr,seg,1,0,N-1);

   cin >> M;
   long long inp, B, C;
   while(M>0){
      cin >> inp >> B >> C;
      M--;
      if(inp == 2){
         cout << query(seg,1,0,N-1,B-1,C-1) << '\n';
      } else {
         update3(arr,seg,1,0,N-1,B-1,C);
      }
   }
}
