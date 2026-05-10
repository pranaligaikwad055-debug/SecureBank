#include <stdio.h>
#include <string.h>

struct Account
{
    int accNo;
    char name[50];
    char password[20];
    float balance;
};

struct Account users[100];
int totalAccounts = 0;

int loggedInIndex = -1;

// Create Account
void createAccount()
{
    printf("\n===== CREATE ACCOUNT =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &users[totalAccounts].accNo);

    printf("Enter Name: ");
    scanf("%s", users[totalAccounts].name);

    printf("Create Password: ");
    scanf("%s", users[totalAccounts].password);

    printf("Enter Initial Balance: ");
    scanf("%f", &users[totalAccounts].balance);

    totalAccounts++;

    printf("Account Created Successfully!\n");
}
// Login
void login()
{
    int acc;
    char pass[20];
    int found = 0;

    printf("\n===== LOGIN =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Password: ");
    scanf("%s", pass);

    for(int i = 0; i < totalAccounts; i++)
    {
        if(users[i].accNo == acc &&
           strcmp(users[i].password, pass) == 0)
        {
            loggedInIndex = i;
            found = 1;
            break;
        }
    }

    if(found)
    {
        printf("Login Successful!\n");
    }
    else
    {
        printf("Invalid Account Number or Password!\n");
    }
}

// Check Balance
void checkBalance()
{
    if(loggedInIndex == -1)
    {
        printf("Please Login First!\n");
        return;
    }

    printf("\nCurrent Balance = %.2f\n",
           users[loggedInIndex].balance);
}

// Transfer Money
void transferMoney()
{
    if(loggedInIndex == -1)
    {
        printf("Please Login First!\n");
        return;
    }

    int receiverAcc;
    float amount;
    int receiverIndex = -1;

    printf("\n===== TRANSFER MONEY =====\n");

    printf("Enter Receiver Account Number: ");
    scanf("%d", &receiverAcc);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    for(int i = 0; i < totalAccounts; i++)
    {
        if(users[i].accNo == receiverAcc)
        {
            receiverIndex = i;
            break;
        }
    }

    if(receiverIndex == -1)
    {
        printf("Receiver Account Not Found!\n");
        return;
    }

    if(users[loggedInIndex].balance < amount)
    {
        printf("Insufficient Balance!\n");
        return;
    }

    users[loggedInIndex].balance -= amount;
    users[receiverIndex].balance += amount;

    printf("Money Transferred Successfully!\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");

        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Check Balance\n");
        printf("4. Transfer Money\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                checkBalance();
                break;

            case 4:
                transferMoney();
                break;

            case 5:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}