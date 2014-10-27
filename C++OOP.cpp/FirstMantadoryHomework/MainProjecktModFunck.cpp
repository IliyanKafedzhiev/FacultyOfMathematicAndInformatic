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
}*Companie;
struct Invertors
{
    unsigned int ID;
    char Name[31];
    double capital;
}*Invertor;
struct Stocks
{
    unsigned InvID;
    unsigned ComID;
    double Count;
}*Stock;
int choiceB(fstream &,fstream &,fstream&);
int choiceS(fstream &,fstream &,fstream&);
int choiceP(fstream &,fstream &,fstream&);
int main ( int argc , char* argv[])
{
    fstream FileI;                                                       // Read INVERTORS
    FileI.open(argv[1],ios::binary | ios::in | ios::out);
    if (!FileI)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    fstream FileS;                                                      // Read STOCKS
    FileS.open(argv[2],ios::binary | ios::in | ios::out);
    if (!FileS)
    {
        cout<<"Error"<<endl;
        delete Invertor;
        return 0;
    }
    FileS.seekg(0,ios::end);
    int HowManyStocks=(FileS.tellg())/sizeof(Stocks);
    Stock =new Stocks [HowManyStocks];
    FileS.seekg(0,ios::beg);
    for (int i=0;!FileS.eof();i++)
    {
        FileS.read((char*)&Stock[i],sizeof(Stocks));
    }
    fstream FileC;                                                     //Read Comnpanies
    FileC.open(argv[3],ios::binary|ios::in);
    if (!FileC)
    {
        cout<<"Error"<<endl;
        delete Invertor;
        delete Stock;
        return 0;
    }
    FileC.seekg(0,ios::end);
    int HowManyCompanies=(FileC.tellg())/sizeof(Companies);
    Companie =new Companies [HowManyCompanies];
    FileC.seekg(0,ios::beg);
    for (int i=0;!FileC.eof();i++)
    {
        FileC.read((char*)&Companie[i],sizeof(Companies));
    }
    bool TrueInput=true;
    FileC.clear();                                                                            //File CLEAR FLAG STATUS
    FileS.clear();
    FileI.clear();
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
                choiceS(FileI,FileS,FileC);
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
int choiceB(fstream &FileI,fstream &FileS,fstream&FileC)
{
                    double sumStocks;
                    int numInvertor=-1;
                    int numCompanie=-1;
                    int numStock=-1;
                    FileS.seekg(0,ios::end);
                    int HowManyStocks=(FileS.tellg())/sizeof(Stocks);
                    FileC.seekg(0,ios::end);
                    int HowManyCompanies=(FileC.tellg())/sizeof(Companies);
                    FileI.seekg(0,ios::end);
                    int HowManyInvertors=(FileI.tellg())/sizeof(Invertors);
                    unsigned chosenIDIn;
                    unsigned chosenIDCom;
                    double chosenSum;
                    FileI.seekg(0,ios::beg);
                    FileS.seekg(0,ios::beg);
                    FileC.seekg(0,ios::beg);                                                      // Choice BUY A STOCKS
                    // cout<<endl<<"Imput ID Investor=";                                          //Search for Invertor
                    cin>>chosenIDIn;
                    for (int i=0;i<HowManyInvertors;i++)
                    {
                        if (Invertor[i].ID==chosenIDIn)
                        {
                            numInvertor=i;
                        }
                    }
                    if (numInvertor==-1)
                    {
                        cout<<"Error"<<endl;
                        return 0;
                    }

                    //cout<<endl<<"Imput Sum=";
                    cin>>chosenSum;
                    if((Invertor[numInvertor].capital)<chosenSum)
                    {
                        cout<<"Error"<<endl;
                        return 0;
                    }
                                                                          //Search for Company
                    //cout<<endl<<"Imput ID Company=";
                    cin>>chosenIDCom;
                    for (int i=0;i<HowManyCompanies;i++)
                    {
                        if (Companie[i].IDCom==chosenIDCom)
                        {
                            numCompanie=i;
                        }
                    }
                    if (numCompanie==-1)
                    {
                        cout<<"Error"<<endl;
                        return 0;
                    }
                                                                                                    //Search for Free Stocks

                    sumStocks=0;
                    for (int i=0;i<HowManyStocks;i++)
                    {
                        if(Stock[i].ComID==Companie[numCompanie].IDCom )
                        {
                            sumStocks+=Stock[i].Count;
                        }
                    }
                    if ((Companie[numCompanie].StockPrice-sumStocks)>=chosenSum)
                    {
                        cout<<"Error"<<endl;
                         //cout<<fixed<<sumStocks;
                        return 0;
                    }
                    Invertor[numInvertor].capital=Invertor[numInvertor].capital-chosenSum;           //MAKE PURCHASE WRITE INVESTOR CHANGE
                    FileI.seekg((numInvertor)*(sizeof(Invertors)),ios::beg);
                    //cout<<"POSITION:"<<(numInvertor)*(sizeof(Invertors))<<endl;
                    //cout<<"POSITION INVESTORRS"<<FileI.tellg()<<endl;
                    FileI.write((char*)&Invertor[numInvertor],sizeof(Invertors));
                    for (int i=0;i<HowManyStocks;i++)                                               //Search for Avaiable Stocks
                    {
                        if(Stock[i].ComID==Companie[numCompanie].IDCom && Stock[i].InvID==Invertor[numInvertor].ID)
                        {
                            numStock=i;
                        }
                    }
                    if (numStock==-1)                                                               //Write NEW STOCKS
                    {
                        Stocks newStock;
                        newStock.Count=chosenSum;
                        newStock.ComID=Companie[numCompanie].IDCom;
                        newStock.InvID=Invertor[numInvertor].ID;
                        FileS.seekp(0,ios::end);
                        FileS.write((char*)&newStock,sizeof(Stocks));
                        cout<<"OK"<<endl;
                        return 1;
                    }
                    else
                    {
                        Stock[numStock].Count+=chosenSum;
                        FileS.seekp(numStock*sizeof(Stocks),ios::beg);
                        //cout<<"POSITION STOCKS"<<FileS.tellp();
                        FileS.write((char*)&Stock[numStock],sizeof(Stocks));
                        cout<<"OK"<<endl;
                        return 1;
                    }
}
int choiceS(fstream &FileI,fstream &FileS,fstream &FileC)
{
                                                                                       //SEL STOCKS
                    double sumStocks;
                    int numInvertor=-1;
                    int numCompanie=-1;
                    int numStock=-1;
                    FileS.seekg(0,ios::end);
                    int HowManyStocks=(FileS.tellg())/sizeof(Stocks);
                    FileC.seekg(0,ios::end);
                    int HowManyCompanies=(FileC.tellg())/sizeof(Companies);
                    FileI.seekg(0,ios::end);
                    int HowManyInvertors=(FileI.tellg())/sizeof(Invertors);
                    unsigned chosenIDIn;
                    unsigned chosenIDCom;
                    FileI.seekg(0,ios::beg);
                    FileS.seekg(0,ios::beg);
                    FileC.seekg(0,ios::beg);
                    double chosenSum;
                      //  cout<<"Input ID Investor"<<endl;
                        cin>>chosenIDIn;
                      //  cout<<"Input ID Company"<<endl;
                        cin>>chosenIDCom;
                      //  cout<<"Input Sell PRICE"<<endl;
                        cin>>chosenSum;
                        for (int i=0;i<HowManyStocks;i++)                                               //Search for Avaiable Stocks
                        {
                            if(Stock[i].ComID==chosenIDCom && Stock[i].InvID==chosenIDIn)
                            {
                                numStock=i;
                            }
                        }
                        if (numStock==-1)
                        {
                            cout<<"Erorr"<<endl;
                            return 0;
                        }
                        if(Stock[numStock].Count<chosenSum)
                        {
                            cout<<"Erorr "<<endl;
                            return 0;
                        }
                        Stock[numStock].Count=Stock[numStock].Count-chosenSum;
                        FileS.seekp(numStock*sizeof(Stocks),ios::beg);
                        FileS.write((char*)&Stock[numStock],sizeof(Stocks));
                        for (int i=0;i<HowManyInvertors;i++)
                        {
                            if(Invertor[i].ID==chosenIDIn)
                            {
                                numInvertor=i;
                            }
                        }
                        if (numInvertor==-1)
                        {
                            cout<<"Error "<<endl;
                            return 0;
                        }
                        Invertor[numInvertor].capital=Invertor[numInvertor].capital+chosenSum;
                        FileI.seekp(numInvertor*sizeof(Invertors),ios::beg);
                        FileI.write((char*)&Invertor[numInvertor],sizeof(Invertors));
                        cout<<"OK"<<endl;
                        return 1;
}
int choiceP(fstream &FileI,fstream &FileS,fstream &FileC)
{
                double sumStocks;
                int numInvertor=-1;
                int numCompanie=-1;
                int numStock=-1;
                FileS.seekg(0,ios::end);
                int HowManyStocks=(FileS.tellg())/sizeof(Stocks);
                FileC.seekg(0,ios::end);
                int HowManyCompanies=(FileC.tellg())/sizeof(Companies);
                FileI.seekg(0,ios::end);
                int HowManyInvertors=(FileI.tellg())/sizeof(Invertors);
                unsigned chosenIDIn;
                unsigned chosenIDCom;
                FileI.seekg(0,ios::beg);
                FileS.seekg(0,ios::beg);
                FileC.seekg(0,ios::beg);
                fstream fileT;
                fileT.open("InvestorInformation.txt",ios::out);
                if(!fileT)
                {
                    cout<<"Error"<<endl;
                    fileT.close();
                    return 0;
                }
               // cout<<"Input Investor ID"<<endl;
                cin>>chosenIDIn;
                for (int i=0;i<HowManyInvertors;i++)
                {
                    if(chosenIDIn==Invertor[i].ID)
                    {
                        numInvertor=i;
                    }
                }
                if (numInvertor==-1)
                {
                    cout<<"Error"<<endl;
                    fileT.close();
                    return 0;
                }
                sumStocks=Invertor[numInvertor].capital;
                fileT<<"Име на Инвеститора:";

                for (int i=0;Invertor[numInvertor].Name[i]!='\0';i++)
                {
                    fileT<<Invertor[numInvertor].Name[i];
                }
                fileT<<endl<<endl<<endl;
                fileT<<"Акции:"<<endl;
                int countStocks;
                countStocks=0;
                for (int i=0 ;i<HowManyStocks;i++)
                {
                    if (Invertor[numInvertor].ID==Stock[i].InvID)
                    {
                        numCompanie=-1;
                        for (int j=0;j<HowManyCompanies;j++)
                        {
                            if (Companie[j].IDCom==Stock[i].ComID)
                            {
                                numCompanie=j;
                            }
                        }
                        if (numCompanie==-1)
                        {
                            break;
                        }
                        fileT<<"Компания : ";
                        int k;
                        for ( k=0;Companie[numCompanie].Name[k]!='\0';k++)
                        {
                            fileT<<Companie[numCompanie].Name[k];
                        }
                        for(k;k<30;k++)
                        {
                            fileT<<" ";
                        }
                        fileT<<"                              Дял Акции :"<<fixed<<Stock[i].Count<<endl;
                        sumStocks+=Stock[i].Count;
                    }
                }
                fileT<<endl<<endl<<"                                                                       ОБЩО КАПИТАЛ:"<<fixed<<sumStocks;
                cout<<"OK"<<endl;
                fileT.close();
                return 1;
}
