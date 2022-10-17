// g++ count_inversions.cpp -std=c++17 && ./a.out && rm ./a.out

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

int inversiones_centradas(vector<int> &A, int l, int mid, int r)
{
    // cout << l << "  " << r << endll;
    vector<int> L, R;
    for (int i = l; i <= mid; i++)
        L.pb(A[i]);
    for (int i = mid+1; i <= r; i++)
        R.pb(A[i]);
    L.pb(INF);
    R.pb(INF);
   
   int total = 0;
    int idx_l = 0, idx_r = 0;
    for (int k = l; k <= r; k++)
    {
        if (L[idx_l] <= R[idx_r])
        {
            A[k] = L[idx_l++];
            total += idx_r;
        }
        else A[k] = R[idx_r++];
    }
    return total;
}

int inversiones_dc(vector<int>& A, int l, int r)
{
    if (l == r)
        return 0;
    
    auto mid = l + (r-l)/2;
    auto total1 = inversiones_dc(A, l, mid);
    auto total2 = inversiones_dc(A, mid+1, r);
    auto total3 = inversiones_centradas(A, l, mid, r);
    return total1 + total2 + total3;
}

int main()
{
#ifndef TEST
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    // int N; cin >> N;
    // auto vec = random_vec(N);
    auto N = 5;
    vector<int> vec {1, 20, 6, 4, 5};
    PRINT_VEC(vec);
    auto count = inversiones_dc(vec, 0, N-1);
    PRINT_VEC(vec);
    cout << count << endll;

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

/* 
INVERSIONES-DC(A, l, r)
    if p == r
        return 0
    mid = l + (r-l)/2
    total1 = INVERSIONES-DC(A, l, mid)
    total2 = INVERSIONES-DC(A, mid+1, r)
    total3 = INVERSIOENS-CENTRADAS(A, l, mid, r)
    
    return total1 + total2 + total3

COUNT_BY_PARTS(A, l, m, r)
    // sort by two pointers technique
 */

/* 
INPUT:  A[1...N]
OUTPUT: number of inversions, where one inversions is a pair (i, j) such that i < j and A[i] > A[j]

NAIVE APPROACH
    INVERSIONES-INGENUO(A, N)
        total = 0
        for i = 1 to N-1
            for j = i + 1 to N
             if A[i] > A[j]
                total++
        return total
    
    T(n) = theta(N^2)

APPLYING DIVIDE & CONQUER

    INVERSIONES-CENTRADAS(A, p, q, r)
        n1 = q - p + 1
        n2 = r - q

        L = [1 ... n1 + 1]
        R = [1 ... n2 + 1]

        for i = 1 to n1
            L[i] = A[p + i - 1]
        for j = 1 to n2
            R[j] = A[q + j]
        
        L[n1 + 1] = INF
        L[n2 + 1] = INF

        i = 1, j = 1

        total = 0
        for k = p to r
            if L[i] <= R[j]
                A[k] = L[i]
                i = i + 1
                total = total + j - 1
            else
                A[k] = R[j]
                j = j + 1
        return total
        
    INVERSIONES-DC(A, p, r)
        if p == r
            return 0
        q = p + (r-p)/2
        total1 = INVERSIONES-DC(A, p, q)
        total2 = INVERSIONES-DC(A, q+1, r)
        total3 = INVERSIONES-CENTRADAS(A, p, q, r)

        return total1 + total2 + total3
 */

