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
typedef vector<long long> vll;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, tree_size;

vll arr;
vll seg;

void seginit(vll& arr , vll &seg, int node, int start, int end){
   if(start == end){
      seg[node] = start;
   } else{   
      seginit(arr,seg,node*2,start,(start+end)/2);
      seginit(arr,seg,node*2+1,(start+end)/2+1,end);
      // seg[node] = seg[node*2] + seg[node*2+1];
      if(arr[seg[node*2]] < arr[seg[node*2+1]]){
         seg[node] = seg[node*2];
      } else{
         seg[node] = seg[node*2+1];
      }
   }
}

long long query(vll& seg, int node, int start, int end, int left, int right){
   if(start > right || end < left){
      return N;
   }
   if(left <= start && end <= right){
      return seg[node];
   }
   long long lsum = query(seg,node*2,start,(start+end)/2,left,right);
   long long rsum = query(seg,node*2+1,(start+end)/2+1,end,left,right);
   if(arr[lsum] < arr[rsum]){
     return lsum;
   } else return rsum;
}

void update2(vll& seg, int node, int start, int end, int idx, long long diff){
   if(idx < start || idx > end) return;
   seg[node] += diff;
   if(start != end){
      update2(seg,node*2,start,(start+end)/2,idx,diff);
      update2(seg,node*2+1,(start+end)/2+1,end,idx,diff);
   }
}


void update(vll& arr,vll& seg, int len, int idx, long long val){
   long long diff = val - arr[idx];
   arr[idx] = val; 
   update2(seg,1,0,len-1,idx,diff);
}

long long solve(int lo, int hi){
   if(lo < 0 || hi > N) return 0;
   int min_idx = query(seg,1,0,N-1,lo,hi-1);
   long long res = arr[min_idx]*(hi-lo);
   // pf2(lo,hi);
   // pf2(min_idx,arr[min_idx]);
   // pf1(res);
   if(lo <= min_idx-1){
      long long lres = solve(lo,min_idx);
      res = max(lres,res);
   }
   if(hi > min_idx+1){
      long long rres = solve(min_idx+1,hi);
      res = max(rres,res);
   }
   return res;
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   while(true){
      cin >> N;
      if(N == 0) break;;
      arr = vll(N+1);
      for(int i = 0; i < N; i++){
         cin >> arr[i];
      }

      int h = (int)ceil(log2(N));
      tree_size = (1 << (h+1));
      // pf1(tree_size);
      seg = vll(tree_size);
      arr[N] = 1e9+1;

      seginit(arr,seg,1,0,N-1);
      long long res = solve(0,N);
      cout << res << '\n';
   }
}
