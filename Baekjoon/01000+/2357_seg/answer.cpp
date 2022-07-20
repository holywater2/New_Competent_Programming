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
vll segmin,segmax;

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

void seginit2(vll& arr , vll &seg, int node, int start, int end){
   if(start == end){
      seg[node] = arr[start];
   } else{   
      seginit2(arr,seg,node*2,start,(start+end)/2);
      seginit2(arr,seg,node*2+1,(start+end)/2+1,end);
      seg[node] = max(seg[node*2],seg[node*2+1]);
   }
}

long long query2(vll& seg, int node, int start, int end, int left, int right){
   if(start > right || end < left){
      return -1;
   }
   if(left <= start && end <= right){
      return seg[node];
   }
   long long lsum = query2(seg,node*2,start,(start+end)/2,left,right);
   long long rsum = query2(seg,node*2+1,(start+end)/2+1,end,left,right);
   return max(lsum,rsum);
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
   cin >> N >> M;
   arr = vll(N);
   int h = (int)ceil(log2(N));
   int tree_size = (1 << (h+1));
   segmin = vll(tree_size);
   segmax = vll(tree_size);
   for(int i = 0; i < N; i++){
      cin >> arr[i];
   }
   seginit(arr,segmin,1,0,N-1);
   seginit2(arr,segmax,1,0,N-1);
   
   // int k = 2;
   // for(int i = 1; i <= tree_size; i++){
   //    cout << segmin[i] << ' ';
   //    if(i % k == k-1){
   //       cout << '\n';
   //       k *= 2;
   //    }
   // }
   // cout << '\n';

   // k = 2;
   // for(int i = 1; i <= tree_size; i++){
   //    cout << segmax[i] << ' ';
   //    if(i % k == k-1){
   //       cout << '\n';
   //       k *= 2;
   //    }
   // }
   // cout << '\n';

   long long inp, B, C;
   while(M>0){
      cin >> B >> C;
      M--;
      cout << query(segmin,1,0,N-1,B-1,C-1) << ' ' << query2(segmax,1,0,N-1,B-1,C-1) << '\n';
   }
}
