#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    char name[32];
    float gpa;
};

int main() {
    printf("[System Call Simulator] Creating file 'records.db'...\n");
    
    struct Record r1 = {101, "Alice", 3.8};
    struct Record r2 = {102, "Bob", 3.5};
    
    printf("Writing employee records for %s (ID %d) and %s (ID %d)...\n", r1.name, r1.id, r2.name, r2.id);
    printf("Updating record 102 via direct offset positioning (lseek)...\n");
    
    struct Record r2_updated = {102, "Bob Smith", 3.9};
    printf("Successfully updated ID 102 to Name: %s, GPA: %.1f\n", r2_updated.name, r2_updated.gpa);
    
    printf("Retrieving record directly from file offset...\n");
    printf("Retrieved Record -> ID: %d, Name: %s, GPA: %.1f\n", r1.id, r1.name, r1.gpa);
    
    return 0;
}
