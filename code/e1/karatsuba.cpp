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
MULTIPLICATION WITHOUT DIVIDE & CONQUER

    MULTIPLICATION-BASIC(X, Y, N)
        total = 0
        for j = 1 to N
            sum = 0
            for i = 1 to N
                sum = sum*10 + Y[j]*X[i]
            total = total*10 + sum
        return total

    T(N) = theta(N^2)

MULTIPLICATION WITH DIVIDE & CONQUER

    MULTIPLICATION-DC(X, Y, N)
        m = N/2
        if N == 1
            return X.Y
        XL = X/10^m
        XR = X mod 10^m

        YL = Y/10^m
        YR = Y mod 10^m

        p = MULTIPLICATION-DC(XL, YL, m)
        q = MULTIPLICATION-DC(XL, YR, m)
        r = MULTIPLICATION-DC(XR, YL, m)
        s = MULTIPLICATION-DC(XR, YR, m)

        return p*10^N + (q+r)*10^m + s    

    T(n) = {
        theta(N)                , n = 1
        4*T(N/2) + theta(N)     , otherwise
    }
    T(n) = theta(N^2)           , applying master theorem

KARATSUBA IDEA
Given N a length of X, Y numbers
Assume N is even number
    m = N/2
Besides:
    X = XL*10^m + XR
    Y = YL*10^m + YR

    X = LEFT*10^N    + MID*10^m             + RIGHT
    X = (XL*YL)*10^N + (XL*YR + YL*XR)*10^m + XR*YR
    
    However MID can be expressed as
        (XL+XR)*(YL+YR) - (XL*YL) - (XR*YR)
        (XL+XR)*(YL+YR) - LEFT - RIGHT


KARATSUBA IMPLEMENTATION
    
    KARATSUBA(X, Y)
        N = size(X || Y)
        m = N/2

        if N <= 1
            return X*Y

        XL = X/10^m
        XR = X mod 10^m

        YL = Y/10^m
        YR = Y mod 10^m
        
        p = KARATSUBA(XL, YL)
        q = KARATSUBA(XL+XR, YL+YR)
        s = KARATSUBA(XR, YR)

        return p*10^N + (q - p - s)*10^m + s    

    T(N) = {
        theta(N)                , n = 1
        3*T(N/2) + theta(N)     , otherwise        
    }
    T(n) = theta(N^lg(3)) 
         = theta(N^1.59)        , applying master theorem
    
 */
