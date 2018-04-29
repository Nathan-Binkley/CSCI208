#include <iostream>
#include <string>

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
