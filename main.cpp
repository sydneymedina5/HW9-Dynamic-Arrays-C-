/* Author: Sydney Medina
Compiler: GCC set according to the CodeBlocks Notes
Date: 4/11/2018
Purpose of program: Your program will read from an input file that contains account records. Each account record starts with
a delimiter, which is the ‘#’ character, followed by the account number, followed by the number of
owners, followed by one or more owner records (there is one record for each owner), followed by the
number of transactions, followed by one or more transaction records (there is one record for each
transaction). An owner record consists of the owner’s name followed by the owner’s DOB in
mm/dd/yyyy format, followed the owner’s address. A transaction record consists of the transaction
date, followed by the transaction type (1 for account creation, 2 for deposit, and 3 for withdrawal),
followed by the amount. The various fields are separated by a white space, except for the owner’s name
and address, which are surrounded by a new line
*/

#include <iostream>
#include "Account.h"
#include "Date.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

/* This function takes as argument a string representing a date
in the mm/dd/yyyy format and returns the day as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getDay(string d)
{
    int day = 0;

    day = (d[3] - '0')*10;
    day += (d[4] - '0');

    return day;
} // end getDay()

/* This function takes as argument a string representing a date
in the mm/dd/yyyy format and returns the month as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getMonth(string d)
{
    int month = 0;

    month = (d[0] - '0')*10;
    month += (d[1] - '0');

    return month;
} // end getMonth()

/* This function takes as argument a string representing a date
in the mm/dd/yyyy format and returns the year as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getYear(string d)
{
    int year = 0;

    year = (d[6] - '0')*1000;
    year += (d[7] - '0')*100;
    year += (d[8] - '0')*10;
    year += (d[9] - '0');

    return year;
} // end getYear()

/* This function reads from a file to determine the number of accounts
It returns -1 if file open is unsuccessful, else it returns the number of
accounts
*/
int determineNumAccounts(string fname)
{
    ifstream in;
    string word;
    int c = 0;

    in.open(fname.c_str());

    if(!in)
        return -1;

    while(getline(in, word))
    {
        if(word == "#")
            c++;
    }

    in.close();

    return c;
} // end determineNumAccounts()

/* pass a string and create a date object and set month day and year then return object*/
Date* getDateObj(string date)
{
    Date *dateObj = new Date;
    int month = getMonth(date);
    int day = getDay(date);
    int year = getYear(date);

    dateObj->set(getMonth(date), getDay(date), getYear(date));
    return dateObj;
} // end getDateObj()

/* This function reads from an account file and populates an array of Account
objects (not an array of pointers to Account) with all the owners and
transactions data read from the file. The owner data is the owner’s name, DOB
and address. The transaction data is the transaction date, transaction type
(account creation, deposit, withdrawal), and transaction amount. For each
account, the function should dynamically allocate an array of Transaction of
size equal to the number of transactions, assign the array’s address to
transacPtr, and populate the array with the transaction data. In the array,
the transactions should be sorted by date (oldest first).
It takes as arguments the file name, the array and the size of the array.
It returns true if file open is successful, false otherwise. It should close
the file when done
*/
bool readAccounts(string fname, Account accntPtr [], int numAccnts)
{
    ifstream in;
    int accountNum = 0, numOwner = 0;
    string word;

    in.open(fname.c_str());

    if(!in)
        return false;

    getline(in, word);
    for(int i = 0; i < numAccnts; i++)
    {
        getline(in, word);
        accountNum = stoi(word);

        getline(in, word);
        numOwner = stoi(word);

        accntPtr[i].set(accountNum, numOwner);

        for(int j = 0; j < numOwner; j++)
        {
            Person *p = new Person;

            getline(in, word);
            p->name = word;

            getline(in, word);
            Date *DOB = getDateObj(word);
            p->DOB = *DOB;

            getline(in, word);
            p->address = word;

            accntPtr[i].setOwner(j, *p);
        }

        getline(in, word);

        string personO, personTw, personT;

        accntPtr[i].setNumTransactions(stoi(word));

        Transaction *arr = new Transaction[stoi(word)];

        getline(in, word);

        int counter = 0;

        while(word != "#")
        {
            if(word == "")
                break;

            Transaction *t = new Transaction;
            personO = word.substr(0, word.find(" "));
            word = word.substr(word.find(" ") + 1);
            personTw = word.substr(0, word.find(" "));
            personT = word.substr(word.find(" ") + 1);

            t->type = stoi(personTw);
            t->amount = stod(personT);
            t->transactionDate = *(getDateObj(personO));

            arr[counter] = *t;
            getline(in, word);
            accntPtr[i].setBalance(stod(personT), stoi(personTw));
            counter++;
        }

        accntPtr[i].setTransacPtr(arr);
    }
    return true;
} // end readAccounts()

/* display information given*/
void display(Account a)
{
    cout << endl;
    cout << "Account number: " << a.getAccountNumber() << endl;
    cout << "===============" << endl;
    for(int i = 0; i < a.getNumOwners(); i++)
    {
        cout << "Name: " << setw(10) << a.getOwner(i).name << ", DOB: ";
        Date date = a.getOwner(i).DOB;

        date.print();
        cout << ", Address: " << a.getOwner(i).address << endl;
    }
    double amount = 0;

    cout << endl << "Transaction History" << endl;
    for(int i = 0; i < a.getNumTransactions(); i++)
    {
        cout << endl << "Transaction #" << i + 1 << endl;
        cout << "Date: ";

        Transaction trans = a.getTransaction(i);
        trans.transactionDate.print();
        cout << ", type: ";
        int type = trans.type;
        switch(type)
        {
            case 1:
                amount = trans.amount;
                cout << "account creation";
                break;
            case 2:
                amount += trans.amount;
                cout << "deposit";
                break;
            default:
                amount -= trans.amount;
                cout << "withdrawal";
                break;
        }
        cout << ", amount: " << trans.amount << ", new balance: " << amount << endl;
    }
} // end display()

int main()
{
    string fname;
    int numAcc = 0;
    Account * accountPtr;

    cout << "Enter the account filename: ";
    getline(cin, fname);

    numAcc = determineNumAccounts(fname);
    cout << "There are " << numAcc << " accounts in the file" << endl;

    if(numAcc == -1)
    {
        cout << "Invalid filename." << endl;
        return -1;
    }

    accountPtr = new Account[numAcc];

    readAccounts(fname, accountPtr, numAcc);


    for(int i = 0; i < numAcc; i++)
    {
        display(accountPtr[i]);
    }
    return 0;
} // end main()
