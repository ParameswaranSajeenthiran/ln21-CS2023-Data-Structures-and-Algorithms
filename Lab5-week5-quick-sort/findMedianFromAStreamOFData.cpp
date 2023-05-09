#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

//calculate median of a sorted array
double findMedian(vector <int> v){
    int n = v.size();
    if(n % 2 == 0){
        return (v[n / 2] + v[n / 2 - 1]) / 2.0;
    }
    else{
        return  (double) v[n / 2];
    }
}




//insertion sort
void sort(vector <int> &v){
    int n = v.size();
    int j =v.size()-1;
    int key = v[j];
    j--;
  
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    
}

int main(){
    vector <int > test ={7,3,5,2};
    int n = test.size();
    vector<int> cuurentArray={};


    for(int i = 0; i < n; i++){
        cout<< "inerted "<<test[i]<< " ";
        cuurentArray.push_back(test[i]);
        cout << "Sorted ";
        sort(cuurentArray);
        printVector(cuurentArray);
               cout<< "Median ="<< fixed<< setprecision(1)<< findMedian(cuurentArray)<<endl;


    }

    return 0;




}