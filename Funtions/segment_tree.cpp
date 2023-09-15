#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct {
    int set_val, add, sum, val;
} node;
int n, q; node tree[100]; int nums[100]; int BIT[100];
#define lp 2*now
#define rp 2*now+1
#define mid (L+R)/2
// Pull
void pull(int now){  // update now with 2 children
    // 用l、rp更新now
    // tree[now].sum = tree[lp].sum + tree[rp].sum;
    // tree[now].prefix = max(tree[lp].sum+tree[rp].prefix, tree[lp].prefix);
    // tree[now].suffix = max(tree[lp].suffix+tree[rp].sum, tree[rp].suffix);
    // tree[now].middle_max = max(max(tree[lp].middle_max, tree[rp].middle_max), tree[lp].suffix+tree[rp].prefix);
    // tree[now].middle_max = max(max(tree[now].middle_max, tree[now].prefix), tree[now].suffix);
}
// 懶人
void push(int now, int child){
    if(tree[now].set_val){
        tree[child].set_val = 1;
        tree[child].val = tree[now].val;
        tree[child].add = tree[now].add;
    }
    else {
        tree[child].add += tree[now].add;
    }
}
void apply_tag(int now, int L, int R){
    if(tree[now].set_val)
        tree[now].sum = (R-L+1)*tree[now].val;
    tree[now].sum += (R-L+1)*tree[now].add;
    if(L != R){ // 還可以往下走
        push(now, lp);
        push(now, rp);
    }
    tree[now].add = tree[now].set_val = 0;  // Reset
}
// Build
void build(int L, int R, int now){
    if(L == R){
        // init tree[now];
        return;
    }
    int M = mid;
    build(L, M, lp);
    build(M + 1, R, rp);
    pull(now);
}
// modify
void modify(int l, int r, int L, int R, int now){
    if(R < l || r < L || L > n) // 無效範圍
        return;
    if(l <= L && R <= r){
        // modify tree[now];
        // tree[now].add += add;    // modify_add
        // tree[now].set_val = 1;   // modify_mod
		// tree[now].val = mod;
		// tree[now].add = 0;  // Set優先
        return;
    }
    int M = mid;
    apply_tag(now, L, R);
    modify(l, r, L, M, lp);
    modify(l, r, M+1, R, rp);
    apply_tag(lp, L, M);	// 算好(最底的也會，順便Reset)
    apply_tag(rp, M+1, R);	// 算好(最底的也會，順便Reset)
    pull(now);  // update now with 2 children
}
// query
ll query(int l, int r, int L, int R, int now){
    int M = mid;
    if(R < l || r < L || L > n){
        return 0;
    }
    // apply_tag(now, L, R);   // 懶人
    if(l <= L && R <= r){
        return tree[now].sum;
    }
	return query(l, r, L, M, lp) + query(l, r, M+1, R, rp);
}
// pizza_queries
// 左(s < t): dis_l = (pizza[s] - s) + t;
// 右(t < s): dis_r = (pizza[s] + s) - t;

// List Removals
// 用線段樹維護範圍內有多少個被選過
// 用二分搜找ans前有mod個被選過，若ans - mod == pos，nums[ans]即是答案，順便modify tree[pos]

// polynomial queries
// 懶人seg，存底跟公差