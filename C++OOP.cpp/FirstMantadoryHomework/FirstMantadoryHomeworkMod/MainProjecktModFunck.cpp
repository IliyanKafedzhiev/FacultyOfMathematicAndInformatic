// Илиян Митков Кафеджиев 4 група Фак.Номер:44877
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
struct Companies
{
    unsigned IDCom;
    char Name [31];
    double StockPrice;
};
struct Invertors
{
    unsigned int ID;
    char Name[31];
    double capital;
};
struct Stocks
{
    unsigned InvID;
    unsigned ComID;
    double Count;
};
void choiceB(fstream &,fstream &,fstream&);
int choiceS(fstream &,fstream &,fstream&);
void choiceP(fstream &,fstream &,fstream&);
int main ( int argc , char* argv[])
{
    fstream FileI;                                                       // Read INVERTORS
    FileI.open(argv[1],ios::binary | ios::in | ios::out);
    if (!FileI)
    {
        cout<<"ERROR"<<endl;
        return 0;
    }
    fstream FileS;                                                      // Read STOCKS
    FileS.open(argv[3],ios::binary | ios::in | ios::out);
    if (!FileS)
    {
        cout<<"ERROR"<<endl;
        return 0;
    }
    fstream FileC;                                                     //Read Comnpanies
    FileC.open(argv[2],ios::binary|ios::in);
    if (!FileC)
    {
        cout<<"ERROR"<<endl;
        return 0;
    }
    bool TrueInput=true;
    fstream fileT;
    do
    {
        char choice;                                                                         //Choice MENU
        cin>>choice;
        switch (choice)
        {
            case 'b':
                choiceB(FileI,FileS,FileC);
                break;
            case 's':
                int result;
                result =choiceS(FileI,FileS,FileC);
                if(result!=-1)
                {
                        Stocks Stock[1];
                        FileS.clear();
                        FileS.seekg(0,ios::beg);
                        fstream newFile;
                        newFile.open("new.dat",ios::binary|ios::out);
                        for(int i=0;FileS.read((char*)&Stock[0],sizeof(Stocks));i++)
                        {
                            if (i!=result)
                            {
                                newFile.write((char*)&Stock[0],sizeof(Stocks));
                            }
                        }
                        FileS.close();
                        if (remove(argv[3])!=0)
                        {
                            cout<<"ERROR"<<endl;
                            break;
                        }
                        newFile.close();
                        char oldname[] ="new.dat";
                        if (rename(oldname,argv[3])!=0)
                        {
                            cout<<"ERROR"<<endl;
                            break;
                        }
                        cout<<"OK"<<endl;
                }
                break;
            case 'p':
                choiceP(FileI,FileS,FileC);
                break;
            default:
                TrueInput=false;
                break;
        }

    }
    while(!TrueInput==false);
    FileI.close();
    FileC.close();
    FileS.close();

    return 0;
}
void choiceB(fstream &FileI,fstream &FileS,fstream&FileC)
{
                    Companies Companie [1];
                    Stocks Stock [1];
                    Invertors Invertor [1];
                    double sumStocks=0;
                    int numInvertor=-1;
                    int numCompanie=-1;
                    int numStock=-1;
                    unsigned chosenIDIn;
                    unsigned chosenIDCom;
                    double chosenSum;
                    FileI.seekg(0,ios::beg);
                    FileS.seekg(0,ios::beg);
                    FileC.seekg(0,ios::beg);
                    FileI.clear();
                    FileC.clear();
                    FileS.clear();
                    // cout<<endl<<"Imput ID Investor=";                                          //Search for Invertor
                    cin>>chosenIDIn;
                    cin>>chosenIDCom;
                    cin>>chosenSum;
                    if (chosenSum<0)
                    {
                        cout<<"ERROR"<<endl;
                        return;
                    }

                    for (int i=0;!FileI.eof();i++)
                    {
                        FileI.read((char*)&Invertor[0],sizeof(Invertors));
                        if (Invertor[0].ID==chosenIDIn)
                        {
                            numInvertor=i;
                            if (Invertor[0].capital<chosenSum)
                            {
                                cout<<"ERROR"<<endl;
                                return ;
                            }
                            break;
                        }
                    }
                    FileI.clear();
                    if (numInvertor==-1)
                    {
                        cout<<"ERROR"<<endl;
                        return ;
                    }

                    //cout<<endl<<"Imput Sum=";
                                                                                                //Search for Company
                    //cout<<endl<<"Imput ID Company=";
                    for (int i=0;!FileC.eof();i++)
                    {
                        FileC.read ((char*)&Companie[0],sizeof(Companies));
                        if (Companie[0].IDCom==chosenIDCom)
                        {
                            numCompanie=i;
                            while (!FileS.eof())
                            {
                                FileS.read((char*)&Stock[0],sizeof(Stocks));
                                if(Stock[0].ComID==Companie[0].IDCom )
                                {
                                    sumStocks+=Stock[0].Count;
                                }
                            }
                            FileS.clear();
                            FileS.seekg(0,ios::beg);
                            if ((Companie[0].StockPrice-sumStocks)<chosenSum)
                            {
                                cout<<"ERROR"<<endl;
                                 //cout<<fixed<<sumStocks;
                                return ;
                            }
                            break;
                        }
                    }
                    if (numCompanie==-1)
                    {
                        cout<<"ERROR"<<endl;
                        return ;
                    }
                    FileC.clear();
                    for (int i=0;!FileS.eof();i++)
                    {
                        FileS.read((char*)&Stock[0],sizeof(Stocks));
                        if(Stock[0].ComID==Companie[0].IDCom && Stock[0].InvID==Invertor[0].ID)
                        {
                            numStock=i;
                            break;
                        }
                    }
                    FileS.clear();
                    Invertor[0].capital=Invertor[0].capital-chosenSum;           //MAKE PURCHASE WRITE INVESTOR CHANGE
                    FileI.seekp((numInvertor)*(sizeof(Invertors)),ios::beg);
                    FileI.write((char*)&Invertor[0],sizeof(Invertors));
                    if (numStock==-1)                                                               //Write NEW STOCKS
                    {
                        Stocks newStock;
                        newStock.Count=chosenSum;
                        newStock.ComID=Companie[0].IDCom;
                        newStock.InvID=Invertor[0].ID;
                        FileS.seekp(0,ios::end);
                        FileS.write((char*)&newStock,sizeof(Stocks));
                        cout<<"OK"<<endl;
                        return ;
                    }
                    else
                    {
                        Stock[0].Count+=chosenSum;
                        FileS.seekp(numStock*sizeof(Stocks),ios::beg);
                        //cout<<"POSITION STOCKS"<<FileS.tellp();
                        FileS.write((char*)&Stock[0],sizeof(Stocks));
                        cout<<"OK"<<endl;
                        return ;
                    }
}
int choiceS(fstream &FileI,fstream &FileS,fstream &FileC)
{
                    Companies Companie [1];
                    Stocks Stock [1];
                    Invertors Invertor [1];                                                                   //SEL STOCKS
                    double sumStocks=0;
                    int numInvertor=-1;
                    int numCompanie=-1;
                    int numStock=-1;
                    unsigned chosenIDIn;
                    unsigned chosenIDCom;
                    FileI.seekg(0,ios::beg);
                    FileS.seekg(0,ios::beg);
                    FileC.seekg(0,ios::beg);
                    FileI.clear();
                    FileC.clear();
                    FileS.clear();
                    double chosenSum;
                    cin>>chosenIDIn;
                    cin>>chosenIDCom;
                    cin>>chosenSum;
                    if (chosenSum<0)
                    {
                        cout<<"ERROR"<<endl;
                        return -1;
                    }
                    for (int i=0;!FileS.eof();i++)                                               //Search for Avaiable Stocks
                    {
                        FileS.read((char*)&Stock[0],sizeof(Stocks));
                        if(Stock[0].ComID==chosenIDCom && Stock[0].InvID==chosenIDIn)
                        {
                            numStock=i;
                            if(Stock[0].Count<chosenSum)
                            {
                                cout<<"ERROR"<<endl;
                                return -1;
                            }
                            break;
                        }
                    }
                    FileS.clear();
                    if (numStock==-1)
                    {
                        cout<<"ERROR"<<endl;
                        return -1;
                    }

                    Stock[0].Count=Stock[0].Count-chosenSum;

                    FileS.seekp(numStock*sizeof(Stocks),ios::beg);
                    FileS.write((char*)&Stock[0],sizeof(Stocks));
                    for (int i=0;!FileI.eof();i++)
                    {
                        FileI.read((char*)&Invertor[0],sizeof(Invertors));
                        if(Invertor[0].ID==chosenIDIn)
                        {
                            numInvertor=i;
                            break;
                        }
                    }
                    FileI.clear();
                    if (numInvertor==-1)
                    {
                        cout<<"ERROR"<<endl;
                        return -1;
                    }
                    Invertor[0].capital=Invertor[0].capital+chosenSum;
                    FileI.seekp(numInvertor*sizeof(Invertors),ios::beg);
                    FileI.write((char*)&Invertor[0],sizeof(Invertors));
                    if (Stock[0].Count<0.01)
                    {
                        return numStock;

                    }
                    cout<<"OK"<<endl;

                    return -1;
}
void choiceP(fstream &FileI,fstream &FileS,fstream &FileC)
{
                Companies Companie [1];
                Stocks Stock [1];
                Invertors Invertor [1];
                double sumStocks=0;
                int numInvertor=-1;
                int numCompanie=-1;
                int numStock=-1;
                unsigned chosenIDIn;
                unsigned chosenIDCom;
                FileI.clear();
                FileC.clear();
                FileS.clear();
                FileI.seekg(0,ios::beg);
                FileS.seekg(0,ios::beg);
                FileC.seekg(0,ios::beg);
                fstream fileT;
                fileT.open("InvestorInformation.txt",ios::out);
                if(!fileT)
                {
                    cout<<"ERROR"<<endl;
                    fileT.close();
                    return ;
                }
                cin>>chosenIDIn;
                if (chosenIDIn<0)
                {
                    cout<<"ERROR"<<endl;
                    fileT.close();
                    return ;
                }
                for (int i=0;!FileI.eof();i++)
                {
                    FileI.read((char*)&Invertor[0],sizeof(Invertors));
                    if(Invertor[0].ID==chosenIDIn)
                    {
                        numInvertor=i;
                        break;
                    }
                }
                FileI.clear();
                if (numInvertor==-1)
                {
                    cout<<"ERROR"<<endl;
                    fileT.close();
                    return ;
                }
                sumStocks=Invertor[0].capital;
                fileT<<"Име на Инвеститора:";

                for (int i=0;Invertor[0].Name[i]!='\0';i++)
                {
                    fileT<<Invertor[0].Name[i];
                }
                fileT<<endl<<endl<<endl;
                fileT<<"Акции:"<<endl;
                int countStocks;
                countStocks=0;
                while (!FileS.eof())
                {
                    FileS.read((char*)&Stock[0],sizeof(Stocks));
                    if(FileS.eof())
                        break;
                    if (Invertor[0].ID==Stock[0].InvID)
                    {
                        numCompanie=-1;
                        for (int j=0;!FileC.eof();j++)
                        {
                            FileC.read ((char*)&Companie[0],sizeof(Companies));
                            if (Companie[0].IDCom==Stock[0].ComID)
                            {
                                numCompanie=j;
                                break;
                            }
                        }
                        FileC.clear();
                        FileC.seekg(0,ios::beg);
                        if (numCompanie==-1)
                        {
                            break;
                        }
                        fileT<<"Компания : ";
                        int k;
                        for ( k=0;Companie[0].Name[k]!='\0';k++)
                        {
                            fileT<<Companie[0].Name[k];
                        }
                        for(k;k<30;k++)
                        {
                            fileT<<" ";
                        }
                        fileT<<"                              Дял Акции :"<<fixed<<Stock[0].Count<<endl;
                        sumStocks+=Stock[0].Count;
                    }

                }
                fileT<<endl<<endl<<"                                                                       ОБЩО КАПИТАЛ:"<<fixed<<sumStocks;
                cout<<"OK"<<endl;
                fileT.close();
                return ;
}
