#ifndef ELECTRICALAPPLIANCE_H
#define ELECTRICALAPPLIANCE_H

// ��������� �� ��. ����
enum State
{
    TURN_OFF, TURN_ON
};

class ElectricalAppliance
{
    public:
        // ����������� � ������������ �� ���������
        ElectricalAppliance(const char* = "", State = TURN_OFF, double = 0);
        // ����������� �� ��������
        ElectricalAppliance(const ElectricalAppliance&);
        // ������������� �� ���������� �� �����������
        ElectricalAppliance& operator=(const ElectricalAppliance&);
        // ����������
        ~ElectricalAppliance();

        // ���������
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

        // �������� ����-�������
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

        // ��������
        void setState(State);

    private:
        // ��������� �� ��. ����
        char* _category;
        // ���������: ������� ��� ��������
        State _state;
        // ������� �� ��. ���� W
        double _power;

        // ������� ����-�������, ����� �� ����� �� ���������� �� �����
        // �� ����-������� category � �������������� �� ���������� ��.
        void initData(const char*, State, double);

        // P (�������) = I (������ �� ����) * U (������������)
        // ������������ �� ��. ����������, V
        // ���������� ����-�����, ������������ �� ������� ���� �����������
        const static double POTENTIAL_DIFFERENCE = 220;
        // ���������� ���� �� ����, A
        // ���������������� �� ������ � ��. ������������
        const static double MAX_EL_CURRENT = 16;

        // ��������� ����������� �� ���������, W
        // ��������� �� ���� ������������ �� ������������ ���� � ������������
        const static double ACCEPTABLE_LOAD;

        // �������� ����-�����, � ����� �� �������� ��������� ��
        // ���������� ��. �����, �� ���� �� ��������� ACCEPTABLE_LOAD
        static double _currentLoad;
};

#endif // ELECTRICALAPPLIANCE_H
