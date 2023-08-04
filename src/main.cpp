#include "RobotSimulation.h"
#include <string>
#include <iostream>
#include <limits>

int main() {
    std::cout << "1. Load config from file." << std::endl;
    std::cout << "2. Load config from console." << std::endl;

    int choice;

    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter valid number." << std::endl;
    }

    if (choice == 1) {
        const std::string filePath("..//data//config.txt");
        RobotSimulation robot(filePath);
        robot.StartSimulation();
        robot.MoveTo(3.5f, 2.0f);
        robot.StopSimulation();
    } else if(choice == 2) {
        std::cout << "Enter number of wheels" << std::endl;
        int numberOfWheels;
        std::cin >> numberOfWheels;
        RobotSimulation robot(numberOfWheels);
        robot.StartSimulation();
        robot.MoveTo(3.5f, 2.0f);
        robot.StopSimulation();
    }

    return 0;
}
