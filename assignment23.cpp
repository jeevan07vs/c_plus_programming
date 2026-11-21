#include <iostream>
#include <stdexcept>
#include <string>

// Custom Exception Class
class InsufficientFunds : public std::runtime_error {public:
    InsufficientFunds(double balance, double amount)
        : std::runtime_error("Insufficient funds: tried to withdraw $" + 
          std::to_string(amount) + " with balance $" + std::to_string(balance)) {}
};
class BankAccount {private:
    double balance;
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Updated withdraw method: returns void and throws an exception on failure
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds(balance, amount);
        }
        balance -= amount;
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
    }
};
int main() {
    BankAccount account(100.0);

    try {
        account.withdraw(40.0);  // Succeeds
        account.withdraw(80.0);  // Throws InsufficientFunds
    } 
    catch (const InsufficientFunds& e) {
        std::cerr << "Transaction Failed -> " << e.what() << "\n";
    }

    return 0;
}
