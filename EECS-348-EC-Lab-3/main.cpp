"""
ASSIGNMENT_NAME: EECS 347 Extra Credit Lab 3
FUNCTION: Manages bank accounts
INPUTS: NONE
OUTPUTS: Various operations performed on bank accounts
AUTHOR_NAME: Michael Stang
COLLABORATORS: None
CREATION_DATE: 11/26/23
"""

#include <iostream>
#include <string>

using namespace std;

class Account {
    /* Base Class of Account */
    protected:
        string account_number;
        string account_holder_name;
        float balance;
    
    public:
        // Initlizises the class 
        Account(string account_number, string account_holder_name, float balance) : account_number(account_number), account_holder_name(account_holder_name), balance(balance) {}

        void displayDetails() {
            /* Outputs details of the account to console */
            cout << "Account Details for Account (ID: " << account_number << "):\n" << "Holder: " << account_holder_name << "\nBalance: $" << balance << "\n\n";
        }

        void deposit(float amount) {
            /* Adds money to account */
            balance = balance + amount;
        }

        int withdraw(float amount) {
            /* Removes money from account */
            if (balance >= amount) {
                balance = balance - amount;
                return 1;
            } else {
                cout << "Not enough money to withdraw.\n\n";
                return 0;
            }
        }

        Account operator+ (Account& other) {  // overloads +
            double transfer_amount = 300;  // the amount that + moves

            int success = other.withdraw(transfer_amount);
            if (success == 1) {
                deposit(transfer_amount);
            }
            return other;
        }

    friend ostream& operator<<(ostream& os, const Account& acc) {  // overloads << 
        os << "Account Details for Account (ID: " << acc.account_number << "):\n" << "Holder: " << acc.account_holder_name << "\nBalance: $" << acc.balance << "\n\n";
        return os;
    }
};


class SavingsAccount : public Account {
    double interest_rate;
    double minimum_balance = 100;  // Default minimum balacne for a savings account, this is NOT passed in

    public:
        // Initilizses the class
        SavingsAccount(string account_number, string account_holder_name, float balance, double interest_rate) : Account(account_number, account_holder_name, balance), interest_rate(interest_rate) {}
        void displayDetails() {
            /* Outputs details of the account to console */
            cout << "Account Details for Savings Account (ID: " << account_number << "):\n" << "Holder: " << account_holder_name << "\nBalance: $" << balance << "\nInterest Rate: " << interest_rate * 100 << "%\n\n";
        }

        int withdraw(float amount) {
            /* Removes money from account */
            if ((balance - amount) >= minimum_balance) { // Checks if the remaining balance is equal to or over the minimum balance requirement
                balance = balance - amount;
                return 1;
            } else {
                cout << "Not enough money to withdraw and maintain account minimum.\n\n";
                return 0;
            }
        }

    friend ostream& operator<<(ostream& os, const SavingsAccount& acc) { // overloads << 
        os << "Account Details for Savings Account (ID: " << acc.account_number << "):\n" << "Holder: " << acc.account_holder_name << "\nBalance: $" << acc.balance << "\nInterest Rate: " << acc.interest_rate * 100 << "%\n\n";
        return os;
    }
};

class CurrentAccount : public Account {
    double overdraft_limit;

    public:
        // Initilizses the class
        CurrentAccount(string account_number, string account_holder_name, float balance, float overdraft_limit) : Account(account_number, account_holder_name, balance), overdraft_limit(overdraft_limit) {}
        void displayDetails() {
            /* Outputs details of the account to console */
            cout << "Account Details for Current Account (ID: " << account_number << "):\n" << "Holder: " << account_holder_name << "\nBalance: $" << balance << "\nOverdraft Limit: $" << overdraft_limit << "\n\n";
        }

        int withdraw(float amount) {
            /* Removes money from account */
            if ((balance - amount) >= (-1 * overdraft_limit)) { // Checks if the remaining balance is equal to or over the minimum balance requirement
                balance = balance - amount;
                return 1;
            } else {
                cout << "Not enough money to withdraw without going over overdraft limit.\n\n";
                return 0;
            }
        }

        friend ostream& operator<<(ostream& os, const CurrentAccount& acc) {  // overloads << 
            os << "Account Details for Current Account (ID: " << acc.account_number << "):\n" << "Holder: " << acc.account_holder_name << "\nBalance: $" << acc.balance << "\nOverdraft Limit: $" << acc.overdraft_limit << "\n\n";
            return os;
    }
};

int main() {
    /* Runs the program according to instructions */

    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "John Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    cout << "Account Details after deposit and withdrawal: \n";
    savings.displayDetails();
    current.displayDetails();

    //Transfer 300 from savings to current

    current + savings;

    cout << "Account Details after transfer: \n";
    cout << savings;
    cout << current;

    return 0;
}

