#ifndef ELECTRICALAPPLIANCE_H
#define ELECTRICALAPPLIANCE_H

// състояние на ел. уред
enum State
{
    TURN_OFF, TURN_ON
};

class ElectricalAppliance
{
    public:
        // конструктор с подразбиращи се параметри
        ElectricalAppliance(const char* = "", State = TURN_OFF, double = 0);
        // конструктор за копиране
        ElectricalAppliance(const ElectricalAppliance&);
        // предефиниране на операцията за присвояване
        ElectricalAppliance& operator=(const ElectricalAppliance&);
        // деструктор
        ~ElectricalAppliance();

        // селектори
        const char* getCategory() const
        {
            return _category;
        }

        State getState() const
        {
            return _state;
        }

        double getPower() const
        {
            return _power;
        }

        // статични член-функции
        static double getCurrentLoad()
        {
            return _currentLoad;
        }

        static double getSystemPotentialDifference()
        {
            return POTENTIAL_DIFFERENCE;
        }

        static double getMaxElectricCurrent()
        {
            return MAX_EL_CURRENT;
        }

        static double getAcceptableLoad()
        {
            return ACCEPTABLE_LOAD;
        }

        // мутатори
        void setState(State);

    private:
        // категория на ел. уред
        char* _category;
        // състояние: включен или изключен
        State _state;
        // мощност на ел. уред W
        double _power;

        // помощна член-функция, която се грижи за заделянето на памет
        // за член-данната category и инизиализиране на останалите ел.
        void initData(const char*, State, double);

        // P (мощност) = I (силата на тока) * U (напрежението)
        // напрежението на ел. инсталация, V
        // константна член-данна, инициализира се веднага след деклариране
        const static double POTENTIAL_DIFFERENCE = 220;
        // максимална сила на тока, A
        // характеристиката на бушона в ел. инсталацията
        const static double MAX_EL_CURRENT = 16;

        // допустимо натоварване на системата, W
        // изчислява се като произведение на максималната сила и напрежението
        const static double ACCEPTABLE_LOAD;

        // статична влен-данна, в която се натрупва мощността на
        // включените ел. уреди, не бива да надвишава ACCEPTABLE_LOAD
        static double _currentLoad;
};

#endif // ELECTRICALAPPLIANCE_H
