// g++ main.cpp -std=c++17 && ./a.out && rm ./a.out

#include <bits/stdc++.h>
using namespace std;

#define endll '\n'
#define pb push_back

typedef long long ll;

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

    int N = 10, curr_size = 1, left, l, mid, r;
    for (; curr_size <= N; curr_size*=2)
    {
        cout << curr_size << endll;
        left = 1;
        while (left <= N)
        {
            l = left;
            mid = min(left + curr_size - 1, N);
            r = min(left + 2*curr_size - 1, N);
            cout << "\t" << l << " " << mid << " " << r << endll;
            left = r + 1;   
        }
    }

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}
