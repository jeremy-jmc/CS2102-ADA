#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

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

