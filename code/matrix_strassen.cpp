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
MATRIX MULTIPLICATION
    SQUARE-MATRIX-MULTIPLICATION(A, B)
        N = A.rows
        C = [](N*N)
        for i = 1 to N
            for j = 1 to N
                cij = 0
                for k = 1 to N
                    cij += A_ik * B_kj
        return C
    T(n) = theta(N^3)

RECURSIVE MATRIX MULTIPLICATION WITH D&C
    Let A, B, C, where:

    A = [
        A11, A12
        A21, A22
    ]
    B = [
        B11, B12
        B21, B22
    ]
    C = [
        C11, C12
        C21, C22
    ]

    And C = A.B
    Then:
        C11 = A11.B11 + A12.B21 
        C12 = A11.B12 + A12.B22
        C21 = A21.B11 + A22.B21
        C22 = A21.B12 + A22.B22

    T(n) = {
        theta(N^2)
        8 T(N/2) + theta(N^2)
    }
    T(n) = theta(N^3)

STRASSEN MATRIX MULTIPLICATION
Create 10 matrices
Compute 7 matrix products, each matrix of size N/2 * N/2, in theta(N^2) time.
Compute the desired submatrices C11, C12, C21, C22 applying various combinations of 7 previous matrices.

    T(n) = {
        theta(N^2)
        7 T(N/2) + theta(N^2)
    }
    T(n) = theta(lg7)
 */