#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Date.h"
#include <string>

struct Transaction
{
    Date transactionDate;
    int type;
    double amount;
}; // end struct Transaction

struct Person
{
    std::string name;
    Date DOB;
    std::string address;
}; // end struct Person

class Account
{
    public:
        Account();
        virtual ~Account();
        void set(int accountNumber, int numOwners);
        void setTransacPtr(Transaction * transacPtr_);
        int getNumTransactions() const;
        void setNumTransactions(int numTransactions_);
        Transaction getTransaction(int ind) const;
        void setOwner(int ind, Person p);
        Person getOwner(int ind) const;
        int getAccountNumber() const;
        double getBalance() const;
        void setBalance(double, int);
        int getNumOwners() const;

        private:
        int accountNumber;
        int numOwners;
        Person * ownerPtr;
        double balance;
        int numTransactions; // Number of transactions for the account
        Transaction * transacPtr; // Pointer to an array that holds the Transactions

    protected:
};

/* default constructor*/
Account::Account()
{
} // end Account::Account()

/* destructor which releases the array of Person dynamically created in the
constructor*/
Account::~Account()
{
    delete [] ownerPtr;
    delete [] transacPtr;
} // end ~Account::account()

/* This function sets numTransactions_ to numTransactions and creates a
transaction array */
void Account::setNumTransactions(int numTransactions_)
{
    numTransactions = numTransactions_;
    transacPtr = new Transaction[numTransactions_];
} // end Account::setNumTransactions()

/* This function sets transactionPtr_ to transactionPtr*/
void Account::setTransacPtr(Transaction * transacPtr_)
{
    transacPtr = transacPtr_;
} // end Account::setTransacPtr()

/* This function sets the arguments accountNumber_ and numOwners_ to
accountNumber and numOwners while also creating a person array */
void Account::set(int accountNumber_, int numOwners_)
{
    accountNumber = accountNumber_;
    numOwners = numOwners_;
    ownerPtr = new Person[numOwners_];
} // end Account::set()

/* This function takes in amount and type of transaction then
goes through a switch statement and sets balance equal to
amount */
void Account::setBalance(double amount, int type)
{
    switch(type)
    {
        case 1:
            balance == amount;
            break;
        case 2:
            balance += amount;
            break;
        default:
            balance -= amount;
            break;
    }

    balance+=amount;
} // Account::setBalance()

/* A mutator function that assigns Person p to the
co-owner at index ind of the ownerPtr array*/
void Account::setOwner(int ind, Person p)
{
    ownerPtr[ind] = p;
} // end Account::setOwner(int ind, Person p)

/* An accessor that returns the owner at index ind of the ownerPtr
array. Return type is Person. This function is later called by the displayAccountInfo()
function.*/
Person Account::getOwner(int ind) const
{
   return ownerPtr[ind];
} //  end Account::getOwner(int ind)

/* An accessor function that returns the account number. This function
is later called by the displayAccountInfo() function.*/
int Account::getAccountNumber() const
{
    return accountNumber;
} // end Account::getAccountNumber()

/*An accessor function that returns the account balance. This function is
later called by the displayAccountInfo() function.*/
double Account::getBalance() const
{
    return balance;
} // end Account::getBalance()

/* An accessor function that returns numOwners. This function is later
called by the displayAccountInfo() function.*/
int Account::getNumOwners()const
{
    return numOwners;
} // end Account::getNumOwners()

/*An accessor function that returns numTransactions*/
int Account::getNumTransactions() const
{
    return numTransactions;
} // end Account::getNumTransactions()

/*An accessor function that returns getTransaction*/
Transaction Account::getTransaction(int ind) const
{
    return transacPtr[ind];
} // end Account::getTransaction()
#endif // ACCOUNT_H
