#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>

using namespace std;

/*

*/

class Logger
{
    public:
        // статична член-функция, която се грижи да създаде
        // единствената инстанция на класа, връща нейн псевдоним
        static Logger& getInstance();

        // нестатични член-функции, който могат да бъдат извикани
        // с псевдонима на единствения обект, който създаваме с getInstance()
        bool openFile(const char*);
        bool writeInFile(const char*);
        void closeFile();

    private:
        // конструкторът, копиращия конструктор и операцията за присвояване
        // са обявени в private частта, следователно не можем да създадем
        // обект от този клас във външна функция
        //единственото място, от което се извиква конструктора е
        // статичната член-функция getInstance()
        Logger();

        // скрит, за да не може да се използва за създаване на обект
        Logger(const Logger&);
        Logger& operator=(const Logger&);

        ~Logger();

        // единствена член-данна, потокът, който ще бъде свързан с изходния файл
        ofstream logFileStream;
};

#endif // LOGGER_H
