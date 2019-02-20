#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct PERSON{
char Name[20];
float Balance;

};

void Display(PERSON *persons, int N);
void FindRichest(PERSON *persons, int N);
void Deposit(char CustName[],PERSON *persons, int N);
void NewCopy(string fname, PERSON *persons, int N);

int main(){
int N=0;
ifstream in;
in.open("data.txt");
  if(in.fail()){
    cout<<"Unable to open file"<<endl;
    return 0;
    }

string line;
  while(getline(in, line)){
    N++;
    }

in.clear();
in.seekg(0, ios::beg);
PERSON *persons = new PERSON[N];
string fname, lname;
int i=0;
  while(in>>fname>>lname>>persons[i].Balance){
    strcpy(persons[i].Name, (fname+" "+lname).c_str());
    i++;
    }

Display(persons, N);
FindRichest(persons, N);

char CustName[20];
cout<<"Enter your full name to deposit money:";
cin.getline(CustName, 20);
Deposit(CustName, persons, N);
NewCopy("data.txt", persons, N);
return 0;

}

void Display(PERSON *persons, int N){
cout<<setprecision(2)<<fixed;
cout<<setw(20)<<left<<"Name"<<" Balance"<<endl;
cout<<"-------------------------------------"<<endl;
  for(int i=0; i<N; i++){
      cout<<setw(20)<<persons[i].Name<<" "<<persons[i].Balance<<endl;
      }
    }

void FindRichest(PERSON *persons, int N){
int max=0;
  for(int i=0; i<N; i++){
    if(persons[max].Balance<persons[i].Balance)
      max = i;
      }
      cout<<"The customer with maximum balance is "<<persons[max].Name<<endl;
      }

void Deposit(char CustName[],PERSON *persons, int N){
int ind = -1;
  for(int i=0; i<N; i++){
    if(strcmp(CustName, persons[i].Name)==0){
      ind = i;
      break;
      }
    }

    if(ind==-1)
      cout<<"Sorry! Customer Name not found"<<endl;
      else{
        double deposit;
        cout<<" "<<CustName<<", how much would you like to deposit? ";
        cin>>deposit;
        persons[ind].Balance+=deposit;
        cout<<"Now your new balance is "<<persons[ind].Balance<<endl;
          }
        }

void NewCopy(string fname, PERSON *persons, int N){
ofstream out;
out<<setprecision(2)<<fixed;
out.open(fname.c_str());
  for(int i=0; i<N; i++){
    out<<persons[i].Name<<" "<<persons[i].Balance<<endl;
    }
    out.close();
    }
