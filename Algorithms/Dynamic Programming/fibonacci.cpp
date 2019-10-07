#include<iostream>
#include<vector>
using namespace std;

//For timing
#include <chrono> 
using namespace std::chrono; 

class FibonacciSeriesTester{
    vector <int> fibForMemoization;

    public:
    FibonacciSeriesTester(int n){
        this->fibForMemoization.resize(n+1);
    }

    int simpleRecursion(int n){
        if(n<=1) return n;
        else return this->simpleRecursion(n-1) + this->simpleRecursion(n-2);
    }

    int tabulationMethod(int n){
        vector <int> fib{1, 1};
        for(int i=2; i<n; i++){ fib.push_back( fib[i-1] + fib[i-2] ); }
        return fib.back();
    }

    int memoizationMethod(int n){
        if (n <= 1){
            this->fibForMemoization[n] = n;
            return n;
        }
        this->fibForMemoization[n] = this->memoizationMethod(n-1) + this->memoizationMethod(n-2);
        return this->fibForMemoization[n];
    }
};

void calcTime(auto start){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << duration.count() << endl; 
}

int main(){
    cout << "Calculating 6th Fibonacci Number:\n";
    FibonacciSeriesTester tester(6);

    auto start = high_resolution_clock::now(); 
    cout << "Through simple recursion: " << tester.simpleRecursion(40) << endl;
    calcTime(start);

    start = high_resolution_clock::now(); 
    cout << "Through Tabulation: " << tester.tabulationMethod(40) << endl;
    calcTime(start);

    start = high_resolution_clock::now(); 
    cout << "Through Memoization: " << tester.memoizationMethod(40) << endl;
    calcTime(start);

    return 0;
}