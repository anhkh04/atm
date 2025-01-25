#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Bank;

class Account 
{
private:
    string name;
    int balance;
    string creation_date;
    int password;

public:
    string get_name()
    {
        return this->name;
    }

    int get_balance()
    {
        return this->balance;
    }
    string get_creation_date()
    {
        return this->creation_date;
    }

    friend Bank;
};

class Bank
{
private:
    vector<Account> accounts;

public:
    void add_account(string &name, int &balance, int password)
    {
        Account new_account;
        new_account.name = name;
        new_account.balance = balance;
        new_account.password = password;
        this->accounts.push_back(new_account);
        cout << "You have successfully add a new bank account!" << endl;
        return;
    }
    
    string get_creation_date()
    {
        time_t now = time(0);
        tm *current = localtime(&now);
        string year = to_string(current->tm_year + 1900);
        string month = to_string(current->tm_mon + 1);
        string day = to_string(current->tm_mday);

        return day + "/" + month + "/" + year;
    }

    void get_account(string &name)
    {
        int index = -1;
        for(int i=0; i < accounts.size(); i++)
        {
            if(accounts[i].name == name)
            {
                index = i;
                break;
            }
        }

        if(index != -1)
        {
            cout << "Name: " << accounts[index].get_name() << ", ";
            cout << "Balance: " << accounts[index].get_balance() << ", ";
            cout << "Date: " << get_creation_date() << endl;
            return;
        }
        cout << "Account not found!" << endl;
    }

    void deposit(string &name)
    {
        int index = -1;
        for(int i=0; i < accounts.size(); i++)
        {
            if(accounts[i].name == name)
            {
                index = i;
                break;
            }
        }

        int amount, password;
        if(index != -1)
        {
            for(int i=0; i<3; i++)
            {
                cout << "Password: ";
                cin >> password;
                if(password == accounts[index].password)
                {
                    break;
                }
                else if(i == 1)
                {
                    cout << "Last chance!" << endl;
                }
            }
            if(accounts[index].password == password)
            {
                cout << "Enter the money you want to deposit: ";
                cin >> amount;
                accounts[index].balance += amount;
                cout << "You have successfully deposit " << amount << endl;
            }
            else
            {
                cout << "You entered the wrong password 3 times (>.<)" << endl;
            }

        }
        else
        {
            cout << "Account not found!" << endl;
        }
        return;
        
    }

    void withdraw(string &name)
    {
        int index = -1;
        for(int i=0; i < accounts.size(); i++)
        {
            if(accounts[i].name == name)
            {
                index = i;
                break;
            }
        }

        int amount, password;
        if(index != -1)
        {
            for(int i=0; i<3; i++)
            {
                cout << "Password: ";
                cin >> password;
                if(password == accounts[index].password)
                {
                    break;
                }
                else if(i == 1)
                {
                    cout << "Last chance!" << endl;
                }
            }
            if(accounts[index].password == password)
            {
                cout << "Enter the money you want to withdraw: ";
                cin >> amount;
                if(amount <= accounts[index].balance)
                {
                    accounts[index].balance -= amount;
                    cout << "You have successfully withdraw " << amount << endl;
                }
                else
                {
                    cout << "You don't have enough money to withdraw!" << endl; 
                }
            }
            else
            {
                cout << "You entered the wrong password 3 times (>.<)" << endl;
            }

        }
        else
        {
            cout << "Account not found!" << endl;
        }
        return;
    }
};

void show_menu();
int access_feature(Bank &account);

/* MAIN*/
int main()
{
    Bank tk1;
    show_menu();
    while(true)
    {
        if(access_feature(tk1))
        {
            return 0;
        }
    }
}

void show_menu()
{
    cout << "=======  MENU  =======" << endl;
    cout << " 1.  Add new account" << endl;
    cout << " 2.  Get account's information" << endl;
    cout << " 3.  Withdraw" << endl;
    cout << " 4.  Deposit" << endl;
    cout << " #.  Exit" << endl; 
}

int access_feature(Bank &account)
{
    string name;
    int amount, password, choice;
    cout << endl << "Your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            cout << "Enter account's name: ";
            cin >> name;
            cout << "Enter default balance: ";
            cin >> amount;
            cout << "Create your password: ";
            cin >> password;
            account.add_account(name, amount, password);
            return 0;
        }
        case 2:
        {
            cout << "Enter account's name you want to check: ";
            cin >> name;
            account.get_account(name);
            return 0;
        }
        case 3:
        {
            cout << "Enter acount's name you want to withdraw: ";
            cin >> name;
            account.withdraw(name);
            return 0;
        }
        case 4:
        {
            cout << "Enter account's name you want to deposit: ";
            cin >> name;
            account.deposit(name);
            return 0;
        }
        default:
        {
            cout << "Do you want to exit?(1:Y/0:N) : ";
            cin >> amount;
            if(amount)
            {
                return 1;
            }
            return 0;
        }
    }
}
