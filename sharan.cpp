#include <iostream>
#include <ctime>
#include <cstdlib>

class BankAccount {
private:
    std::string account_holder;
    double balance;
    long long account_number;

public:
    BankAccount(const std::string& holder, double initial_balance) {
        account_holder = holder;
        balance = initial_balance;
        // Generate a random 10-digit account number
        account_number = rand() % 9000000000 + 1000000000;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << ". Successfully" << std::endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ". Successfully" << std::endl;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    void getBalance() const {
        std::cout << "Account balance for " << account_holder << ": $" << balance << std::endl;
    }

    void getAccountInfo() const {
        std::cout << "Account Holder: " << account_holder << "\nAccount Number: " << account_number
                  << "\nBalance: $" << balance << std::endl;
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    // Get user input
    std::string account_holder;
    double initial_balance;
    int op;
	double withdraw,deposit;

    std::cout << "Enter account holder's name: ";
    std::getline(std::cin, account_holder);

    std::cout << "Enter initial balance: $";
    std::cin >> initial_balance;

    // Create a bank account
    BankAccount user_account(account_holder, initial_balance);

    // Display account information
    std::cout << "\nAccount created successfully!\n";
    user_account.getAccountInfo();
    std::cout<<"\nPress '1' to Deposit\nPress '2' to Withdraw\nPress '3' to Check Balance\nPress '4' to Exit Banking"<<std::endl;
	while(initial_balance!=0){
		std::cout<<"\nEnter the Operation You Want to Perform: ";
		std::cin>>op;
		if(op==1){
			std::cout<<"\nEnter the Amount You Want to Deposit: ";
			std::cin>>deposit;
			user_account.deposit(deposit);
			user_account.getBalance();
		}
		else if(op==2){
			std::cout<<"\nEnter the Amount You Want to Withdraw: ";
			std::cin>>withdraw;
			user_account.withdraw(withdraw);
			user_account.getBalance();
		}
		else if(op==3){
			user_account.getBalance();
		}
		else if(op==4){
			std::cout<<"\nThanks For Banking with us!";
			break;
		}
		else{
			std::cout<<"\nEnter a valid Operation!"<<std::endl;
		}
	}

    return 0;
}