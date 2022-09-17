// g++ recurrences.cpp -std=c++17 && ./a.out && rm ./a.out
#include <bits/stdc++.h>
using namespace std;

#define endll '\n'
#define pb push_back

typedef long long ll;

int recursive(int N)
{
    if (N == 1)
        return 1;
    return 2*recursive(N/2) + N*int(log2(N));
}

int solved(int N)
{ return (1<<int(log2(N))) + (N/2)*(int(log2(N)))*(int(log2(N))+1); }

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
        cout << recursive(n) << " " << solved(n) << endll;

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}
