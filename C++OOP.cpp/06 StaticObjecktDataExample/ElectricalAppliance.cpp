#include "ElectricalAppliance.h"

#include <iostream>
#include <cstring>

using namespace std;

// �������������� �� ���������� ����-�����
const double ElectricalAppliance::ACCEPTABLE_LOAD =
    ElectricalAppliance::POTENTIAL_DIFFERENCE * ElectricalAppliance::MAX_EL_CURRENT;

double ElectricalAppliance::_currentLoad = 0.0;

 // ����������� � ������������ �� ���������
ElectricalAppliance::ElectricalAppliance(const char* category, State state, double power) : _state(TURN_OFF)
{
    initData(category, state, power);
}

// ����������� �� ��������
ElectricalAppliance::ElectricalAppliance(const ElectricalAppliance& other) : _state(TURN_OFF)
{
    initData(other._category, other._state, other._power);
}

// ������������� �� ���������� �� �����������
ElectricalAppliance& ElectricalAppliance::operator=(const ElectricalAppliance& other)
{
    if(&other != this)
    {
        delete [] _category;

        initData(other._category, other._state, other._power);
    }

    return *this;
}

// ����������
ElectricalAppliance::~ElectricalAppliance()
{
    delete [] _category;

    // ��� ������ � ��� �������
    // ������ �� ������� �������� ������� �� ��������
    // ����������� �� ���������
    if(_state == TURN_ON)
    {
        _currentLoad -= _power;
    }
}

// ��������
// ��������� ����������� �� �����, ���������
void ElectricalAppliance::setState(State state)
{
    if(state == TURN_OFF || state == TURN_ON)
    {
        // ��� ��� ������ ������� ���������
        if (_state == TURN_OFF && state == TURN_ON)
        {
            // ��� ������ � ��� �������� � ���� �� ���������
            // ������ �� ������� �������� ������� ��� ��������
            // ����������� �� ���������

            // ����������� � ��������� ������ �� �����, ����
            // ��� �� ������������ ���������
            if(_currentLoad + _power < ACCEPTABLE_LOAD)
            {
                _currentLoad += _power;
            }
            else
            {
                // ����������� ����������� ����������� �� ���������
                cout << "You'll exceed the acceptable load for the system!" << endl;
                _state = TURN_OFF;
                // �������� �� ��������� ��� �� ��������� �����������
                return;
            }
        }
        else if(_state == TURN_ON && state == TURN_OFF)
        {
            // ��� ������ � ��� ������� � ���� �� ����������
            // ������ �� ������� �������� ������� �� ��������
            // ����������� �� ���������
            _currentLoad -= _power;
        }

         // ��������� �����������
         _state = state;
    }
//    else
//    {
//        // �������� � ���� ����� ����������� �� ��������� ��� State
//        // ���� �� ��������� �����������
//    }
}

// ������� ����-�������, ����� �� ����� �� ���������� �� �����
// �� ����-������� category � ������� ��������������
void ElectricalAppliance::initData(const char* category, State state, double power)
{
    // �������������� �� ����������� ����-�����
    _category = new char[strlen(category) + 1];
    strcpy(_category, category);

    // �������������� �� ���������, ����� �����������
    _power = (power > 0)? power : 0.0;

    // �������������� �� �����������
    setState(state);
}
