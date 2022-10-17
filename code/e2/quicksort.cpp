// g++ quicksort.cpp -std=c++17 && ./a.out && rm ./a.out

#include <bits/stdc++.h>
using namespace std;

#define endll '\n'
#define pb push_back

typedef long long ll;

const int INF = INT_MAX;
const int min_value = -1e2, max_value = 1e2;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// UTILITIES
int random (int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "["; for (auto el : v) cout << el << ", "; cout << "\b\b]\n"; }

vector<int> random_vec(int n)
{
    vector<int> vec;
    for (int i=1; i<=n; i++)
        vec.pb(random(min_value, max_value));
    return vec;
}

int partition(vector<int>& arr, int low, int high)
{
    auto pivot = arr[high];
    auto i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    cout << arr[i+1] << " -> ";
    for (size_t i = low; i <= high; i++)
        cout << arr[i] << " ";
    cout << endll;
    return i+1;
}

void quicksort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        auto pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
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
    
    int N = 15; 
    // cin >> N;
    auto vec = random_vec(N);
    PRINT_VEC(vec);
    quicksort(vec, 0, N-1);
    PRINT_VEC(vec);

    time(&end);
    auto time_taken = double(end-start);
    cout << "\tTime: " << fixed << time_taken << setprecision(5) << " sec\n";
    return 0;
}

// https://www.geeksforgeeks.org/quick-sort/
// https://web.stanford.edu/class/archive/cs/cs161/cs161.1168/lecture6.pdf