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

long long mod = 1000000007;

void seginit(vll& arr , vll &seg, int node, int start, int end){
   if(start == end){
      seg[node] = arr[start];
   } else{   
      seginit(arr,seg,node*2,start,(start+end)/2);
      seginit(arr,seg,node*2+1,(start+end)/2+1,end);
      seg[node] = (seg[node*2]%mod) * (seg[node*2+1]%mod);
      seg[node] %= mod;
   }
}

long long query(vll& seg, int node, int start, int end, int left, int right){
   if(start > right || end < left){
      return 1;
   }
   if(left <= start && end <= right){
      return seg[node];
   }
   long long lsum = query(seg,node*2,start,(start+end)/2,left,right)%mod;
   long long rsum = query(seg,node*2+1,(start+end)/2+1,end,left,right)%mod;
   return (lsum * rsum)%mod;
}

long long powi(long long a, int pow){
   long long res = 1;
   a %= mod;
   while(pow > 0){
      if(pow % 2 == 1){
         res *= a;
         res %= mod;
      }
      a *= a;
      a %= mod;
      pow /= 2;
   }
   return res;
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
   seg[node] = (seg[node*2]%mod) * (seg[node*2+1]%mod);
   seg[node] %= mod;
}

// void update2(vll& seg, int node, int start, int end, int idx, long long diff){
//    if(idx < start || idx > end) return;
//    seg[node] *= diff;
//    seg[node] %= mod;
//    if(start != end){
//       update2(seg,node*2,start,(start+end)/2,idx,diff);
//       update2(seg,node*2+1,(start+end)/2+1,end,idx,diff);
//    }
// }


// void update(vll& arr,vll& seg, int len, int idx, long long val){
//    long long diff = powi(arr[idx],mod-2)*val;
//    diff %= mod;
//    arr[idx] = val; 
//    update2(seg,1,0,len-1,idx,diff);
// }


int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
      // freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M >> K;
   arr = vll(N);
   int h = (int)ceil(log2(N));
   int tree_size = (1 << (h+1));
   seg = vll(tree_size,1);
   for(int i = 0; i < N; i++){
      cin >> arr[i];
   }
   seginit(arr,seg,1,0,N-1);

   long long inp, B, C;
   while(M+K>0){
      cin >> inp >> B >> C;
      if(inp == 2){
         M--;
         cout << query(seg,1,0,N-1,B-1,C-1) << '\n';
      } else {
         K--;
         update3(arr,seg,1,0,N-1,B-1,C);
      }
   }
}
