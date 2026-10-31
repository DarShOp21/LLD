#include <iostream>
#include <vector>

using namespace std;

class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;

    virtual ~DepositOnlyAccount() {}
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;

    virtual ~WithdrawableAccount() {}
};

class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited : $" << amount
             << " | Savings Account"
             << " | Balance : $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;

            cout << "Withdrawn : $" << amount
                 << " | Savings Account"
                 << " | Balance : $" << balance << endl;
        } else {
            cout << "Withdrawal failed : Insufficient funds!"
                 << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
private:
    double balance;

public:
    CurrentAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited : $" << amount
             << " | Current Account"
             << " | Balance : $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;

            cout << "Withdrawn : $" << amount
                 << " | Current Account"
                 << " | Balance : $" << balance << endl;
        } else {
            cout << "Withdrawal failed : Insufficient funds!"
                 << endl;
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;

        cout << "Deposited : $" << amount
             << " | Fixed Term Account"
             << " | Balance : $" << balance << endl;
    }
};

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient(
        vector<WithdrawableAccount*> withdrawableAccounts,
        vector<DepositOnlyAccount*> depositOnlyAccounts
    ) {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {

        cout << "\n========================================\n";
        cout << "      WITHDRAWABLE ACCOUNTS\n";
        cout << "========================================\n";

        for (WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500);

            cout << endl;
        }

        cout << "\n========================================\n";
        cout << "       DEPOSIT-ONLY ACCOUNTS\n";
        cout << "========================================\n";

        for (DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);

            cout << endl;
        }
    }
};

int main() {

    cout << "========================================\n";
    cout << "          BANK ACCOUNT SYSTEM\n";
    cout << "========================================\n";

    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

    int savingsCount;
    int currentCount;
    int fixedCount;

    cout << "\nEnter number of Savings Accounts: ";
    cin >> savingsCount;

    cout << "Enter number of Current Accounts: ";
    cin >> currentCount;

    cout << "Enter number of Fixed Term Accounts: ";
    cin >> fixedCount;

    // Create Savings Accounts
    for (int i = 0; i < savingsCount; i++) {
        withdrawableAccounts.push_back(new SavingAccount());
    }

    // Create Current Accounts
    for (int i = 0; i < currentCount; i++) {
        withdrawableAccounts.push_back(new CurrentAccount());
    }

    // Create Fixed Term Accounts
    for (int i = 0; i < fixedCount; i++) {
        depositOnlyAccounts.push_back(new FixedTermAccount());
    }

    BankClient* client = new BankClient(
        withdrawableAccounts,
        depositOnlyAccounts
    );

    client->processTransactions();

    // Free memory
    delete client;

    for (WithdrawableAccount* account : withdrawableAccounts) {
        delete account;
    }

    for (DepositOnlyAccount* account : depositOnlyAccounts) {
        delete account;
    }

    withdrawableAccounts.clear();
    depositOnlyAccounts.clear();

    cout << "========================================\n";
    cout << "       TRANSACTIONS COMPLETED\n";
    cout << "========================================\n";

    return 0;
}
