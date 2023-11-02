#include <iostream>
#include <vector>
#include <string>

#include "account.h"
#include "accountManager.h"

//Doesn't return the balance value at the end of the while loop to the list I think, sets it back to zero when run through the program again.

void useAccount(std::shared_ptr<account> myAccount)
{
    bool usingAccount = true;
    std::string operand;

    while (usingAccount)
    {
        std::cout << "What do you want to do? You can either deposit, withdraw or get a statement. \n";
        std::cin >> operand;
        if (operand == "withdraw")
        {
            int amount;
            std::cout << "How much do you want to take out? \n";
            std::cin >> amount;
            bool withdrawSuccessful = myAccount->withdraw(amount);
            if (withdrawSuccessful)
            {
                const int balance = myAccount->getBalance();
                std::cout << "Your new balance is " << balance << "\n";
            }
            else
            {
                std::cout << "You don't have enough funds \n";
            }
        }
        else if (operand == "deposit")
        {
            int amount;
            std::cout << "How much do you want to deposit? \n";
            std::cin >> amount;
            myAccount->deposit(amount);
            const int balance = myAccount->getBalance();
            std::cout << "Your new balance is " << balance << "\n";
        }
        else if (operand == "statement")
        {
            const int balance = myAccount->getBalance();
            std::cout << "Your balance is " << balance << "\n";
        }
        std::string Continue;
        std::cout << "Do you want to do anything else, yes or no? \n";
        std::cin >> Continue;
        if (Continue == "yes")
        {
            usingAccount = true;
        }
        else
        {
            usingAccount = false;
        }
    }
}

int main()
{
    int accountNumber;
    std::string createAccount;
    accountManager manager{};
    std::string ownAccount;

    std::shared_ptr<account> myAccount = nullptr;
    bool active = true;

    while (active)
    {
        std::cout << "Do you have an account? yes or no \n";
        std::cin >> ownAccount;
        if (ownAccount == "no")
        {
            std::cout << "Do you want to create an account? \n";
            std::cin >> createAccount;
            if (createAccount == "yes")
            {
                accountNumber = manager.createAccount();
                std::cout << accountNumber << "\n";
                bool checkAccount = manager.checkAccount(accountNumber);
                if (checkAccount)
                {
                    myAccount = manager.getAccount(accountNumber);

                    if (myAccount != nullptr)
                    {
                        useAccount(myAccount);
                    }
                }
            }
        }
        else if (ownAccount == "yes")
        {
            std::cout << "Enter your account number to access your account: \n";
            std::cin >> accountNumber;
            bool checkAccount = manager.checkAccount(accountNumber);
            if (checkAccount)
            {
                std::cout << "Well done!";
                myAccount = manager.getAccount(accountNumber);

                if (myAccount != nullptr)
                {
                    useAccount(myAccount);
                }

            }
        }
        std::string startAgain;
        std::cout << "Do you wish to go back to the start? yes or no \n";
        std::cin >> startAgain;
        if (startAgain == "no")
        {
            active = false;
        }
    }
}


