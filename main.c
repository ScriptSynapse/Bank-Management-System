#include <stdio.h>

#define MAX_ACCOUNTS 100
#define MAX_ATTEMPTS 3

struct BankAccount {
    int accNo;
    char name[50];
    int pin;
    float balance;
    int locked;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int readInt(int *value) {
    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    return 1;
}

int readFloat(float *value) {
    if (scanf("%f", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    return 1;
}

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
    if (!readInt(&accounts[totalAccounts].accNo)) {
        printf("Invalid input.\n");
        return;
    }

    if (findAccount(accounts[totalAccounts].accNo) != -1) {
        printf("Account already exists.\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    clearInputBuffer();
    fgets(accounts[totalAccounts].name, sizeof(accounts[totalAccounts].name), stdin);

    printf("Set 4-digit PIN: ");
    if (!readInt(&accounts[totalAccounts].pin) ||
        accounts[totalAccounts].pin < 1000 ||
        accounts[totalAccounts].pin > 9999) {
        printf("PIN must be exactly 4 digits.\n");
        return;
    }

    printf("Enter Initial Balance: ");
    if (!readFloat(&accounts[totalAccounts].balance) ||
        accounts[totalAccounts].balance < 0) {
        printf("Invalid balance.\n");
        return;
    }

    accounts[totalAccounts].locked = 0;
    totalAccounts++;

    printf("\nAccount created successfully.\n");
}

void depositMoney(int index) {
    float amount;

    printf("\nEnter amount to deposit: ");
    if (!readFloat(&amount) || amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit successful.\n");
}

void withdrawMoney(int index) {
    float amount;

    printf("\nEnter amount to withdraw: ");
    if (!readFloat(&amount) || amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Please collect your cash.\n");
}

void checkBalance(int index) {
    printf("\nAccount Number: %d\n", accounts[index].accNo);
    printf("Account Holder: %s", accounts[index].name);
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

        if (!readInt(&choice)) {
            printf("Invalid input. Enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: depositMoney(index); break;
            case 2: withdrawMoney(index); break;
            case 3: checkBalance(index); break;
            case 4: printf("Logged out successfully.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void login() {
    int accNo, pin, attempts = 0;

    printf("\nEnter Account Number: ");
    if (!readInt(&accNo)) {
        printf("Invalid input.\n");
        return;
    }

    int index = findAccount(accNo);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    if (accounts[index].locked) {
        printf("Account is locked.\n");
        return;
    }

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter PIN: ");
        if (!readInt(&pin)) {
            printf("Invalid input.\n");
            continue;
        }

        if (pin == accounts[index].pin) {
            printf("\nLogin successful.\n");
            accountMenu(index);
            return;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n",
                   MAX_ATTEMPTS - attempts);
        }
    }

    accounts[index].locked = 1;
    printf("Account locked due to multiple incorrect attempts.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (!readInt(&choice)) {
            printf("Invalid input. Enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: printf("Thank you for using the system.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
