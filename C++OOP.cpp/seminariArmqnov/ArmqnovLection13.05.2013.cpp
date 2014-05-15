class Device
{
public:
    Device(const char* b,int t,double p,double w):brand(strcpy(new char [strlen(b)+1]),b),price(p),weight(w);
    Device(cosnt Device&d):brand(strcpy(new char [strlen(d.brand)+1]),d.brand),price(d.price),weight(d.price);
    {

    }
    ~Device()
    {
        char*b=(char*)brand;
        delete []b;
    }
protected:
    int liveTime;
private:
    void operator=(const Device&);
    const char* const brand;
    double price;
    double weight;

};
class GSM: virtual public Device
{
public:
    GSM(int cC,int*f,int fc,const char* brand,int t,double p,double w):Device(b,t,p,w),countContacts(cC),
        {
            fcount=fc
            if(fc<0)
            {
                throw "Invalid size";
            }
            ArrayOfFrequency=new int [fcount];
        }
        GSM (const GSM&g):Device(g)
        {
            countContacts=g.countContacts;
            fcount=g.fcount;.....
        }
        ~GSM()
        {
            delete[]ArrayOfFrequency;
        }
private:
    void operator=(const GSM&)//zabranqvame operator =
    int countContacts;
    int fcount;
    int* ArrayOfFrequency;

};
class AudioPlayer: virtual public Device
{
    private:
        int memory;
        char** Formats;
};
class SmartPhone: public AudioPlayer, public GSM
{
public:
    SmartPhone(bool Browser,cosnt char*b,int t,float w........):Device(b,t,w),GSM(int,fr,fr,b,t..),AudioPlayer(....)
    {
        hasBrowser=Browser;
    }
    SmartPhone & operator=(const SmartPhone&S)
    {
        if(&s!=this)
        {
            assert(strcmp(getBrand(),s.getBrand())==0);
            setFreq(S.getFq());
            weight=s.weight;//private
            .......
        }
        return *this;
    }
private:
    void operator=(const SmartPhone &);
    bool hasBrowser;
};
