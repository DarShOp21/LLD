#include <iostream>
#include <vector>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    virtual ~Account() {}
};

class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited: $" << amount
             << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;

            cout << "Withdrawn: $" << amount
                 << " | New Balance: $" << balance << endl;
        } else {
            cout << "Withdrawal failed: Insufficient funds!" << endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;

public:
    CurrentAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited: $" << amount
             << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;

            cout << "Withdrawn: $" << amount
                 << " | New Balance: $" << balance << endl;
        } else {
            cout << "Withdrawal failed: Insufficient funds!" << endl;
        }
    }
};

class FixedTermAccount : public Account {
private:
    double balance;

public:
    FixedTermAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited: $" << amount
             << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed in Fixed Term Account!" << endl;
    }
};

class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts) {
        this->accounts = accounts;
    }

    void processTransactions() {

        cout << "\n========================================\n";
        cout << "       PROCESSING TRANSACTIONS\n";
        cout << "========================================\n";

        int accountNumber = 1;

        for (Account* acc : accounts) {

            cout << "\nAccount " << accountNumber << endl;
            cout << "----------------------------------------\n";

            acc->deposit(1000);
            acc->withdraw(500);

            accountNumber++;
        }

        cout << "\n========================================\n";
        cout << "       TRANSACTIONS COMPLETED\n";
        cout << "========================================\n";
    }
};

int main() {

    cout << "========================================\n";
    cout << "          BANK ACCOUNT SYSTEM\n";
    cout << "========================================\n";

    vector<Account*> accounts;

    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice;

        cout << "\nSelect Account Type\n";
        cout << "1. Savings Account\n";
        cout << "2. Current Account\n";
        cout << "3. Fixed Term Account\n";
        cout << "Enter choice: ";

        cin >> choice;

        Account* account = nullptr;

        switch (choice) {

            case 1:
                account = new SavingAccount();
                break;

            case 2:
                account = new CurrentAccount();
                break;

            case 3:
                account = new FixedTermAccount();
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                i--;
                continue;
        }

        accounts.push_back(account);
    }

    BankClient* client = new BankClient(accounts);

    client->processTransactions();

    // Free memory
    delete client;

    for (Account* account : accounts) {
        delete account;
    }

    accounts.clear();

    cout << "\nProgram terminated successfully.\n";

    return 0;
}
