#include <iostream>
#include <iomanip>

#include "ElectricalAppliance.h"
#include "Logger.h"

using namespace std;

int main()
{
//    cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;
//    cout << "Acceptable Load: " << ElectricalAppliance::getAcceptableLoad() << endl;
//
//    {
//        ElectricalAppliance tv("TV", TURN_ON, 200);
//        cout << tv.getCategory() << " power: " << tv.getPower() << endl;
//        cout << tv.getCategory() << " state: " << tv.getState() << endl;
//
//        cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;
//
//        ElectricalAppliance airConditioner("Air Conditioner", TURN_ON, 1190);
//        cout << airConditioner.getCategory() << " power: " << airConditioner.getPower() << endl;
//        cout << airConditioner.getCategory() << " state: " << airConditioner.getState() << endl;
//
//        cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;
//
//        ElectricalAppliance airConditioner1 = airConditioner;
//        cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;
//
//        ElectricalAppliance airConditioner2 = airConditioner;
//        cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;
//    }
//
//    cout << "Current Load: " << ElectricalAppliance::getCurrentLoad() << endl;

    Logger& logger = Logger::getInstance();
    logger.openFile("Test.txt");
    logger.writeInFile("Log message into the file..");
    logger.closeFile();

    return 0;
}
