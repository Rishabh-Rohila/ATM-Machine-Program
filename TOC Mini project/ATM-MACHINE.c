#include <stdio.h>

// Define the states of the ATM machine
typedef enum {
    IDLE,
    PIN_ENTERED,
    TRANSACTION_SELECTION,
    BALANCE_ENQUIRY,
    WITHDRAWAL_AMOUNT_ENTERED,
    WITHDRAWAL_TRANSACTION,
    DEPOSIT_AMOUNT_ENTERED,
    DEPOSIT_TRANSACTION,
    FINISHED
} State;

// Define the initial balance in the account
#define INITIAL_BALANCE 1000

// Define a global variable to store the current balance
int currentBalance = INITIAL_BALANCE;

// Function to process user input and transition to the next state
State processInput(State currentState, int input) {
    switch (currentState) {
        case IDLE:
            if (input == 1) {
                printf("Enter your ATM PIN: 🔢");
                return PIN_ENTERED;
            }
            break;
        case PIN_ENTERED:
            if (input == 1234) {
                
                return TRANSACTION_SELECTION;
            } else {
                printf("Oops You Have Entered Invalid PIN, Please Try Again 😊\n");
                return IDLE;
            }
        case TRANSACTION_SELECTION:
            if (input == 1) {
                printf("Your current balance is ₹%d\n", currentBalance);
                return BALANCE_ENQUIRY;
            } else if (input == 2) {
                printf("Enter the amount to withdraw: ");
                return WITHDRAWAL_AMOUNT_ENTERED;
            } else if (input == 3) {
                printf("Enter the amount to deposit: ");
                return DEPOSIT_AMOUNT_ENTERED;
            } else if (input == 4) {
                printf("Thank you for using the ATM machine!\n");
                printf("Collect Your Card 💳 \n");
                printf("Have A Nice Day!\n");
                return FINISHED;
            }
            break;
        case BALANCE_ENQUIRY:
            if (input == 5) {
                printf("Give me a moment...\n");
                return TRANSACTION_SELECTION;
            }
            break;
        case WITHDRAWAL_AMOUNT_ENTERED:
            if (input <= currentBalance) {
                printf("Cash will Be In Your Hand Shortly.. ₹%d...\n", input);
                currentBalance -= input;
                return WITHDRAWAL_TRANSACTION;
            } else {
                printf("Oops Insufficient balance. Please enter a valid amount within: ₹" ,currentBalance);
                return WITHDRAWAL_AMOUNT_ENTERED;
            }
            break;
        case WITHDRAWAL_TRANSACTION:
            if (input == 5) {
                printf("Transaction completed successfully.\n");
                return TRANSACTION_SELECTION;
            }
            break;
        case DEPOSIT_AMOUNT_ENTERED:
            printf("We Are Updating Your Current Balance.. ₹%d...\n", input);
            currentBalance += input;
            return DEPOSIT_TRANSACTION;
        case DEPOSIT_TRANSACTION:
            if (input == 5) {
                printf("Transaction completed successfully.\n");
                return TRANSACTION_SELECTION;
            }
            break;
        case FINISHED:
            // No valid transitions from FINISHED state
            break;
    }
    
    // Default case: Invalid input or no state transition
    printf("Invalid input or no state transition.\n");
    return currentState;
}

int main() {
    State currentState = IDLE;
    int input;
    
    
    printf("Rishabh_1085, Mini Project for TOC\n");
printf("Welcome to the ATM machine!\n");
    while (currentState != FINISHED) {
        printf("\n");
        switch (currentState) {
            case IDLE:
                printf("1. Insert Your Card 😊\n");
                printf("Select an option: ");
                break;
            case PIN_ENTERED:
                break;
            case TRANSACTION_SELECTION:
               
                printf("1. Balance Enquiry\n");
                printf("2. Withdrawal Cash\n");
                printf("3. Deposit Cash\n");
                printf("4. Exit from ATM\n");
                printf("What Do You Want to Do - ");
                break;
            case BALANCE_ENQUIRY:
                printf("5. Return to Main Menu\n");
                printf("Select an option: ");
                break;
            case WITHDRAWAL_AMOUNT_ENTERED:
                break;
            case WITHDRAWAL_TRANSACTION:
                printf("5. Return to Main Menu\n");
                printf("Select an option: ");
                break;
            case DEPOSIT_AMOUNT_ENTERED:
                break;
            case DEPOSIT_TRANSACTION:
                printf("5. Return to Main Menu\n");
                printf("Select an option: ");
                break;
        }

        scanf("%d", &input);
        currentState = processInput(currentState, input);
    }

    return 0;
}