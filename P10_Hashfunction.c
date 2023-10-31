#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Data {
    int key;
    int value;
};

struct Data* hashArray[SIZE];
struct Data* dummyItem;
struct Data* item;

int hashCode(int key) {
    return key % SIZE;
}

struct Data *search(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int key, int value) {
    struct Data *item = (struct Data*) malloc(sizeof(struct Data));
    item->value = value;
    item->key = key;

    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

void display() {
    int i;
    printf("Index\tKey\tValue\n");
    for (i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("%d\t%d\t%d\n", i, hashArray[i]->key, hashArray[i]->value);
        } else {
            printf("%d\t---\t---\n", i);
        }
    }
}

int main() {
    dummyItem = (struct Data*) malloc(sizeof(struct Data));
    dummyItem->value = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();

    int keyToSearch;
    printf("Enter the key to search: ");
    scanf("%d", &keyToSearch);

    item = search(keyToSearch);
    if (item != NULL) {
        printf("Element found: %d\n", item->value);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
