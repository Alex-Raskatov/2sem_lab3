#include <iostream>
#include "circullar_buffer.h"

int main () {

    CircBuffer *buffer = insert_after(nullptr);

    auto second = insert_after(buffer);

    for (int i = 0; i < 100; i++) insert_after(buffer);

    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);
    remove_after_in_step(buffer, 5);

    erase(buffer);

    return 0;
}