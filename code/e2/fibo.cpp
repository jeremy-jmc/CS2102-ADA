#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

ll fibo_dp(ll N){
    vector<ll> M{0, 1};
    for (size_t i = 2; i <= N; i++)
        M.pb(M[i-1]+M[i-2]);
    return M[N];
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
    for (size_t i = 1; i <= 10; i++)
        cout << fibo_dp(i) << endl;
    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

// g++ fibo.cpp -std=c++17 && ./a.out && rm ./a.out