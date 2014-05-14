#include "CString.h"
#include <string.h>


using namespace std;

// инициализиране на статичната член-данна
// извън тялото (декларацията) на класа
int String::countStrings = 0;

// конструктор с подразбиращи се стойности
String::String(const char* otherString)
{
    setData(otherString);
    // увеличаваме стойността на статичната член-данна,
    // в която пазим броя на създадените обекти
    countStrings++;
}

// конструктор за копиране
String::String(const String& other)
{
    // отново трябва да се задели памет за член-данните,
    // в тях се копират съответните стойности от other
    setData(other.stringValue);
    // работим във функция, която е член на класа,
    // тук имаме достъп до елементите в private частта

    // увеличаваме стойността на статичната член-данна,
    // в която пазим броя на създадените обекти
    countStrings++;
}

// предефиниране на оператор за присвояване
String& String::operator=(const String& other)
{
     // тук обектът вече е създаден, заделена е памет за неговите член-данни
    // this e указател към текущия обект
    if(&other != this)
    {
        // ако текущият обект (лявата страна на оператора =) е различен от
        // other (обекта в дясната страна на оператора), т.е.
        // не се опитаваме да напраавим самоприсояване (а = а)

        // първо трябва да освободим паметта, която се заема в момента
        delete [] stringValue;
        setData(other.stringValue);
    }

    // връщаме текущия обект
    return *this;
}

// предефиниране на оператор за присвояване, който получава
// като входен параметър const char*
String& String::operator=(const char* otherValue)
{
    // тук обектът вече е създаден, заделена е памет за неговите член-данни
    // първо трябва да освободим паметта, която се заема в момента
    delete [] stringValue;
    setData(otherValue);

    // връщаме текущия обект
    return *this;
}

String::~String()
{
    // освобождава динамичната памет
    delete [] stringValue;
    // намаляваме стойността на статичната член-данна,
    // в която пазим броя на създадените обекти
    countStrings--;
}

// помощна член-функция, която се грижи за заделянето на памет
void String::setData(const char* otherString)
{
    // намираме дължината на подадения стринг
    length = strlen(otherString);
    // зададеляме необходимата памет,
    // + 1, заради символа '\0'
    stringValue = new char[length + 1];
    strcpy(stringValue, otherString);
}

// предефиниране на операциите за индексиране []
// можем да променяме стойността на посочения елемент
// извиква се с неконстантен обект на класа
char& String::operator [](int index)
{
     // дали index е валиден индекс?
    if(index < 0 || index >= length)
    {
        cout << "The index is out of range!" << endl;
        index = 0;
    }

    // връщаме псевдоним на елемента
    return stringValue[index];
}

// връщаме const псевдоним, т.е. елемента не може да се променя
// извиква се с константен обект от класа
const char& String::operator [] (int index) const
{
    // дали index е валиден индекс?
    if(index < 0 || index >= length)
    {
        cout << "The index is out of range!" << endl;
        index = 0;
    }

    return stringValue[index];
}

// предефиниране на операциите + и +=
const String String::operator + (const String& other) const
{
    String result(*this);
    result += other;

    return result;
}

String& String::operator += (const String& other)
{
    // определяме новата дължина на стринга
    int len = length + other.length;
    // временно заделяме памет, в която да натрупаме двата стринга
    char* temp = new char[len + 1];

    // копираме последователно левия и десния стринг
    strcpy(temp, stringValue);
    strcpy(temp + length, other.stringValue);

    // освобождаваме паметта, с която е свързан текущия обект
    delete [] stringValue;

    // присвояваме нови стойности на член-данните
    stringValue = temp;
    length = len;

    return *this;
}

// предефиниране на операцията (), за да реализираме
// връщане на подниз от опреденена позиция с определен брой символи
String String::operator ()(int position, int len) const
{
    // валидация на входните аргументи
    if(position < 0 || position >= length || len <= 0)
        return ""; // ще се включи конструктора на класа, за да създаде необходимия обект
        // неявно преобразуване

    // изчисляване дължината на подниза
    // ако имаме низ с дължина 5 ("абвгд") и искаме да намерим подниз
    // от позиция 2 с дължина 4, 2 + 4 > 5 => можем да копираме само ел. до индекс
    // length - 1, т.е. броя символи е (length - 1) - position + 1 = length - position
    if(position + len > length)
        len = length - position;

    // временно заделяме памет, в която да натрупаме двата стринга
    char* temp = new char[len + 1];

    // копираме len наброй символа, от позиция position в temp
    strncpy(temp, stringValue + position, len);
    temp[len] = '\0';

    // създаваме нов обект, който да върнем като резултат
    String result(temp);

    // освобождаваме временната памет
    delete [] temp;

    return result;
}

// предефиниране на операцията за преобразуване на стринг до масив от символи
String::operator const char*() const
{
    return stringValue;
}

// сравнения между два стринга
// връща истина, ако текущия стринг е преди подадения като параметър,
// сравнението е лексикографско
bool String::operator < (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) < 0;
}

// връща истина, ако текущия стринг е равен на подадения като параметър,
// сравнението е лексикографско
bool String::operator == (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) == 0;
}

// връща истина, ако текущия стринг е след подадения като параметър,
// сравнението е лексикографско
bool String::operator > (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) > 0;
}

// връща истина, ако текущия стринг е различен от подадения като параметър,
// сравнението е лексикографско
bool String::operator != (const String& other) const
{
    return !(*this == other);
}

// извеждане на стринга
// предефиниране на оператора <<, използване на приятелска функция
ostream& operator << (ostream& out, const String& str)
{
    out << str.stringValue;
    return out;
}

// прочитане на стринга от стандартния вход,
// резултатът се записва във втория параметър
istream& operator >> (istream& in, String& str)
{
    // временен масив, в който да прочетем данните
    char temp[String::CIN_LIMIT];
    // четем от стандартния вход най-много CIN_LIMIT символа
    // или до срещането на символа за нов ред
    in.getline(temp, String::CIN_LIMIT, '\n');
    // ако четенето е успешно
    if(in)
    {
        // включва се предефинираната операция за присвояване
        str = temp;
    }

    // връщаме псевдоним на потока, от който четем
    // можем да извършваме каскадни четения
    return in;
}

// статична член-функция, която връща броя на създадените обекти
int String::getCountStrings()
{
    // статичните методи не се обявяват за константни,
    // константността е свързана с указателя this, а
    // статичните методи могат да не се извикват с конкретен обект,
    // а с името на класа::
    return countStrings;
}
