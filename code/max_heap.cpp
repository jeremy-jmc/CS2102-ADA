#include <bits/stdc++.h>
using namespace std;

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "["; for (auto el : v) cout << el << ", "; cout << "\b\b]\n"; }

int parent(int i){ return i/2; }

int left(int i){ return 2*i; }

int right(int i){ return 2*i + 1;}

int heap_maximum(const vector<int>& A){ return A[1]; }

void max_heapify(vector<int>& A, int i)
{
    auto heap_size = A.size();
    if (i <= heap_size)
    {
        auto l = left(i);
        auto r = right(i);

        int largest = -1;
        if (l <= heap_size && A[l] > A[i]) 
            largest = l;
        else largest = i;

        if (r <= heap_size && A[r] > A[largest]) 
            largest = r;
        
        if (largest != i)
        {
            swap(A[i], A[largest]);
            max_heapify(A, largest);
        }
    }
}

void build_max_heap(vector<int>& A)
{
    auto heap_size = A.size();
    for (int i = heap_size/2; i >= 1; i--)
    {
        max_heapify(A, i);
        PRINT_VEC(A);
    }
}

void heap_increase_key(vector<int>& A, int i, int key)
{
    cout << i << ' ' << key << endl;
    if (key < A[i])
    {
        cout << "new key is smaller than current key";
        return;
    }
    A[i] = key;
    while (i > 1 && A[parent(i)] < A[i])
    {
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

void max_heap_insert(vector<int>& A, int key)
{
    A.push_back(INT_MIN);
    auto heap_size = A.size();
    heap_increase_key(A, heap_size-1, key);
}

void heap_delete(vector<int>& A, int i)
{   // i: pos to delete
    heap_increase_key(A, i, INT_MAX);       // lg(n)
    auto heap_size = A.size();
    A[1] = A[heap_size-1];
    A.pop_back();                           // c1       A.resize(A.size()-1);
    max_heapify(A, 1);                      // lg(n)
}

int heap_extract_maximum(vector<int>& A)
{
    auto mx = A[1];
    heap_delete(A, 1);
    return mx;
}

int main()
{
    vector<int> A;

    A = {-1, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    PRINT_VEC(A);
    max_heapify(A, 3);
    PRINT_VEC(A);

    A = {-1, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    build_max_heap(A);

    A = {-1, 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2};
    build_max_heap(A);
    PRINT_VEC(A);
    max_heap_insert(A, 10);
    PRINT_VEC(A);
    cout << heap_extract_maximum(A) << endl;
    PRINT_VEC(A);
    return 0;
}

// g++ max_heap.cpp -std=c++17 && ./a.out && rm ./a.out