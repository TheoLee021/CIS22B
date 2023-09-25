#include <iostream>
using namespace std;

class Computer {
    public:
        void SetComputerStatus(string cpuStatus, string internetStatus) {
            cpuUsage = cpuStatus;
            internet = internetStatus;
        };

        void PrintStatus() {
            cout << "CPU: " << cpuUsage << endl;
            cout << "Internet: " << internet << endl;
        };

    protected:
        string cpuUsage;
        string internet;
};

class Laptop : public Computer {
    public:
        void SetComputerStatus(string cpuStatus, string internetStatus, string wifiStatus) {
            cpuUsage = cpuStatus;
            internet = internetStatus;
            wifiQuality = wifiStatus;
        };

        void PrintStatus() {
            Computer::PrintStatus();
            cout << "WiFi: " << wifiQuality << endl;
        };

    private:
        string wifiQuality;
};

int main() {
    Laptop myLaptop;

    myLaptop.SetComputerStatus("15%", "connected", "good");
    myLaptop.PrintStatus();

    return 0;
}