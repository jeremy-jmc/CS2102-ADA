#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C(ll N, ll K)
{
    if (N == K || K == 0)
        return 1;
    return C(N-1, K) + C(N-1, K-1);
}

ll C_(ll N, ll K)
{
    vector<vector<ll>> CM(N+1, vector<ll>(N+1, 0));
    for (int i = 0; i <= N; i++)
        CM[i][i] = CM[i][0] = 1;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i - 1; j++)
            CM[i][j] = CM[i-1][j-1] + CM[i-1][j];
    return CM[N][K];
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

    cout << C(6, 2) << " " << C_(6, 2) << endl;
    cout << C(5, 2) << " " << C_(5, 2) << endl;
    cout << C(8, 2) << " " << C_(8, 2) << endl;

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}
// g++ binomial_coeff.cpp -std=c++17 && ./a.out && rm ./a.out

/*
C(i, j) = {
    1                               i=j o j=0
    C(i-1, j-1) + C(i-1, j)         cc
}
*/