#pragma once
#include <vector>
#include "account.h"

class accountManager {
public:
	int accountTracker = 0;
	std::vector<std::shared_ptr<account>> myClients{};
	int createAccount()
	{
		std::shared_ptr<account> newAccount = std::make_shared<account>(account(++accountTracker));	
		myClients.push_back(newAccount);
		return(newAccount->accountNumber);
	}
	bool checkAccount(int accountNumber)
	{
		for (auto accountEntry : myClients)
		{
			if (accountNumber == accountEntry->accountNumber)
			{
				return true;
			}
		}
		return false;
	}
	std::shared_ptr<account> getAccount(int accountNumber)
	{
		for (auto myAccount : myClients)
		{
			if (accountNumber == myAccount->accountNumber)
			{
				return myAccount;
			}
		}

		return nullptr;
	}


};