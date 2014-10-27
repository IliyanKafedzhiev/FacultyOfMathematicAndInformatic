#include <iostream> //Dvoichni failove Pozicionirane
#include <fstream>;
using namespace std;
int main()
{
    fstream bin ;
    bin.open("BINFIle.bin",ios::binary);
    bin.tellg();//chetene vrashta poziciqta
    bin.tellp();//pisane vrashta tekushtiq kursor na potoka na pisane
    bin.seekg(3,ios::begin);//premestvane pri cheten ot nachaloto
    bin.seekg(3,ios::end);//premestvane pri chetee ot kraq
    bin.seekg(3,ios::cur);//premestwane pri chetene ot tekushtata poziciq
    bin.seekp(3,ios::begin);//premestvane pri pisane ot nachaloto
    bin.seekp(3,ios::end);//premestvane pri pisane ot kraq
    bin.seekp(3,ios::cur);//premestvane pri pisane ot tekushtata poziciq
    ofstream file ("car",ios::binary)
    car c;
    file.write((char*)&c.weight,sizeof(c));

    return 0;
}
struct car
{
    int weight;
    char brand[20];
};

