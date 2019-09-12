#include <QCoreApplication>
#include <iostream>
#include "conveyer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Conveyer conveyer;
//    try {
        conveyer.loadRandomValuesInConveyer();
//    }
//    catch (exception &e) {
//      std::cout << e.what() << std::endl;
//    }
    std::cout << "Conveyer:" << std::endl << conveyer << std::endl;

    std::cout << std::endl << "PushA(4), popping value: " << conveyer.PushA(4) << std::endl;

    std::cout << "New conveyer:" << std::endl << conveyer << std::endl;

    std::cout << std::endl << "PushA(7), popping value: " << conveyer.PushA(7) << std::endl;

    std::cout << "New conveyer:" << std::endl << conveyer << std::endl;

    std::cout << std::endl << "PushB(2), popping value: " << conveyer.PushB(2) << std::endl;

    std::cout << "New conveyer:" << std::endl << conveyer << std::endl;

    return a.exec();
}
