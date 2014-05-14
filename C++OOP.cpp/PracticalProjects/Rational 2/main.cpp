#include <iostream>
#include <cstring>

#include "CString.h"
#include "Rational.h"

using namespace std;

int main()
{
//    String str = "";
//    cout << !str << endl;
//
//    String str1 = "You";
//    cout << str1 << endl;
//
//    if(str < str1)
//    {
//        cout << str << " is before " << str1 << endl;
//    }
//
//    // операци€ за присво€ване
//    str = str1;
//    cout << str << endl;
//
//    String str2;
//    // четене от стандатни€ вход
//    cin >> str2;
//    cout << "STRING READ: " << str2 << endl;
//
//    cout << str2[3] << endl;
//
//    cout << str1 << " + " << str2 << " = " << str1 + str2 << endl;
//    cout << str1 << " += " << str2 << " is " << (str1 += str2) << endl;
//    cout << str1 << "( 1, 3)" << str1(1, 3) << endl;
//
//    // (str1 += str2) += str;
//
//    int x = 5, y = 6;
//    (x -= y) = x;
//    cout << "x = " << x << endl;

    Rational rat;
    cout << rat << endl;

    cout << "Change Rat: ";
    rat.setNumerator(3);
    rat.setDenominator(4);
    cout << rat << endl;

    cout << "5 + " << rat << " = " << 5 + rat << endl;
    cout << "5 - " << rat << " = " << 5 - rat << endl;
    cout << "5 * " << rat << " = " << 5 * rat << endl;
    cout << "5 / " << rat << " = " << 5 / rat << endl;

    Rational other(4, 5);
    cout << other << endl;

    cout << rat << " + " << other << " = " << rat + other << endl;
    cout << rat << " - " << other << " = " << rat - other << endl;
    cout << rat << " * " << other << " = " << rat * other << endl;
    cout << rat << " / " << other << " = " << rat / other << endl;


    return 0;
}
