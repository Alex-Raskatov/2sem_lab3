#include "circullar_buffer.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <ostream>

CircBuffer * flav_task_buf(CircBuffer *buffer, unsigned size, unsigned task_step) {

    auto current = buffer;
    auto after_corpse = remove_after_in_step(current, task_step);

    while (current != after_corpse) {
        current = after_corpse;
        after_corpse = remove_after_in_step(current, task_step);
    }

    return current;
}

int flav_task_arr(int array[], unsigned size, unsigned task_step) {

    int idx = 0, current_size = size, counter;

    while (current_size > 1) {
        idx = (idx + task_step) % current_size;
        for (int j = idx; j < current_size-1; j++) {
            array[j] = array[j+1];
        }
        --current_size;
    }

    return counter;

}


int main() {
    std::ofstream file_buf("flav_buf_data.txt");
    std::ofstream file_arr("flav_arr_data.txt");

    unsigned start = 1000, stop = 10000, step = 100, task_step = 3;

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        int array[SIZE];

        for (int i = 0; i < SIZE; i++) {
            array[i] = i;
        }

        CircBuffer *buffer = insert_after(nullptr);
        buffer->data = 0;
        CircBuffer *current = buffer, *next;

        for (int i = 1; i < SIZE; i ++) {
            next = insert_after(current);
            next->data = i;
            current = next;
        }

        //начинаем тестировать время 

        auto begin = std::chrono::steady_clock::now();

        buffer = flav_task_buf(buffer, size, task_step);

        auto end = std::chrono::steady_clock::now();

        auto time_span_buf = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        begin = std::chrono::steady_clock::now();

        flav_task_arr(array, size, task_step);

        end = std::chrono::steady_clock::now();

        auto time_span_arr = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        // заканчиваем тестировать время


        /* if (buffer == nullptr) std::cout << "nullptr" << std::endl;
        else{
            auto tmp = buffer->next;
            std::cout << buffer->data << " " << buffer << std::endl;
            while (tmp != buffer) {
                std::cout << tmp->data << " " << tmp << std::endl;
                tmp = tmp->next;
            }
        } */

        erase(buffer);

        file_buf << size << " " << time_span_buf.count() << '\n';
        file_arr << size << " " << time_span_arr.count() << '\n';
    }

    file_buf.close();
    file_arr.close();

    return 0;
}