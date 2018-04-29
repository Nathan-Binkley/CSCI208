#include <iostream>
#include <string>
using namespace std;

class Account{
  private:
    int AccountID;
    string Namne;
    int AccBal;

  public:
    int getAccID(){
      return AccountID;
    }
    string getNamne(){
      return Namne;
    }
    int getAccBal(){
      return AccBal;
    }
    void setAccID(int num){
      if(num > 0)
          AccountID = num;
      else
          AccountID = 1;
    }
    void setNamne(string name){
      Namne = name;
    }
    void setAccBal(int num){
      if(num < 0)
        AccBal = 0;
      else
        AccBal = num;
    }
    int credit(int num){
      if(num < 0)
        return 1;
      else {
        AccBal+=num;
        return 0;
      }
    }
    int debit(int num){
      if(num > AccBal)
        return 1;
      else {
        AccBal -= num;
        return 0;
      }
    }
    void toString(){
      cout << "Acc ID: " << AccountID << endl << "Name: " << Namne << endl << "Balance: "<< AccBal << endl;
    }
  Account(int ID, string Name, int Bal){
    AccountID = ID;
    Namne = Name;
    AccBal = Bal;
  }
  Account(int ID,  int Bal){
    AccountID = ID;
    AccBal = Bal;
  }
  Account(int ID, string Name){
    AccountID = ID;
    Name = Namne;
  }
  Account(string Name, int Bal){
    Name = Namne;
    AccBal = Bal;
  }
  Account(){
    AccountID = 1;
    Namne = "Bobby";
    AccBal = 1;
  }
};

int main(){
  string inp;
  int inpu;
  Account *account1 = new Account();
  cout << account1->getAccID() << endl;
  cout << account1->getNamne() << endl;
  cout << account1->getAccBal() << endl;

  cout << "give an account name" << endl;
  cin >> inp;
    account1->setNamne(inp);
  cout << "give an account id" << endl;
  cin >> inpu;
    account1->setAccID(inpu);
  cout << "give an account balance" << endl;
  cin >> inpu;
    account1->setAccBal(inpu);

  Account account2(2, "Johnny", 45);

  int num = 0;
  account1->toString();
  account2.toString();
  cout << "How much did " << account1->getNamne() << " spend?" << endl;
  cin >> num;
  account1->credit(num);

  cout << "How much did " << account2.getNamne() << " deposit?" << endl;
  cin >> num;
  account2.debit(num);

  Account acc[2];
    acc[0] = *account1;
    acc[1] = account2;

  for (int i=0;i<2;i++) {
    acc[i].toString();
  }
  return 0;
}
