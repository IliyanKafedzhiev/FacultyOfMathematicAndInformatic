#include "ElectricalAppliance.h"

#include <iostream>
#include <cstring>

using namespace std;

// Инициализиране на статичнати член-данни
const double ElectricalAppliance::ACCEPTABLE_LOAD =
    ElectricalAppliance::POTENTIAL_DIFFERENCE * ElectricalAppliance::MAX_EL_CURRENT;

double ElectricalAppliance::_currentLoad = 0.0;

 // конструктор с подразбиращи се параметри
ElectricalAppliance::ElectricalAppliance(const char* category, State state, double power) : _state(TURN_OFF)
{
    initData(category, state, power);
}

// конструктор за копиране
ElectricalAppliance::ElectricalAppliance(const ElectricalAppliance& other) : _state(TURN_OFF)
{
    initData(other._category, other._state, other._power);
}

// предефиниране на операцията за присвояване
ElectricalAppliance& ElectricalAppliance::operator=(const ElectricalAppliance& other)
{
    if(&other != this)
    {
        delete [] _category;

        initData(other._category, other._state, other._power);
    }

    return *this;
}

// деструктор
ElectricalAppliance::~ElectricalAppliance()
{
    delete [] _category;

    // ако уредът е бил включен
    // трябва да извадим неговата мощност от текущото
    // натоварване на системата
    if(_state == TURN_ON)
    {
        _currentLoad -= _power;
    }
}

// мутатори
// променяме състоянието на уреда, валидация
void ElectricalAppliance::setState(State state)
{
    if(state == TURN_OFF || state == TURN_ON)
    {
        // ако сме подали валидно състояние
        if (_state == TURN_OFF && state == TURN_ON)
        {
            // ако уредът е бил изключен и сега го включваме
            // трябва да добавим неговата мощност към текущото
            // натоварване на системата

            // включването в системата трябва да стане, само
            // ако не претоварваме системата
            if(_currentLoad + _power < ACCEPTABLE_LOAD)
            {
                _currentLoad += _power;
            }
            else
            {
                // надхвърляме допустимото натоварване на системата
                cout << "You'll exceed the acceptable load for the system!" << endl;
                _state = TURN_OFF;
                // излизаме от функцията без да променяме състоянието
                return;
            }
        }
        else if(_state == TURN_ON && state == TURN_OFF)
        {
            // ако уредът е бил включен и сега го изключваме
            // трябва да извадим неговата мощност от текущото
            // натоварване на системата
            _currentLoad -= _power;
        }

         // Променяме състоянието
         _state = state;
    }
//    else
//    {
//        // подадено е нещо извън стойностите на изброения тип State
//        // няма да променяме състоянието
//    }
}

// помощна член-функция, която се грижи за заделянето на памет
// за член-данната category и нейното инизиализиране
void ElectricalAppliance::initData(const char* category, State state, double power)
{
    // Инициализиране на динамичната член-данна
    _category = new char[strlen(category) + 1];
    strcpy(_category, category);

    // инициализиране на мощността, преди състоянието
    _power = (power > 0)? power : 0.0;

    // инициализиране на състоянието
    setState(state);
}
