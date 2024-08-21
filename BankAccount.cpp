#include "BankAccount.h"

Account::Account(unsigned long num, std::string name, std::string type, double bal )
{
    Account_Number = num;
    Holder_Name = name;
    Account_Type = type;
    Balance = bal;
}
void Account::Deposit(double amount)
{
    if (amount > 0)
    {
        Balance += amount;
    }
}
void Account::withdraw(double amount)
{
    if (amount > 0 && amount <= Balance)
    {
        Balance -= amount;
    }
    else
    {
        std::cout << "Balance Not Enough....!\n";
        std::cout << "the withdrawal process has not been completed...!\n";
    }
}

unsigned long Account::Get_Account_Number() const { return Account_Number; }
std::string Account::Get_Account_Holder() const { return Holder_Name; }
std::string Account::Get_Account_Type() const { return Account_Type; }
double Account::Get_Account_Balance() const { return Balance; }

void Account::DisplayAccountInfo(void)
{
    std::cout << "Account Number: " << Account_Number << std::endl;
    std::cout << "Account Holder: " << Holder_Name << std::endl;
    std::cout << "Account Type: " << Account_Type << std::endl;
    std::cout << "Balance: $" << Balance << std::endl;
    std::cout << "------------------------------" << std::endl;
}


    // Add a new BankAccount to the collectio
    void Bank::AddAccount(int id, std::string name, std::string type, double bal)
    {
        bool state = true;
        Account temp(id, name, type, bal);
        // check if this account exist or not
        for (auto &acc : accounts)
        {
            if (acc.Get_Account_Number() == temp.Get_Account_Number())
            {
                state = false;
                std::cout << "-------------------------------------\n";
                std::cout << "Account Number Already Exist....!\n";
            }
        }
        if (state)
        {
            accounts.push_back(temp);
        }
    }
    // Get the total balance of all accounts
    double Bank::Get_Total_Balance() const
    {
        double total_balance = 0.0;

        for (auto acc : accounts)
        {
            total_balance += acc.Get_Account_Balance();
        }
        return total_balance;
    }
    // search function for deposite and withdrow operations
    void Bank::Search(unsigned int num, double amount, int choise)
    {
        bool flag = false;
        /* reference in this line is very important */
        for (auto &acc : accounts)
        {
            if (acc.Get_Account_Number() == num)
            {
                flag = true;
                if (choise == 2)
                {
                    acc.Deposit(amount);
                }
                else if (choise == 3)
                {
                    acc.withdraw(amount);
                }
                break;
            }
        }
        if (!flag)
        {
            std::cout << "Account Number Not Exist...!\n";
        }
    }
    // Display all account information
    void Bank::DisplayAccounts(void) const
    {
        if (accounts.empty())
        {
            std::cout << "no accounts in the bank\n";
        }
        else
        {
            for (auto acc : accounts)
            {
                acc.DisplayAccountInfo();
            }
        }
    }


void Menu(void)
{
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Create an Account \n"
              << "2. Deposit funds \n"
              << "3. Withdraw funds \n"
              << "4. Total Balance \n"
              << "5. Display all accounts\n"
              << "6. Exit\n";
    std::cout << "please enter your choise :";
}