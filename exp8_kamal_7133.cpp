#include <iostream>
#include <map>

using namespace std;

class BankAccount {
private:
    static int totalTrans;
    static map<int, BankAccount*> accountsMap;

public:
    int accountNum;
    double bal;

    BankAccount(int accNum, double balance) : accountNum(accNum), bal(balance) {}

    // Deposit money into the account
    void deposit(double amt) {
        bal += amt;
        totalTrans++;
        cout << "Deposit of $" << amt << " successful.\n";
    }

    // Withdraw money from the account
    void withdraw(double amt) {
        if (bal >= amt) {
            bal -= amt;
            totalTrans++;
            cout << "Withdrawal of $" << amt << " successful.\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    // Add account to the map
    static void addAcc(int accNum, BankAccount* accPtr) {
        accountsMap[accNum] = accPtr;
    }

    // Get account from the map
    static BankAccount* getAcc(int accNum) {
        return accountsMap[accNum];
    }

    // Get total transactions
    static int getTotalTrans() {
        return totalTrans;
    }
};

int BankAccount::totalTrans = 0;
map<int, BankAccount*> BankAccount::accountsMap;

int main() {
    double depAmt;
    int numAccs;

    cout << "Enter the number of accounts to create: ";
    cin >> numAccs;

    int i = 0;
    while (i < numAccs) {
        int accNum;
        double initBal;

        cout << "Enter account number for account " << i + 1 << ": ";
        cin >> accNum;

        cout << "Enter initial balance for account " << i + 1 << ": ";
        cin >> initBal;

        BankAccount* newAcc = new BankAccount(accNum, initBal);
        BankAccount::addAcc(accNum, newAcc);

        cout << "Account created successfully.\n";
        i++;
    }

    int numTrans;
    cout << "Enter the number of transactions to perform: ";
    cin >> numTrans;

    int j = 0;
    while (j < numTrans) {
        int accNum;
        char transType;
        double amt;

        cout << "Enter account number: ";
        cin >> accNum;

        BankAccount* accPtr = BankAccount::getAcc(accNum);
        if (accPtr == nullptr) {
            cout << "Account not found.\n";
            continue;
        }

        cout << "Enter 'D' for deposit or 'W' for withdrawal: ";
        cin >> transType;

        if (transType == 'D' || transType == 'd') {
            cout << "Enter deposit amount: ";
            cin >> amt;
            accPtr->deposit(amt);
        } else if (transType == 'W' || transType == 'w') {
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            accPtr->withdraw(amt);
        } else {
            cout << "Invalid transaction type.\n";
        }
        j++;
    }

    cout << "Total transactions: " << BankAccount::getTotalTrans() << endl;

    return 0;
}
