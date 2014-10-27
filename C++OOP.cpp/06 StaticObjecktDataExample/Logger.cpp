#include "Logger.h"

// �������� ����-�������, ����� �� ����� �� �������
// ������������ ��������� �� �����, ����� ���� ���������
Logger& Logger::getInstance()
{
    // ������� �� �������� �����, �� ����� �� ���������� �� ����������,
    // ��� ������� ��������� �� ����-���������
    // ���� ����� ����������, ������ �� ������� �� ����������
    static Logger instance;

    // ������� ��������� �� ���� �����
    return instance;
}

Logger::Logger()
{
    cout << "Logger constructor " << endl;

    // �� ���� ���� � ������� �������������� �� �����������
    // �� ����� ostream, ������� �� � ������� � �����
}

Logger::~Logger()
{
    cout << "~Logger destructor " << endl;
    // �� ���� ������� � ����������� �� ������
}

// ��������� �� ������ � ���� �� ������
bool Logger::openFile(const char* fileName)
{
    // ��������� ������ � �����, ������� ���� ���������
    // ������ � ������� �� �������� � ���� �� �����
    logFileStream.open(fileName, ios::ate);

    // ������� ������, ��� ������ � ������� ������� �� ������
    return !logFileStream;
}

bool Logger::writeInFile(const char* message)
{
    // ��������� ������������ �� ����������� ��� �����
    logFileStream << message << endl;

    // ����������� ���� �������� � �������
    return !logFileStream;
}

// ��������� �� �����
void Logger::closeFile()
{
    logFileStream.close();
}
