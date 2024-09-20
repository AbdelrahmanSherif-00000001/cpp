#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int balance = 1000000;

class Atm
{
private:
    size_t _bankBalance;
public:
    Atm() : _bankBalance(balance) {}
    size_t getBalance() const
    {
        return _bankBalance;
    }
};

class Customer
{
private:
    Atm& atm;
    size_t _account_number;
    size_t _balance;
public:
    Customer(Atm& atm_ref) : atm(atm_ref), _account_number(0), _balance(0){}
    int find_User(const string& card_id)
    {
        string  file = "Bank.txt";
        ifstream source_file(file);
        if(!source_file.is_open())
        {
            cerr << "Error, opening the file \n";
            return 1;
        }
        string cardSearch;   bool found = false;
        while(getline(source_file, cardSearch))
        {
            if(cardSearch == card_id)
            {
                cout << card_id << "Found in the file";
                found = true;
                break;
            }
        }
        if (!found) cout << "can not find your card id ";
        source_file.close();
    }
    void showBalance() {}
    void withDraw() {}
    void Transfer() {}
    void Deposite() {}
};

class Technician
{
private:
    string _name;
    size_t _password;
public:
    void Repair() {}
    void fillAtm() {}
    void Update() {}
};


int main()
{
    Atm atm;
    string id = "balance";
    Customer cust(atm);
    cust.find_User(id);
   return 0;
}
