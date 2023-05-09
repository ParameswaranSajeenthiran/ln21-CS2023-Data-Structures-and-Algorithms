#include <iostream>
#include <vector>
#include <chrono>
using namespace std;



void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (v[i] < v[j])
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
    }
    while (i <= mid)
        temp.push_back(v[i++]);
    while (j <= high)
        temp.push_back(v[j++]);
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];
}

void mergeSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}

int main()
{
int n;
cin >> n;
    //generate a random vector
    vector<int> v (n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;




    // vector<int> v = {5, 4, 3, 2, 1};
    //measure time taken by merge sort
    auto start = chrono::high_resolution_clock::now();
     mergeSort(v, 0, v.size() - 1);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by merge sort: " << duration.count() << " microseconds" << endl;

    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";
    return 0;
}


