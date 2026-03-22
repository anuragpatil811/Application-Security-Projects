//gcc -o inventory_management inventory_management.c
//gcc -o exploit exploit.c
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];

void add_item() {
    char name[20];
    int quantity;
    printf("Enter item name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].quantity == 0) {
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            printf("Item added successfully!\n");
            return;
        }
    }
    printf("Inventory is full!\n");
}

void display_inventory() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i].quantity > 0) {
            printf("Item %d: %s - Quantity: %d\n", i+1, inventory[i].name, inventory[i].quantity);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Internal Inventory Management System\n");
        printf("1. Add item\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}