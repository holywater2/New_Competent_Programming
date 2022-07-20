#include<bits/stdc++.h>

using namespace std;

vector<int> arr = {1,2,3,4,5,6,7};

vector<int> segment = vector<int>(arr.size()*4+1);

void init(vector<int>& tree, vector<int>& arr,int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
    } else{
        init(tree,arr,2*node,start,(start+end)/2);
        init(tree,arr,2*node+1,(start+end)/2+1,end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(vector<int> tree, int node, int start, int end, int left, int right){
    if(start > right || end < left){
        return 0;
    } else if(left <= start && end <= right){
        return tree[node];
    }

    int lsum = query(tree,node*2,start,(start+end)/2,left,right);
    int rsum = query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return lsum + rsum;
}

void update2(vector<int>& tree, int node, int start, int end, int index, int diff){
    if(start <= index && index <= end){
        tree[node] += diff;
        if(start != end){
            update2(tree,node*2,start,(start+end)/2,index,diff);
            update2(tree,node*2+1,(start+end)/2+1,end,index,diff);
        }
    }
}

void update(vector<int>& arr, vector<int>& tree, int len, int index, int val){
    int diff = val-arr[index];
    arr[index] = val;
    update2(tree,1,0,len-1,index,diff);
}


int main(){
    init(segment,arr,1,0,7);
    int k = 2;
    for(int i = 1; i <= 28; i++){
        cout << segment[i] << ' ';
        if(i % k == k-1){
            cout << '\n';
            k *= 2;
        }
    }
    cout << '\n';
    cout << query(segment,1,0,6,0,6);
    cout << '\n';
    update(arr,segment,7,2,10);
    k = 2;
    for(int i = 1; i <= 28; i++){
        cout << segment[i] << ' ';
        if(i % k == k-1){
            cout << '\n';
            k *= 2;
        }
    }
    cout << '\n';
}