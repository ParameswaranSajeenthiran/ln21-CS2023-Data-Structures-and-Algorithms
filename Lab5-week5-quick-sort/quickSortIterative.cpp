#include <iostream>
#include <vector>
#include <chrono>


using namespace std;




void quickSortIterative(vector<int> &v, int low, int high)
{
    int stack[high - low + 1];
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;
    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (v[j] < pivot)
            {
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);
        int p = i + 1;
        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// sort array using quick sort recursively

void quickSortRecursive(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (v[j] < pivot)
            {
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);
        int p = i + 1;
        quickSortRecursive(v, low, p - 1);
        quickSortRecursive(v, p + 1, high);
    }
}

void testQuickSortForVectorOfSzeN(int n ){
    //generate a random vector
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;
    //sort using quick sort
    auto start = chrono::high_resolution_clock::now();
    quickSortRecursive(v, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by quick sort recursive: " << duration.count() << " nanoseconds for n= "<<n<<  endl;
    //sort using quick sort iterative
    start = chrono::high_resolution_clock::now();
    quickSortIterative(v, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by quick sort iterative: " << duration.count() << " nanoseconds for n= "<<n<<  endl;
   
}

int main (){
    for (int i=10000; i<=100000; i+=10000)
        testQuickSortForVectorOfSzeN(i);
    
    return 0;
}