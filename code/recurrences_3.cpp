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
    return 6*recursive(N/2) + N;
}

ll solved(ll N)
{
    return pow(6, log2(N)) + N * ((pow(3, log2(N))-1)/2); 
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

    vector<int> nums {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
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
