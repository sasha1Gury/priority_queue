#include <iostream>
#include <stdio.h>
struct Element {
    int data;
    int priority;
    Element* next;
};

struct Queue {
    Element* tail = NULL, * head = (Element*)malloc(sizeof(Element));

    int flag = 1;

    void push(int d) {
        Element* e = (Element*)malloc(sizeof(Element)); // 1(head) 1 1(tail) 1
        e->data = d;
        //printf("%i e->data\n", e->data);
                //e->priority = d;
        e->next = NULL;

        if (flag) {
            head->next = e;
            tail = e;
            flag = 0;
            //printf("%i e->next \n", e->next);
        }
        else {
            Element* tmp = head->next, * temp = head;
            while (e->data > tmp->data && tmp->next != NULL) {
                tmp = tmp->next;
                temp = temp->next;
            }
            //printf("%i ostanowka na tmp\n", tmp->data);
            if (e->data < tmp->data) {
                e->next = tmp;
                temp->next = e;
            }
            else {
                e->next = tmp->next;
                tmp->next = e;
            }
        }

        /*else {
            tail->next = e;
            tail = e;
        }*/
    }

    void priority() {
        for (Element* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->priority > cur->next->priority) {
                std::cout << cur->data << " > " << cur->next->priority << " ";
            }
            else {
                std::cout << cur->data << " < " << cur->next->priority << " ";
            }
        }
    }

    int pop() {
        if (head == NULL) return 0;

        int tmp = head->data;

        Element* e = head;
        if (head == tail) {
            tail = NULL;
        }
        head = head->next;
        free(e);
        return tmp;
    }

    bool isEmpty() {
        if ((head == NULL) && (tail == NULL)) {
            return true;
        }
        else {
            return false;
        }
    }

    void print() {
        /*Element* cur = head;
        while (cur != nullptr) {
           std::cout << cur->data;
            cur = cur->next;
        }*/
        for (Element* cur = head->next; cur != NULL; cur = cur->next) {
            std::cout << cur->data << " ";
        }
    }

    void clear() {
        while (!isEmpty()) {
            int tmp = pop();
            tmp = 0;
        }
    }

};

int main() {
    Queue q;
    int tmp;
    q.push(3);
    q.push(1); q.push(0); q.push(-1); q.push(7); q.push(5); q.push(3); q.push(9); q.push(6); q.push(0); q.push(2); q.push(-54); q.push(87);
    q.print();
    //q.priority();
    /*std::cout << std::endl;
    q.clear();
    q.print();*/

}