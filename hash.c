#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // Include this for sqrt()

#define TABLE_SIZE 10

typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **table;
    int size;
    int (*hash_func)(const char *key, int size);
    void (*insert)(struct HashTable *ht, const char *key, int value);
    int (*search)(struct HashTable *ht, const char *key);
    void (*remove)(struct HashTable *ht, const char *key);
} HashTable;

int hash_division(const char *key, int size) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key) % size;
        key++;
    }
    return hash % size;
}

int hash_multiplicative(const char *key, int size) {
    double A = (5.0 - sqrt(5.0)) / 2.0;
    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key) % size;
        key++;
    }
    return (int)(size * ((hash * A) - (int)(hash * A)));
}

void chaining_insert(HashTable *ht, const char *key, int value) {
    int index = ht->hash_func(key, ht->size);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

int chaining_search(HashTable *ht, const char *key) {
    int index = ht->hash_func(key, ht->size);
    Node *node = ht->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void chaining_remove(HashTable *ht, const char *key) {
    int index = ht->hash_func(key, ht->size);
    Node *node = ht->table[index];
    Node *prev = NULL;

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void open_addressing_insert(HashTable *ht, const char *key, int value) {
    int index = ht->hash_func(key, ht->size);
    int original_index = index;

    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->key, key) == 0) {
            ht->table[index]->value = value;
            return;
        }
        index = (index + 1) % ht->size;
        if (index == original_index) {
            printf("Hash table is full!\n");
            return;
        }
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    ht->table[index] = new_node;
}

int open_addressing_search(HashTable *ht, const char *key) {
    int index = ht->hash_func(key, ht->size);
    int original_index = index;

    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->key, key) == 0) {
            return ht->table[index]->value;
        }
        index = (index + 1) % ht->size;
        if (index == original_index) {
            return -1;
        }
    }
    return -1;
}

void open_addressing_remove(HashTable *ht, const char *key) {
    int index = ht->hash_func(key, ht->size);
    int original_index = index;

    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->key, key) == 0) {
            free(ht->table[index]->key);
            free(ht->table[index]);
            ht->table[index] = NULL;
            return;
        }
        index = (index + 1) % ht->size;
        if (index == original_index) {
            return;
        }
    }
}

HashTable *create_hash_table(int size, int (*hash_func)(const char *, int), void (*insert)(HashTable *, const char *, int), 
                              int (*search)(HashTable *, const char *), void (*remove)(HashTable *, const char *)) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->size = size;
    ht->hash_func = hash_func;
    ht->insert = insert;
    ht->search = search;
    ht->remove = remove;
    ht->table = (Node **)calloc(size, sizeof(Node *));
    return ht;
}

void free_hash_table(HashTable *ht) {
	int i;
    for ( i = 0; i < ht->size; i++) {
        Node *node = ht->table[i];
        while (node != NULL) {
            Node *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    HashTable *ht_chaining = create_hash_table(TABLE_SIZE, hash_division, chaining_insert, chaining_search, chaining_remove);

    ht_chaining->insert(ht_chaining, "1", 100);
    ht_chaining->insert(ht_chaining, "2", 200);
    ht_chaining->insert(ht_chaining, "3", 300);

    printf("1: %d\n", ht_chaining->search(ht_chaining, "1"));
    printf("2: %d\n", ht_chaining->search(ht_chaining, "2"));
    printf("4: %d\n", ht_chaining->search(ht_chaining, "4"));

    ht_chaining->remove(ht_chaining, "2");
    printf("2 after remove: %d\n", ht_chaining->search(ht_chaining, "2"));

    free_hash_table(ht_chaining);

    HashTable *ht_open = create_hash_table(TABLE_SIZE, hash_multiplicative, open_addressing_insert, open_addressing_search, open_addressing_remove);

    ht_open->insert(ht_open, "10", 100);
    ht_open->insert(ht_open, "20", 200);
    ht_open->insert(ht_open, "30", 300);

    printf("10: %d\n", ht_open->search(ht_open, "10"));
    printf("20: %d\n", ht_open->search(ht_open, "20"));
    printf("40: %d\n", ht_open->search(ht_open, "40"));

    ht_open->remove(ht_open, "20");
    printf("20 after remove: %d\n", ht_open->search(ht_open, "20"));

    free_hash_table(ht_open);

    return 0;
}

