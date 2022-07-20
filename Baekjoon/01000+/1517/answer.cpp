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

int N, M, K;

vll arr;
vll seg;
vll comp;

void seginit(vll& arr , vll &seg, int node, int start, int end){
   if(start == end){
      seg[node] = arr[start];
   } else{   
      seginit(arr,seg,node*2,start,(start+end)/2);
      seginit(arr,seg,node*2+1,(start+end)/2+1,end);
      seg[node] = seg[node*2] + seg[node*2+1];
   }
}

long long query(vll& seg, int node, int start, int end, int left, int right){
   if(start > right || end < left){
      return 0;
   }
   if(left <= start && end <= right){
      return seg[node];
   }
   long long lsum = query(seg,node*2,start,(start+end)/2,left,right);
   long long rsum = query(seg,node*2+1,(start+end)/2+1,end,left,right);
   return lsum + rsum;
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


int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   arr = vll(N);
   for(int i = 0; i < N; i++){
      cin >> arr[i];
   }
   comp = vll(arr);
   sort(all(comp));
   comp.erase(unique(all(comp)),comp.end());

   int h = (int)ceil(log2(comp.size()));
   int tree_size = (1 << (h+1));
   // pf1(tree_size);
   seg = vll(tree_size);
   long long res = 0;
   for(int i = 0; i < N; i++){
      long long num = arr[N-1-i];
      long long idx = lower_bound(all(comp),num)-comp.begin();
      // pf2(num,idx);
      update2(seg,1,0,comp.size()-1,idx,1);
      if(idx != 0){
         res += query(seg,1,0,comp.size()-1,0,idx-1);
      }
   }
   cout << res << '\n';
}
