#include "BankAccount.h"

int main()
{
    Bank bank;
    int choise;
    int num;
    std::string name, type;
    double balance, amount;
    bool state;
    while (true)
    {
        Menu();
        std::cin >> choise;

        if (choise == 1 || choise == 2 || choise == 3 || choise == 4 || choise == 5 || choise == 6)
        {
            switch (choise)
            {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> num;
                std::cout << "Enter account holder name: ";
                std::cin.ignore();
                getline(std::cin, name);
                std::cout << "Enter account type: ";
                getline(std::cin, type);
                std::cout << "Enter account balance: ";
                std::cin >> balance;
                bank.AddAccount(num, name, type, balance);
                break;
            case 2:
                std::cout << "please enter Account Number for Deposit Operation: ";
                std::cin >> num;
                std::cout << "please enter amount: " << std::endl;
                std::cin >> amount;
                bank.Search(num, amount, choise);
                break;
            case 3:
                std::cout << "please enter Account Number for Withdrow Operation: ";
                std::cin >> num;
                std::cout << "please enter amount: " << std::endl;
                std::cin >> amount;
                bank.Search(num, amount, choise);
                break;

            case 4:
                std::cout << "Total Balance = " << bank.Get_Total_Balance() << std::endl;
                break;
            case 5:
                bank.DisplayAccounts();
                break;
            case 6:
                exit(0);

            default:
                std::cout << "please enter correct choise...!" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "----------------------------------\n";
            std::cout << "please enter correct choise..!\n";
        }
    }
}
