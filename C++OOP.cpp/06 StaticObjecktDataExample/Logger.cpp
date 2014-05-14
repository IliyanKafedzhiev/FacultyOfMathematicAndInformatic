#include "Logger.h"

// статична член-функция, която се грижи да създаде
// единствената инстанция на класа, връща нейн псевдоним
Logger& Logger::getInstance()
{
    // създава се статичен обект, по време на изпълнение на програмата,
    // при първото извикване на член-функцията
    // този обект съществува, докато не излезем от програмата
    static Logger instance;

    // връщаме псевдоним на този обект
    return instance;
}

Logger::Logger()
{
    cout << "Logger constructor " << endl;

    // на това ниво е извикан подразбиращият се конструктор
    // на класа ostream, потокът не е свързан с файлс
}

Logger::~Logger()
{
    cout << "~Logger destructor " << endl;
    // ще бъде извикан и деструктора на потока
}

// свързване на потока с файл за писане
bool Logger::openFile(const char* fileName)
{
    // свързваме потока с файла, подаден като параметър
    // файлът е отворен за добавяне в края на файла
    logFileStream.open(fileName, ios::ate);

    // връщаме истина, ако файлът е отворен успешно за писане
    return !logFileStream;
}

bool Logger::writeInFile(const char* message)
{
    // записваме съдържанието на съобщението във файла
    logFileStream << message << endl;

    // проверяваме дали писането е успешно
    return !logFileStream;
}

// затваряне на файла
void Logger::closeFile()
{
    logFileStream.close();
}
