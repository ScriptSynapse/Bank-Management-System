#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_ATTEMPTS 3

struct BankAccount {
    int accNo;
    char name[50];
    int pin;
    float balance;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Find account index
int findAccount(int accNo) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNo == accNo) {
            return i;
        }
    }
    return -1;
}

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nAccount limit reached.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accounts[totalAccounts].accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accounts[totalAccounts].name);

    printf("Set 4-digit PIN: ");
    scanf("%d", &accounts[totalAccounts].pin);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[totalAccounts].balance);

    totalAccounts++;
    printf("\nAccount created successfully.\n");
}

void depositMoney(int index) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else {
        accounts[index].balance += amount;
        printf("Amount deposited successfully.\n");
    }
}

void withdrawMoney(int index) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
    } else {
        accounts[index].balance -= amount;
        printf("Please collect your cash.\n");
    }
}

void checkBalance(int index) {
    printf("\nAccount Number: %d\n", accounts[index].accNo);
    printf("Account Holder: %s\n", accounts[index].name);
    printf("Balance: %.2f\n", accounts[index].balance);
}

void accountMenu(int index) {
    int choice;

    do {
        printf("\n----- ACCOUNT MENU -----\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                depositMoney(index);
                break;

            case 2:
                withdrawMoney(index);
                break;

            case 3:
                checkBalance(index);
                break;

            case 4:
                printf("\nLogged out successfully.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 4);
}

void login() {
    int accNo, pin, attempts = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter PIN: ");
        scanf("%d", &pin);

        if (pin == accounts[index].pin) {
            printf("\nLogin successful. Welcome, %s!\n", accounts[index].name);
            accountMenu(index);
            return;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n",
                   MAX_ATTEMPTS - attempts);
        }
    }

    printf("\nAccount locked due to multiple incorrect PIN attempts.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                printf("\nThank you for using the bank system.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
