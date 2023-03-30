#include <iostream>
#include "linked_list.h"
#include <fstream>

int main () {

    std::ofstream file("test_result.txt");

    LinkedList *head = insert_after(nullptr);

    auto current = head;
    current->data = 0;

    for (int i = 1; i < 10; i++) {
        current = insert_after(current);
        current->data = i;
    }

    current = head;

    file << "before\n";

    while (current != nullptr) {
        file << current->data << " " << current << std::endl;
        current = current->next;
    }

    remove_after(head);

    auto new_head = reverse_rec(head);
    current = new_head;

    file << "\nafter\n";

    while (current != nullptr) {
        file << current->data << " " << current << std::endl;
        current = current->next;
    }

    new_head = reverse_itr(new_head);
    current = new_head;

    file << "\nafter again\n";

    while (current != nullptr) {
        file << current->data << " " << current << std::endl;
        current = current->next;
    }

    erase(new_head);

    file.close();

    return 0;

}