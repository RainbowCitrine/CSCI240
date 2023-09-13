#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime> 

std::vector<double> prefixAverages1(const std::vector<double>& X) {
    int size = X.size();
    std::vector<double> A(size, 0.0);

    for (int i = 0; i < size; ++i) {
        double a = 0;
        for (int j = 0; j <= i; ++j) {
            a += X[j];
        }
        A[i] = a / (i + 1);
    }
    return A;
}

std::vector<double> prefixAverages2(const std::vector<double>& X) {
    int size = X.size();
    std::vector<double> A(size, 0);
    double s = 0;

    for (int i = 0; i < size; ++i) {
        s += X[i];
        A[i] = s / (i + 1);
    }
    return A;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    std::vector<double> testCase = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

    auto start_time_test = std::chrono::high_resolution_clock::now();
    std::vector<double> res_test1 = prefixAverages1(testCase);
    std::vector<double> res_test2 = prefixAverages2(testCase);
    auto end_time_test = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time_test = end_time_test - start_time_test;

    std::cout << "Test Case Results:" << std::endl;
    std::cout << "Method 1: ";
    for (double result : res_test1) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    std::cout << "Method 2: ";
    for (double result : res_test2) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    std::cout << "Elapsed time for test case: " << elapsed_time_test.count() * 1000 << " milliseconds" << std::endl;

    for (int numElements : {100, 1000, 10000, 100000}) {
        std::vector<double> X(numElements);

        for (int i = 0; i < numElements; ++i) {
            X[i] = static_cast<double>(std::rand()) / RAND_MAX * 20000 - 10000;
        }

        auto start_time = std::chrono::high_resolution_clock::now();
        std::vector<double> res = prefixAverages1(X);
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end_time - start_time;

        auto start_time2 = std::chrono::high_resolution_clock::now();
        std::vector<double> res2 = prefixAverages2(X);
        auto end_time2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time2 = end_time2 - start_time2;

        std::cout << "Elapsed time (Method 1) for " << numElements << " elements: " << elapsed_time.count() * 1000 << " milliseconds" << std::endl;
        std::cout << "Elapsed time (Method 2) for " << numElements << " elements: " << elapsed_time2.count() * 1000 << " milliseconds" << std::endl;
    }

    return 0;
}
