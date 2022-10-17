#include <bits/stdc++.h>
using namespace std;

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "["; for (auto el : v) cout << el << ", "; cout << "\b\b]\n"; }

int parent(int i){ return i/2; }

int left(int i){ return 2*i; }

int right(int i){ return 2*i + 1;}

int heap_minimum(const vector<int>& A) { return A[1]; }

void min_heapify(vector<int>& A, int i)
{
    auto heap_size = A.size();
    if (i <= heap_size)
    {
        auto l = left(i);
        auto r = right(i);
        // cout << " (" << l << " " << r << ") ";

        auto smaller = i;
        if (l <= heap_size && A[l] < A[smaller])
            smaller = l;
        if (r <= heap_size && A[r] < A[smaller])
            smaller = r;
        swap(A[i], A[smaller]);
        if (smaller != i)
            min_heapify(A, smaller);
    }        
}

void build_min_heap(vector<int>& A)
{
    auto heap_size = A.size();
    for (int i = heap_size/2; i >= 1; i--)
    {
        // cout << i << " -> ";
        min_heapify(A, i);
        PRINT_VEC(A);
    }
}

void heap_decrease_key(vector<int>& A, int i, int key)
{
    // cout << i << ' ' << key << endl;
    if (key > A[i])
    {
        cout << "new key is greater than current key";
        return;
    }
    A[i] = key;
    while (i > 1 && A[i] < A[parent(i)])
    {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

void heap_delete(vector<int>& A, int i)
{
    heap_decrease_key(A, i, INT_MIN);
    auto heap_size = A.size();
    A[1] = A[heap_size];
    A.resize(heap_size-1);
    min_heapify(A, 1);
}

int heap_extract_minimum(vector<int>& A){
    auto mn = A[1];
    heap_delete(A, 1);
    return mn;
}

int main()
{
    vector<int> A;
    A = {-1, 15, 13, 9, 5, 12, 8, 7, 4, 11, 6, 2, 1};
    PRINT_VEC(A);
    build_min_heap(A);
    PRINT_VEC(A);
    cout << heap_extract_minimum(A) << endl;
    PRINT_VEC(A);
}

// g++ min_heap.cpp -std=c++17 && ./a.out && rm ./a.out