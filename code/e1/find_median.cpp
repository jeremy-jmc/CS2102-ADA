#include <bits/stdc++.h>
using namespace std;

template<typename T>
T find_median(vector<T> &A, int p, int q, vector<T> &B, int r, int s)
{
    
}

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

    vector<int> A{10, 30, 50, 70};
    vector<int> B{20, 40, 60, 80};

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

/* 
Example
    A = [10, 30, 50, 70]
    B = [20, 40, 60, 80]

Case 1: A[n/2] < B[n/2]
    En ese caso, todos los elementos de A[1 ... n/2] son menores que todos los elementos de A[n/2 + 1...n] y B[n/2 ... n]. Como hay n+1 elementos, la mediana no esta en A[1 ... n/2]

    Tambien todos los elementos de B[n/2+1 ... n] son mayores que A[1 ... n/2] y B[1 ... n/2]. Como hay n elementos, la mediana no puede estar en B[n/2+1 ... n]

    Entonces la mediana esta entre A[n/2+1 ... n] y B[1, ... n/2]
Case 2: 
    Lo contrario
    La mediana esta en el otro par de mitades 
        A[1....n/2] y B[n/2 + 1 ... n]

MEDIAN(A, p, q, B, r, s)
    if p == q
        return min(A[p], B[q])
    mid_A = p + (q-p)/2
    mid_B = r + (s-r)/2

    if A[mid_A] > B[mid_B]
        return MEDIAN(A, mid_A+1, q, B, r, mid_B)
    else
        return MEDIAN(A, p, mid_A, B, mid_B+1, s)
 */


/* 
    A = [10, 30 // 50, 70]
    B = [20, 40 // 60, 80]
    
    30 < 60
    [10, 30] < [50, 70]     ... por defecto
    [10, 30] < [60, 80]     ... por la comparacion

    Aca [10, 30] no puede estar la mediana

    40 < 60
    [60, 80] > [20, 40]     ... por defecto
    [60, 80] > [10, 30]     ... por la comparacion anterior

    Aca [60, 80] no puede estar la mediana

    Entonces la mediana esta en [20, 40] y [50, 70]
 */



