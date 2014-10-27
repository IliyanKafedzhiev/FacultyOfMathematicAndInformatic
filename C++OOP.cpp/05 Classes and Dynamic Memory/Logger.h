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
        // �������� ����-�������, ����� �� ����� �� �������
        // ������������ ��������� �� �����, ����� ���� ���������
        static Logger& getInstance();

        // ���������� ����-�������, ����� ����� �� ����� ��������
        // � ���������� �� ����������� �����, ����� ��������� � getInstance()
        bool openFile(const char*);
        bool writeInFile(const char*);
        void closeFile();

    private:
        // �������������, ��������� ����������� � ���������� �� �����������
        // �� ������� � private ������, ������������ �� ����� �� ��������
        // ����� �� ���� ���� ��� ������ �������
        //������������ �����, �� ����� �� ������� ������������ �
        // ���������� ����-������� getInstance()
        Logger();

        // �����, �� �� �� ���� �� �� �������� �� ��������� �� �����
        Logger(const Logger&);
        Logger& operator=(const Logger&);

        ~Logger();

        // ���������� ����-�����, �������, ����� �� ���� ������� � �������� ����
        ofstream logFileStream;
};

#endif // LOGGER_H
