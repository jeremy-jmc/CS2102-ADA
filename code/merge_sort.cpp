// g++ merge_sort.cpp -std=c++17 && ./a.out && rm ./a.out

#include <bits/stdc++.h>
using namespace std;

#define endll '\n'
#define pb push_back

typedef long long ll;

const int INF = INT_MAX;
const int min_value = -1e3, max_value = 1e3;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// UTILITIES
int random (int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "["; for (auto el : v) cout << el << ", "; cout << "\b\b]\n"; }

vector<int> random_vec(int n)
{
    vector<int> vec;
    for (int i=1; i<=n; i++)
        vec.pb(random(min_value, max_value));
    return vec;
}

// MERGE SORT
void merge(vector<int> &A, int l, int mid, int r)
{
    // cout << l << "  " << r << endll;
    vector<int> L, R;
    for (int i = l; i <= mid; i++)
        L.pb(A[i]);
    for (int i = mid+1; i <= r; i++)
        R.pb(A[i]);
    L.pb(INF);
    R.pb(INF);
   
    int idx_l = 0, idx_r = 0;
    for (int k = l; k <= r; k++)
        if (L[idx_l] <= R[idx_r])
            A[k] = L[idx_l++];
        else A[k] = R[idx_r++];
}

void merge_sort(vector<int>& A, int l, int r)
{
    if (l < r)
    {
        auto mid = l + (r-l)/2;
        merge_sort(A, l, mid);
        merge_sort(A, mid+1, r);
        merge(A, l, mid, r);
    }
}

int main()
{
#ifndef TEST
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    int N; cin >> N;
    auto vec = random_vec(N);
    PRINT_VEC(vec);
    merge_sort(vec, 0, N-1);
    PRINT_VEC(vec);

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

/* 
MERGE-SORT(A, l, r)
    if l < r:
        mid = l + (r-l)/2
        MERGE-SORT(A, l, mid)
        MERGE-SORT(A, mid+1, r)
        MERGE(A, l, mid, r)

MERGE(A, l, m, r)
    // sort by two pointers technique
 */

// https://cpc-utec.github.io/blog/web/class-12.html
// https://gist.github.com/Neilblaze/dcf6113fa5e63fc938502f1d742365c4