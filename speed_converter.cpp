#include <iostream>
#include <iomanip>
#include <limits>

class SpeedConverter {
private:
    // Conversion factors
    const double KMH_TO_MS = 0.277778;    // Kilometers per hour to meters per second
    const double KMH_TO_MPH = 0.621371;   // Kilometers per hour to miles per hour
    const double KMH_TO_KNOTS = 0.539957; // Kilometers per hour to knots

public:
    // Convert from kilometers per hour to other units
    double toMetersPerSecond(double kmh) { return kmh * KMH_TO_MS; }
    double toMilesPerHour(double kmh) { return kmh * KMH_TO_MPH; }
    double toKnots(double kmh) { return kmh * KMH_TO_KNOTS; }

    // Convert to kilometers per hour from other units
    double fromMetersPerSecond(double ms) { return ms / KMH_TO_MS; }
    double fromMilesPerHour(double mph) { return mph / KMH_TO_MPH; }
    double fromKnots(double knots) { return knots / KMH_TO_KNOTS; }

    // Clear input buffer
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Display menu
    void displayMenu() {
        std::cout << "\nSpeed Converter Menu:\n";
        std::cout << "1. Convert from Kilometers per hour\n";
        std::cout << "2. Convert to Kilometers per hour\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";
    }

    // Display conversion options
    void displayFromOptions() {
        std::cout << "\nConvert to:\n";
        std::cout << "1. Meters per second\n";
        std::cout << "2. Miles per hour\n";
        std::cout << "3. Knots\n";
        std::cout << "Enter your choice (1-3): ";
    }

    void displayToOptions() {
        std::cout << "\nConvert from:\n";
        std::cout << "1. Meters per second\n";
        std::cout << "2. Miles per hour\n";
        std::cout << "3. Knots\n";
        std::cout << "Enter your choice (1-3): ";
    }

    // Get valid input
    double getValidInput(const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                if (value >= 0) { // Speed cannot be negative
                    return value;
                }
                std::cout << "Error: Speed cannot be negative!\n";
            } else {
                std::cout << "Error: Invalid input! Please enter a number.\n";
                clearInputBuffer();
            }
        }
    }

    // Process conversion from kmh
    void processFromKmh() {
        double speed = getValidInput("Enter speed in kilometers per hour: ");
        displayFromOptions();
        int choice;
        std::cin >> choice;

        std::cout << std::fixed << std::setprecision(2);
        switch (choice) {
            case 1:
                std::cout << speed << " km/h = " << toMetersPerSecond(speed) << " m/s\n";
                break;
            case 2:
                std::cout << speed << " km/h = " << toMilesPerHour(speed) << " mph\n";
                break;
            case 3:
                std::cout << speed << " km/h = " << toKnots(speed) << " knots\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    // Process conversion to kmh
    void processToKmh() {
        displayToOptions();
        int choice;
        std::cin >> choice;

        double result;
        double speed;
        std::cout << std::fixed << std::setprecision(2);

        switch (choice) {
            case 1:
                speed = getValidInput("Enter speed in meters per second: ");
                result = fromMetersPerSecond(speed);
                std::cout << speed << " m/s = " << result << " km/h\n";
                break;
            case 2:
                speed = getValidInput("Enter speed in miles per hour: ");
                result = fromMilesPerHour(speed);
                std::cout << speed << " mph = " << result << " km/h\n";
                break;
            case 3:
                speed = getValidInput("Enter speed in knots: ");
                result = fromKnots(speed);
                std::cout << speed << " knots = " << result << " km/h\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
};

int main() {
    SpeedConverter converter;
    int choice;

    std::cout << "Welcome to Speed Converter!\n";

    while (true) {
        converter.displayMenu();
        if (!(std::cin >> choice)) {
            converter.clearInputBuffer();
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                converter.processFromKmh();
                break;
            case 2:
                converter.processToKmh();
                break;
            case 3:
                std::cout << "Thank you for using Speed Converter!\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please select 1-3.\n";
        }
    }

    return 0;
}