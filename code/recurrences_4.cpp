// g++ recurrences_3.cpp -std=c++17 && ./a.out && rm ./a.out
#include <bits/stdc++.h>
using namespace std;

#define endll '\n'
#define pb push_back

typedef long long ll;

ll recursive(ll N)
{
    if (N == 1)
        return 1;
    return 7*recursive(N/3) + N*N;
}

ll lllog(double base, double x) {
    return (ll)(log(x) / log(base));
}

ll solved(ll N)
{
    return 4.5*N*N - (pow(7, lllog(3, N)+1))/2; 
}

int main()
{
// #ifndef TEST
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    vector<int> nums {1, 3, 9, 27, 81, 243, 243*3, 243*3*3, 243*3*3*3, 243*3*3*3*3, 243*3*3*3*3*3, 243*3*3*3*3*3*3};
    for (const auto& n : nums)
    {
        auto r = recursive(n);
        auto s = solved(n);

        cout << r << " " << s << endll;
        // cout << "recursive: " << r << endint;
        // cout << "solved   : " << s << endint;
    }
        

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}
