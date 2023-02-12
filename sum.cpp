#include <vector>
#include <thread>
#include <algorithm>
#include "sum.h"

namespace sum_utils {
    sum::sum(int* nums, int size) {
        this->nums = nums;
        this->size = size;
    }


    int sum::sum_arr() {
        return this->sum_arr(1);
    }

    void sum::sum_helper(int* const result_location, int* const arr_start, int const n_additions) {
        int sub_result = 0;
        for(int i = 0; i < n_additions; i++) {
            sub_result += arr_start[i];
        }

        *result_location = sub_result;
    }

    int sum::sum_arr(const int n_threads) {

        int results_arr[n_threads];
        int indices_per_thread = (this->size + n_threads - 1) / n_threads;
        const size_t balls = n_threads;
        std::thread threads[n_threads];

        for(int i = 0; i < n_threads; i++) {
            int n_additions = std::min(indices_per_thread, this->size - indices_per_thread * i);
            threads[i] = std::thread(sum_helper, &results_arr[i], this->nums + i * n_additions, n_additions);
        }

        for(int i = 0; i < n_threads; i++) {
            threads[i].join();
        }

        int result = 0;
        for(int i = 0; i < n_threads; i++) {
            result += results_arr[i];
        }

        return result;
    
    }
}