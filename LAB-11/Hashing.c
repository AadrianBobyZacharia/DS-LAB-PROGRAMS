#include <stdio.h>

#define MAX_EMPLOYEES 100
#define MAX_MEMORY_LOCATIONS 50

struct Employee {
    int key;
    // Add other employee details as needed
};

struct HashTable {
    struct Employee table[MAX_MEMORY_LOCATIONS];
    int occupied[MAX_MEMORY_LOCATIONS]; // Flag to check if a location is occupied
};

int hashFunction(int key, int m) {
    return key % m; // Remainder method
}

void insertRecord(struct HashTable* ht, int key, struct Employee emp) {
    int hashValue = hashFunction(key, MAX_MEMORY_LOCATIONS);

    while (ht->occupied[hashValue]) {
        // Collision occurred, linear probing
        hashValue = (hashValue + 1) % MAX_MEMORY_LOCATIONS;
    }

    // Insert the record at the computed hash value
    ht->table[hashValue] = emp;
    ht->occupied[hashValue] = 1; // Mark the location as occupied
}

void displayHashTable(struct HashTable* ht) {
    printf("Memory Location\tEmployee Record\n");

    for (int i = 0; i < MAX_MEMORY_LOCATIONS; i++) {
        if (ht->occupied[i]) {
            printf("%d\t\t%d\n", i, ht->table[i].key);
            // Print other employee details as needed
        }
    }
}

int main() {
    struct HashTable hashTable;
    for (int i = 0; i < MAX_MEMORY_LOCATIONS; i++) {
        hashTable.occupied[i] = 0; // Initialize all locations as unoccupied
    }

    // Sample employee records
    struct Employee emp1 = {1234 /* key /, / other details */};
    struct Employee emp2 = {5678 /* key /, / other details */};
    struct Employee emp3 = {9876 /* key /, / other details */};

    // Insert employee records into the hash table
    insertRecord(&hashTable, emp1.key, emp1);
    insertRecord(&hashTable, emp2.key, emp2);
    insertRecord(&hashTable, emp3.key, emp3);

    // Display the hash table
    displayHashTable(&hashTable);

    return 0;
}
