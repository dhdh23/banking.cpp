#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

class BankManagement
{ 
private:
    int accno;
    string name, address;
    string actype;
    float amount;
    float loanAmount;

public:
    BankManagement()
    {
        accno = 0;
        name = "";
        address = "";
        actype = "";
        amount = 0.0;
        loanAmount = 0.0;
    }

    bool checkAvailability();
    bool searchAccount(int);
    void newAccount();
    void deposit();
    void withdraw();
    void checkAccount();
    void modifyAccount();
    void deleteAccount();
    void takeLoan();
    void repayLoan();
    void checkLoanStatus();
};

bool BankManagement::checkAvailability()
{
    return (accno == 0 && name == "" && address == "" && actype == "" && amount == 0.0 && loanAmount == 0.0);
}

bool BankManagement::searchAccount(int a)
{
    return (accno == a); 
}

void BankManagement::newAccount()
{
    cout << " Enter your account no: ";
    if (!(cin >> accno))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid account number." << endl;
        return;
    }

    cout << " Enter your first name: ";
    cin >> name;

    cout << " Enter your address: ";
    cin >> address;

    cout << " What type of account you want to open saving(s) or Current(c) or Another(a):";
    cin >> actype;

    // Validate the input
    while (actype != "s" && actype != "c" && actype != "a") {
        cout << "Invalid account type. Please enter 's' for saving, 'c' for current, or 'a' for another type: ";
        cin >> actype;
    }

    cout << " Enter How much money you want to deposit: ";
    if (!(cin >> amount))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid amount." << endl;
        return;
    }

    if (amount < 0)
    {
        cout << "Invalid amount. Amount cannot be negative." << endl;
        return;
    }

    cout << " Account Created Successfully..." << endl;
}

void BankManagement::deposit()
{
    float d;
    cout << "\n Enter amount to Deposit = ";
    if (!(cin >> d))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid amount." << endl;
        return;
    }

    if (d < 0)
    {
        cout << "Invalid amount. Amount cannot be negative." << endl;
        return;
    }

    amount += d;
    cout << " Updated...New Amount = " << amount << endl;
}

void BankManagement::withdraw()
{
    int wd;
    cout << "\n Enter amount to withdraw = ";
    if (!(cin >> wd))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid amount." << endl;
        return;
    }

    if (wd < 0)
    {
        cout << "Invalid amount. Amount cannot be negative." << endl;
        return;
    }

    if (wd <= amount)
    {
        amount -= wd;
        cout << "\n Amount is withdrawn." << endl;
    }
    else
    {
        cout << "\n You don't have enough amount in the bank." << endl;
    }
    cout << "\n Remaining amount: " << amount << endl;
}

void BankManagement::checkAccount()
{
    cout << "\n Your name: " << name << endl;
    cout << "\n Your address: " << address << endl;
    cout << "\n Account type: " << actype << endl;
    cout << "\n Amount= " << amount << endl;
}

void BankManagement::modifyAccount()
{
    cout << "\n Account No. : " << accno << endl;
    cout << "\n Modify Account Holder Name : ";
    cin >> name;
    cout << "\n Modify your address: ";
    cin >> address;
    cout << "\n Modify Type of Account: saving (s) or Current (c) or Another (a): ";
    cin >> actype;

    // Validate the input
    while (actype != "s" && actype != "c" && actype != "a") {
        cout << "Invalid account type. Please enter 's' for saving, 'c' for current, or 'a' for another type: ";
        cin >> actype;
    }

    cout << "\n Account is modified." << endl;
}

void BankManagement::deleteAccount()
{
    accno = 0;
    name = "";
    address = "";
    actype = "";
    amount = 0.0;
    loanAmount = 0.0;
    cout << "\n Successfully deleted." << endl;
}

void BankManagement::takeLoan()
{
    cout << " Enter the amount of loan you want to take: ";
    float loan;
    if (!(cin >> loan))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid amount." << endl;
        return;
    }

    if (loan < 0)
    {
        cout << "Invalid amount. Amount cannot be negative." << endl;
        return;
    }

    loanAmount += loan;
    cout << "Loan taken successfully. Total loan amount: " << loanAmount << endl;
}

void BankManagement::repayLoan()
{
    cout << " Enter the amount you want to repay: ";
    float repayment;
    if (!(cin >> repayment))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid amount." << endl;
        return;
    }

    if (repayment < 0)
    {
        cout << "Invalid amount. Amount cannot be negative." << endl;
        return;
    }

    if (repayment > loanAmount)
    {
        cout << "Repayment amount exceeds total loan amount." << endl;
        return;
    }

    loanAmount -= repayment;
    cout << "Loan repayment successful. Remaining loan amount: " << loanAmount << endl;
}

void BankManagement::checkLoanStatus()
{
    cout << "Loan amount: " << loanAmount << endl;
}

int main()
{
    BankManagement b[5];

    int x, an;
    bool check;

    while (true)
    {
        system("CLS");
        cout << "             =================              "
             << endl;
        cout << "             |   Bank Menu   |              " << endl;
        cout << "==========================================" << endl;
        cout << " Enter 1 to create a new account.\n Enter 2 to Deposit.\n Enter 3 to Withdraw.\n Enter 4 to Check account.\n Enter 5 to Modify.\n Enter 6 to Delete.\n Enter 7 to take Loan.\n Enter 8 to Repay Loan.\n Enter 9 to Check Loan Status.\n Enter 10 to show all accounts.\n Enter 11 to exit";
        cout << "\n==========================================" << endl;
        cout << " Enter choice no: ";
        cin >> x;

        switch (x)
        {
        case 1:
        {
            check = false;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].checkAvailability())
                {
                    check = true;
                    b[i].newAccount();
                    break;
                }
            }

            if (!check)
                cout << " Accounts exceeded." << endl;

            break;
        }
        case 2:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].deposit();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 3:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].withdraw();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 4:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].checkAccount();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 5:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].modifyAccount();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 6:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].deleteAccount();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 7:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].takeLoan();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 8:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].repayLoan();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 9:
        {
            check = false;
            cout << " Enter account no. : ";
            cin >> an;
            for (int i = 0; i < 5; i++)
            {
                if (b[i].searchAccount(an))
                {
                    check = true;
                    b[i].checkLoanStatus();
                    break;
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 10:
        {
            check = false;
            for (int i = 0; i < 5; i++)
            {
                if (!b[i].checkAvailability())
                {
                    check = true;
                    cout << "\nAccount details of " << i + 1 << ":\n ";
                    b[i].checkAccount();
                    cout << "\n==========================================\n";
                }
            }

            if (!check)
                cout << " No account found ." << endl;

            break;
        }
        case 11:
        {
            exit(0);
        }
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

return 0;
}