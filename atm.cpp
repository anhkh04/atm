#include <iostream>
#include <string>
using namespace std;

class ATM
{
public:
    virtual void withdraw(int amount) = 0;
    virtual void deposit(int amount) = 0;
    virtual void check_balance() = 0;
};

class atm_function : public ATM
{
private: 
    int balance = 0;

public:
    atm_function() {};

    atm_function(int amount)
    {
        balance = amount;
    }

    void withdraw(int amount)
    {
        if(amount <= balance && balance > 0) 
        {
            cout << " You have successfully deposited money !" << endl;
            balance -= amount;
            return;
        }
        cout << "Not enough money in your bank account !" << endl; 
    }

    void deposit(int amount)
    {
        if(amount > 0)
        {
            balance += amount;
            cout << "You have successfully withdran the money !" << endl; 
        }
    }

    void check_balance()
    {
        if(this->balance <= 0)
        {
            cout << "You have no money in your bank account yet !" << endl;
            return;
        }
        cout << "Your bank account balance: " << this->balance << endl;
    }
};

int user_input();
void menu();
int check_input(atm_function &user1);

int main()
{
    atm_function user;
    menu();
    while(true)
    {
        if(check_input(user))
        {
            break;
        }
    }
    return 0;
}

int user_input()
{
    int choice;
    cin >> choice;
    return choice;
}

void menu()
{
    cout << "=======  MENU  =======" << endl;
    cout << " 1.  Check account balance" << endl;
    cout << " 2.  Deposit" << endl;
    cout << " 3.  Withdraw" << endl;
    cout << " 4.  Exit" << endl;
}

int check_input(atm_function &user1)
{
    cout << "Your choice: ";
    switch(user_input())
    {
        case 1:
        {
            user1.check_balance();
            return 0;
        }
        case 2:
        {
            cout << "Enter the amount you want to deposit: ";
            user1.deposit(user_input());
            return 0;
        }
        case 3:
        {
            cout << "Enter the amount you want to withdraw: ";
            user1.withdraw(user_input());
            return 0;
        }
        default:
        {
            cout << "Do you want to exit ? (1:Y/0:N): ";
            if(user_input())
            {
                return 1;
            }
            return 0;
        }
    }
}