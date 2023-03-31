#include <iostream>
#include "dinamic_array.h"
#include <fstream>
#include <iostream>
#include <chrono>

int main() {
    
    std::ofstream first("da_first.txt");
    std::ofstream second("da_second.txt");
    std::ofstream third("da_third.txt");

    DynamicArray da_1 = new_array(0);
    DynamicArray da_3 = new_array(0);
    DynamicArray da_2 = new_array(0);
    DynamicArray &da_1_ref = da_1, &da_2_ref = da_2, &da_3_ref = da_3;

    unsigned start = 0, stop = 10000000;

    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    auto time_span_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    auto time_span_2 = time_span_1;
    auto time_span_3 = time_span_1;

    for (int i = start; i < stop; i++){
        begin = std::chrono::steady_clock::now();
        push_back_first(da_1_ref, 0);
        end = std::chrono::steady_clock::now();
        time_span_1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        begin = std::chrono::steady_clock::now();
        push_back_second(da_2_ref, 0);
        end = std::chrono::steady_clock::now();
        time_span_2 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        begin = std::chrono::steady_clock::now();
        push_back_third(da_3_ref, 0);
        end = std::chrono::steady_clock::now();
        time_span_3 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        if (i % 1000 == 0 and i > 10) {
            first << i << " " << time_span_1.count() << '\n';
            second << i << " " <<  time_span_2.count() << '\n';
            third << i << " " << time_span_3.count() << '\n';
        }
    }

    first.close();
    second.close();
    third.close();

    erase(da_1_ref);
    erase(da_2_ref);
    erase(da_3_ref);

    return 0;
}