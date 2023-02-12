#ifndef SUM_UTILS_H
#define SUM_UTILS_H

#include <vector>

namespace sum_utils {
    class sum {
        private:
            int* nums;
            int size;
            static void sum_helper(int*, int*, int);

        public:
            sum(int*, int);
            int sum_arr(const int);
            int sum_arr();
    };

}

#endif
