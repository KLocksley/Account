#pragma once
class account {
private:
    int balance = 0;
public:
    const int accountNumber;


    account(int newAccountNumber) : accountNumber(newAccountNumber), balance(0)
    {
    }

    int getBalance()
    {
        return balance;
    }


    bool deposit(int amount)
    {
        balance += amount;
        return true;
    }
    bool withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

};