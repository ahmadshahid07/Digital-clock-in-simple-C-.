#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>  // for system("cls") or system("clear")

using namespace std;

// Function to clear screen depending on OS
void clearScreen() {
#ifdef _WIN32
    system("cls"); // for Windows
#else
    system("clear"); // for Linux/macOS
#endif
}

int main() {
    while (true) {
        clearScreen();  // Clear the console screen

        // Get current time from system (local/landbase time)
        time_t now = time(0);
        tm* localTime = localtime(&now);

        // Display in HH:MM:SS format
        cout << "======================" << endl;
        cout << "     DIGITAL CLOCK    " << endl;
        cout << "======================" << endl;
        cout << "     "
             << setfill('0') << setw(2) << localTime->tm_hour << ":"
             << setfill('0') << setw(2) << localTime->tm_min << ":"
             << setfill('0') << setw(2) << localTime->tm_sec << endl;
        cout << "======================" << endl;

        // Wait for 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}