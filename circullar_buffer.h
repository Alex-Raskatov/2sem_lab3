struct CircBuffer {
    int data;
    CircBuffer *next;
};

CircBuffer* insert_after(CircBuffer * const current) {

    /* добавляет новый узел в существующий список сразу за переданным узлом
    с адресом current и возвращает указатель на созданный узел,
    если в качестве аргумента передано значение nullptr, то функция
    создаёт новый узел и возвращает его адрес */

    if (current == nullptr) {
        CircBuffer *head = new CircBuffer {0, nullptr};
        head->next = head;
        return head;
    }
    else {
        CircBuffer *tmp = current->next;
        current->next = new CircBuffer {0, tmp};
        return current->next;
    }
}

CircBuffer* remove_after(CircBuffer * const current) {

    /* удаляет из существующего списка узел, который идёт сразу за current,
    восстанавливает структуру списка и возвращает указатель на элемент,
    который теперь следует за элементом current, если в качестве аргумента
    передано значение nullptr, то функция ничего не делает и возвращает nullptr; */

    if (current == nullptr) return nullptr;
    else {
        if (current->next == current) {
            delete current;
            return nullptr;
        }
        CircBuffer *tmp = current->next->next;
        delete current->next;
        current->next = tmp;
        return current->next;
    }
}

CircBuffer* remove_after_in_step(CircBuffer * const current, int step) {

    /* удаляет из существующего списка узел, который идёт за current через step элементов,
    восстанавливает структуру списка и возвращает указатель на элемент,
    который теперь следует за элементом current, если в качестве аргумента
    передано значение nullptr, то функция ничего не делает и возвращает nullptr,
    если в списке всего один элемент, то возвращает указатель на него */

    if (current == nullptr) return nullptr;
    else {
        if (current->next == current) {
            return current;
        } else {
            CircBuffer *tmp = current;
            for (int i = 0; i < step; i++) {
                tmp = tmp->next;
            }
            //CircBuffer *tmp_next = tmp->next->next;
            //delete tmp->next;
            //tmp->next = tmp_next;
            //return tmp_next;
            CircBuffer *new_tmp = remove_after(tmp);
            return new_tmp;
        }
    }
}


void erase(CircBuffer * const head) {
    //считая, что узел по адресу head является элементом списка, удаляет все узлы этого списка

    if (head->next == head) {
        delete head;
        return;
    }
    else {
        while (head->next != head) {
            remove_after(head);
        }
        delete head;
        return;
    }
}

/*
void erase(CircBuffer * const head) {
    //считая, что узел по адресу head является началом списка, удаляет все узлы этого списка

    if (head->next == nullptr) {
        delete head;
        return;
    }
    else {
        erase(head->next);
        delete head;
        return;
    }
}

CircBuffer* reverse_rec(CircBuffer * const head) {
    // рекурсивно разварачивает список, элементы связываются в обратном порядке,
    // при этом сами элементы не меняют своего расположения в памяти и не копируются, изменяются только связи

    if (head->next == nullptr) return head;
    else {
        CircBuffer *new_head = reverse_rec(head->next), *tmp = new_head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = head;
        head->next = nullptr;
        return new_head;
    }
}

CircBuffer* reverse_itr(CircBuffer * const head) {
    // итерационно разварачивает список, элементы связываются в обратном порядке,
    // при этом сами элементы не меняют своего расположения в памяти и не копируются, изменяются только связи

    CircBuffer *next_node = head->next, *current_node = head, *tmp;

    current_node->next = nullptr;

    while (next_node != nullptr) {
        tmp = current_node;             //сохраняем текущий элемент, который уже развернут
        current_node = next_node;       //сдвигаем текущий вперед
        next_node = next_node->next;    //сдвигаем следующий
        current_node->next = tmp;       //разворачиваем текущий
    }

    return current_node;
}
*/