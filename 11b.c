
#include <stdio.h>
#include <limits.h>

// Function to insert an element
void insert(int ary[], int hFn, int size) {
    int element, pos, n = 0;

    printf("Enter key element to insert\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (ary[pos] != INT_MIN) {
        if (ary[pos] == INT_MAX)
            break;

        pos = (pos + 1) % hFn;
        n++;

        if (n == size) {
            printf("Hash table is full. No place to insert this element.\n");
            return;
        }
    }

    ary[pos] = element;
    printf("Element inserted at index %d\n", pos);
}

// Function to delete an element
void delete(int ary[], int hFn, int size) {
    int element, pos, n = 0;

    printf("Enter element to delete\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (n < size) {
        if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        } else if (ary[pos] == element) {
            ary[pos] = INT_MAX;
            printf("Element deleted\n");
            return;
        } else {
            pos = (pos + 1) % hFn;
        }

        n++;
    }

    printf("Element not found in hash table\n");
}

// Function to search an element
void search(int ary[], int hFn, int size) {
    int element, pos, n = 0;

    printf("Enter element you want to search\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (n < size) {
        if (ary[pos] == element) {
            printf("Element found at index %d\n", pos);
            return;
        } else if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        } else {
            pos = (pos + 1) % hFn;
        }

        n++;
    }

    printf("Element not found in hash table\n");
}

// Function to display the hash table
void display(int ary[], int size) {
    printf("Index\tValue\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t", i);

        if (ary[i] == INT_MIN) {
            printf("Empty\n");
        } else if (ary[i] == INT_MAX) {
            printf("Deleted\n");
        } else {
            printf("%d\n", ary[i]);
        }
    }
}

// Main function
int main() {
    int size, hFn, choice;

    printf("Enter size of hash table\n");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid hash table size\n");
        return 1;
    }

    printf("Enter hash function (if mod 10, enter 10)\n");
    scanf("%d", &hFn);

    if (hFn <= 0 || hFn > size) {
        printf("Invalid hash function value\n");
        return 1;
    }

    int ary[size];

    for (int i = 0; i < size; i++)
        ary[i] = INT_MIN;

    do {
        printf("\nEnter your choice\n");
        printf("1 -> Insert\n");
        printf("2 -> Delete\n");
        printf("3 -> Display\n");
        printf("4 -> Search\n");
        printf("0 -> Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(ary, hFn, size);
                break;

            case 2:
                delete(ary, hFn, size);
                break;

            case 3:
                display(ary, size);
                break;

            case 4:
                search(ary, hFn, size);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter correct choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
