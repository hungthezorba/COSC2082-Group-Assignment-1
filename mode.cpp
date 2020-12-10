#include <iostream>
#include "mode.h"

using namespace std;

struct node {
    double data;
    node *next;
};

class linked_mode_list {
    private:
        node *head, *tail;
    public:
        linked_mode_list() {
            head = NULL;
            tail = NULL;
        }

        void add_node(double value) {
            node *tmp = new node;
            tmp -> data = value;
            tmp -> next = NULL;

            if (head == NULL) {
                head = tmp;
                tail = tmp;
            } else {
                tail -> next = tmp;
                tail = tail -> next;
            }
        }

        void printMode() {
            node *tmp;
            tmp = head;
            while (tmp != NULL) {
                cout << tmp -> data << " ";
                tmp = tmp -> next;
            }
        }
};

void findMode(double array[], int arraySize) {
    double maxCount = 0;
    linked_mode_list mode;
    double current_mode = NULL;
    double count[arraySize][2];
    for (int i = 0; i < arraySize; i++) {
        count[i][0] = array[i];
        count[i][1] = 0;

        for (int j = 0; j < arraySize; j++) {
            if (array[i] == array[j]) {
                count[i][1]++;
            }
        }

        if (count[i][1] > maxCount) {
            maxCount = static_cast<double>(count[i][1]);
        }
    }
    for (int i = 0; i < arraySize; i++) {
        if (count[i][1] == maxCount) {
            if (current_mode == NULL || current_mode != count[i][0]) {
                current_mode = count[i][0];
                mode.add_node(count[i][0]);
            }
        }
    }
    mode.printMode();
}