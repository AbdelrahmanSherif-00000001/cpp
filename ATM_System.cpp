#include <iostream>
#include <string> // => for manipulating strings, example : compare()
#include <iomanip> // => for setw()
#include <Windows.h> // => for Sleep() and system()
using namespace std;

const int balance = 1000000;

class Atm
{
private:
    size_t _bankBalance;
public:
    Atm() : _bankBalance(balance) {}
    void increaseBankbalance(size_t _deposited) 
    {
        _bankBalance += _deposited;
    }
    void decreaseBankbalance(size_t _withdrawen)
    {
        _bankBalance -= _withdrawen;
    }
    size_t getBalance() 
    {
        return _bankBalance;
    }
};

class Customer
{
private:
    Atm& atm;
    size_t _balance;
public:
    Customer(Atm& atm_ref) : atm(atm_ref), _balance(0) {}
    void setuserBalance(size_t keeped_balance)
    {
        _balance = keeped_balance;
    }
    size_t getuserBalance()
    {
        return _balance;
    }

    void showBalance(const string& card_type) 
    {
        if (card_type == "silver") {
            _balance = 9000;
            cout << "Your balance is : " << _balance << endl;
        }
        else if (card_type == "gold") {
            _balance = 10000;
            cout << "Your balance is : " << _balance << endl;
        }
        else if (card_type == "platinum") {
            _balance = 12000;
            cout << "Your balance is : " << _balance << endl;
        }
    }
    void Withdraw(size_t money_amount)
    {
        if (money_amount <= _balance )
        {
            cout << "Please wait, while your transaction is done "<< endl;
            Sleep(3000);
            _balance -= money_amount;
           
            cout << "Your transaction has ended, your current balance is : " << _balance << endl;
            atm.decreaseBankbalance(money_amount);
        }
        else if (money_amount > atm.getBalance())
        {
            Sleep(2000);
            cout << "Balance in the machine is not enough" << endl;
        }
        else if(money_amount > _balance)
        {
            Sleep(2000);
            cout << "your current balance is not enough, please try again" << endl;
        }
    }
    void Deposit(size_t depo_money)
    {
        cout << "Few seconds to confirm your deposite, please wait... " << endl;
       _balance += depo_money;
        Sleep(3000);
        cout << "Your deposite has been done, your current balance is : " << _balance << endl;
        atm.increaseBankbalance(depo_money);
    }
    void Transfer(const string& acc_number, size_t amount_to_transfer)
    {
        if (amount_to_transfer <= _balance && acc_number.size() == 16 || acc_number.size() == 19)
        {
            cout << "Wait few seconds to verify information" << endl;
            Sleep(10000);
            cout << "transfer has been done, " << amount_to_transfer << " has been send to owner of account: " << acc_number << endl;
            _balance -= amount_to_transfer;
            cout << "Your current balance is :" << _balance;
            atm.increaseBankbalance(amount_to_transfer);
        }
        else
        {
            cout << "Incorrect account number or invalid balance, Please try again \n";
        }
    }
};

class Technican
{
private:
    Atm& atm;
    string _name ;
    string _password ;
public:
    Technican(Atm& atmref) : atm(atmref),_name("natish hindi"),_password("147852369") {}
    string get_techname() const
    {
        return _name;
    }
    string getPassword() const
    {
        return _password;
    }
    void Repair()
    {
        cout << "The Atm will be out of service for 10 minutes for repair purposes \n if you don't have time it's better to use another machine, have a good day" << endl;
        Sleep(600000);
    }
    void fillAtm(size_t _forfill)
    {
        atm.increaseBankbalance(_forfill);
        cout << "Wait untill the refill process finish" << endl;
        Sleep(60000);
        cout << "Refill has finished, You can now use the machine" << endl;
    }
};

void Display_Magic(Customer& cust, Technican& tech, Atm& atm)
{
    int trynum = 0;
    int user_type_choice;
    int operation_choice;
    int tech_choice;
    int card_choice;
    int main_menu_option;
    size_t keep_balance;
    string card_type;
    system("Color 02");
    cout << setw(56) << "Sherif Bank \n";
    cout << "Please, itentify yourself \n 1-> for normal users \t \t 2-> for technican \n";
    cout << "Enter your choice....";
    cin >> user_type_choice;
    switch (user_type_choice)
    {
    case 1:
        Sleep(4000);
        system("CLS");
        cout << "Choose the operation you want \n";
        cout << "1.Show Balance \n";
        cout << "2.Withdraw \n";
        cout << "3.Deposite \n";
        cout << "4.Transfer \n";
        cout << "press number of operation you want, But please see your balance first ....";
        cin >> operation_choice;
        Sleep(2000);
        system("CLS");
        switch (operation_choice)
        {
        case 1:
            cout << "choose your card type \n 1.Silver \t\t 2.Gold \t\t 3.platinum \n";
            cout << "your choice....";
            cin >> card_choice;
            if (card_choice == 1)
                card_type = "silver";
            else if (card_choice == 2)
                card_type = "gold";
            else if (card_choice == 3)
                card_type = "platinum";
            Sleep(1000);
            cust.showBalance(card_type);
            keep_balance = cust.getuserBalance();
            cout << "Do you want another operation, press 0 to main menu , press 9 to exit.... ";
            cin >> main_menu_option;
            if (main_menu_option == 0)
            {
                Sleep(2000);
                system("CLS");
                Atm atm;
                Technican tech(atm);
                Customer cust(atm);
                cust.setuserBalance(keep_balance);
                Display_Magic(cust, tech, atm);
            }
            else
                return;
            break;
        case 2:
            int withdrawn_amount;
            cout << "Enter the amount you want : ";
            cin >> withdrawn_amount;
            cust.Withdraw(withdrawn_amount);
            Sleep(2000);
            break;
        case 3:
            int deposited_amount;
            cout << "Enter the amount you want to deposit.....";
            cin >> deposited_amount;
            cust.Deposit(deposited_amount);
            Sleep(2000);
            keep_balance = cust.getuserBalance();
            cout << "Do you want another operation, press 0 to main menu , press 9 to exit.... ";
            cin >> main_menu_option;
            if (main_menu_option == 0)
            {
                Sleep(2000);
                system("CLS");
                Atm atm;
                Technican tech(atm);
                Customer cust(atm);
                cust.setuserBalance(keep_balance);
                Display_Magic(cust, tech, atm);
            }
            else
                return;
            break;
        case 4:
            string account_number;
            size_t transfered_amount;
            cout << "Enter account number : ";
            cin >> account_number;
            cout << "Enter amount you want to transfer : ";
            cin >> transfered_amount;
            cust.Transfer(account_number, transfered_amount);
            Sleep(2000);
            break;
        }
        break;
    case 2:
        string username;
        string password;
        cin.ignore();

        cout << "Enter username : ";
        getline(cin,username);

        cout << "Enter password : ";
        getline(cin, password);
        int test1 = tech.get_techname().compare(username);
        int test2 = tech.getPassword().compare(password);
        if (test1 == 0 && test2 == 0)
        {
            Sleep(2000);
            system("CLS");
            cout << "Choose the process you want : \n 1-> Repair \t\t 2-> Fill the atm \n";
            cout << "press number of process you want ....";
            cin >> tech_choice;
            Sleep(2000);
            system("CLS");
            switch (tech_choice)
            {
            case 1:
                tech.Repair();
                break;
            case 2:
                if (atm.getBalance() < 50000)
                {
                    size_t money_for_fill;
                    cout << "Enter the you want to add the Atm : ";
                    cin >> money_for_fill;
                    tech.fillAtm(money_for_fill);
                }
                else
                {
                    cout << "Atm does not need to be filled at the current time \n";
                    cout << "The cuurent balance in the atm is : " << atm.getBalance();
                }
                break;
            }
        }
        else
        {
            cout << "You enter incorrect data, restart the machine and sign in again \n";
            return;
        }
        break;
    }
}

int main()
{
    Atm atm;
    Customer cust(atm);
    Technican tech(atm);
    Display_Magic(cust, tech, atm);
   return 0;
}
