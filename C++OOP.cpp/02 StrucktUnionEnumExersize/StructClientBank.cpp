#include <iostream>
#include <cstring>
using namespace std;
const int max_length=20;
struct Person
{
    char firstName [max_length];
    char lastName [max_length];
};
struct Client
{
    Person person;
    double balance;
};
Client clients[max_length];

void readClient (Client &acount)
{
    cout<<"Ballance";
    cin>>acount.balance;
    cout<<"FirstNamePerson"<<endl;
    cin.getline(acount.person.firstName,19);
    cout<<"LaNamePerson"<<endl;
    cin.getline(acount.person.lastName,19);

}
void printClient(Client &p)
{
    cout<<p.person.firstName<<" "<<p.person.lastName<<"  "<<p.balance<<endl;
}

int main()
{
    int n;
cin>>n;
if(n>=max_length)
  {cin>>n;}
    double pay=0;
for (unsigned int i=0;i<=n;i++)
{
    readClient(clients[i]);
    printClient (clients[i]);
    if(clients[i].balance<0)
    {
        pay+=clients[i].balance;
    }

}
cout<<"paymants are:"<<pay<<endl;
return 0;
}
