#include "NetworkSimulation.h"
#include <iostream>

int main() {
    char user_choice;
    NetworkSimulation simulation;
    std::cout << "Welcome to the Network Simulation Program!" << std::endl;
    do {
        std::cout << "Press 's' to start the process or 'q' to quit: ";
        std::cin >> user_choice;
        if (user_choice == 's') {
            std::cout << "" << std::endl;
            simulation.run_process();
            std::cout << "Process completed!" << std::endl;
        }
        else if (user_choice != 'q') {
            std::cout << "Invalid input, please try again." << std::endl;
        }
    } while (user_choice != 'q');
    std::cout << "Goodbye! Program has offical terminated." << std::endl;
    return 0;
}
