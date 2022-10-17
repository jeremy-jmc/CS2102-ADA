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
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
    left-sum = -INF
    sum  = 0
    for i = mid downto low
        sum = sum + A[i]
        if sum > left-sum
            left-sum = sum
            max-left = i
    
    right-sum = -INF
    sum = 0
    for j = mid+1 to high
        sum = sum + A[j]
        if sum > right-sum
            right-sum = sum
            max-right = j
    
    return (max-left, max-right, left-sum + right-sum)

FIND-MAX-SUBARRAY(A, low, high)
    if high == low
        return (low, high, A[low])
    else
        mid = low + (high-low)/2

        left-low,  left-high,  left-sum  = FIND-MAX-SUBARRAY(A, low, mid)
        right-low, right-high, right-sum = FIND-MAX-SUBARRAY(A, mid+1, high)

        cross-low, cross-high, cross-sum = 
            FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)

        return max(cross-sum, left-sum, right-sum)
 */