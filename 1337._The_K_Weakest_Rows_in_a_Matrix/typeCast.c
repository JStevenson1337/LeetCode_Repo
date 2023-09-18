#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Row;

void processRow(void *a) {
    Row *rowA = (Row *)a;
    // Access the fields of the Row struct
    printf("ID: %d\n", rowA->id);
    printf("Name: %s\n", rowA->name);
}

int main() {
    Row row;
    row.id = 1;
    strcpy(row.name, "John Doe");

    // Pass the address of the row struct to the processRow function
    processRow(&row);

    return 0;
}