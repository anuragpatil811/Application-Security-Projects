#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 3
#define MAX_NAME_LENGTH 5
int i;
// Structure to represent a bank account
typedef struct {
 int account_number;
 char owner[MAX_NAME_LENGTH];
 float balance;
} Account;
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;
// Function to create a new account
void create_account(int account_number, const char *owner, float balance) {
 if (num_accounts < MAX_ACCOUNTS) {
 Account new_account;
 new_account.account_number = account_number;
 // Check for buffer overflow
 if (strlen(owner) > MAX_NAME_LENGTH) {
 printf("Buffer Overflow: Owner name exceeds maximum length.\n");
 return;
 }

 strcpy(new_account.owner, owner);
 new_account.balance = balance;
 accounts[num_accounts++] = new_account;
 printf("Account created successfully.\n");
 } else {
 printf("Cannot create account. Maximum number of accounts reached.
\n");
 }
}
// Function to deposit money into an account
void deposit(int account_number, float amount) {
 for (i = 0; i < num_accounts; i++) {
 if (accounts[i].account_number == account_number) {
 accounts[i].balance += amount;
 printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
 return;
 }
 }
 printf("Account not found.\n");
}
// Function to withdraw money from an account
void withdraw(int account_number, float amount) {
 for (i = 0; i < num_accounts; i++) {
 if (accounts[i].account_number == account_number) {
 if (accounts[i].balance >= amount) {
 accounts[i].balance -= amount;
 printf("Withdrawal successful. New balance: %.2f\n",
accounts[i].balance);
 } else {
 printf("Insufficient funds.\n");
 }
 return;
 }
 }
 printf("Account not found.\n");
}
// Function to display account information
void display_account_info(int account_number) {
 for (i = 0; i < num_accounts; i++) {
 if (accounts[i].account_number == account_number) {
 printf("Account Number: %d\n", accounts[i].account_number);
 printf("Owner: %s\n", accounts[i].owner);
 printf("Balance: %.2f\n", accounts[i].balance);
 return;
 }
 }
 printf("Account not found.\n");
}
int main() {
 int choice, account_number;
 char owner[MAX_NAME_LENGTH];
 float balance, amount;
 do {
 printf("\nLegacy Banking System Menu\n");
 printf("1. Create Account\n");
 printf("2. Deposit\n");
 printf("3. Withdraw\n");
 printf("4. Display Account Information\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter account number: ");
 scanf("%d", &account_number);
 printf("Enter owner name: ");
 scanf("%s", owner);
 printf("Enter initial balance: ");
 scanf("%f", &balance);
 create_account(account_number, owner, balance);
 break;
 case 2:
 printf("Enter account number: ");
 scanf("%d", &account_number);
 printf("Enter deposit amount: ");
 scanf("%f", &amount);
 deposit(account_number, amount);
 break;
 case 3:
 printf("Enter account number: ");
 scanf("%d", &account_number);
 printf("Enter withdrawal amount: ");
 scanf("%f", &amount);
 withdraw(account_number, amount);
 break;
 case 4:
 printf("Enter account number: ");
 scanf("%d", &account_number);
 display_account_info(account_number);
 break;
 case 5:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice. Please try again.\n");
 }
 } while (choice != 5);
 return 0;
} 
