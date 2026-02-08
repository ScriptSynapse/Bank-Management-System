#include <stdio.h>

int accountNumber = 0;
char accountHolder[50];
float balance = 0.0;

void createAccount() {
    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accountHolder);

    printf("Enter Initial Balance: ");
    scanf("%f", &balance);

    printf("\nAccount created successfully!\n");
}

void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else {
        balance += amount;
        printf("Amount deposited successfully.\n");
    }
}

void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > balance) {
        printf("Insufficient balance.\n");
    } else {
        balance -= amount;
        printf("Please collect your cash.\n");
    }
}

void checkBalance() {
    printf("\nAccount Number: %d\n", accountNumber);
    printf("Account Holder: %s\n", accountHolder);
    printf("Current Balance: %.2f\n", balance);
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                if (accountNumber == 0)
                    printf("\nPlease create an account first.\n");
                else
                    depositMoney();
                break;

            case 3:
                if (accountNumber == 0)
                    printf("\nPlease create an account first.\n");
                else
                    withdrawMoney();
                break;

            case 4:
                if (accountNumber == 0)
                    printf("\nPlease create an account first.\n");
                else
                    checkBalance();
                break;

            case 5:
                printf("\nThank you for using the bank system.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
