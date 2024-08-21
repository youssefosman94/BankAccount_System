#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

void Menu(void);

class Account
{
private:
    unsigned long Account_Number;
    std::string Holder_Name;
    std::string Account_Type;
    double Balance;

public:
    Account(unsigned long num, std::string name, std::string type, double bal = 0.0);
    void Deposit(double amount);
    void withdraw(double amount);

    unsigned long Get_Account_Number() const;
    std::string Get_Account_Holder() const;
    std::string Get_Account_Type() const;
    double Get_Account_Balance() const;

    void DisplayAccountInfo(void);
};
class Bank
{
private:
    std::vector<Account> accounts;

public:
    // Add a new BankAccount to the collectio
    void AddAccount(int id, std::string name, std::string type, double bal);

    // Get the total balance of all accounts
    double Get_Total_Balance() const;

    // search function for deposite and withdrow operations
    void Search(unsigned int num, double amount, int choise);

    // Display all account information
    void DisplayAccounts(void) const;
};

#endif