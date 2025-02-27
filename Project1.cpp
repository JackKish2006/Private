#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string unit;
    double alpha, muzzle_velocity, target_distance;   
    cout << "Enter units (feet or meters): ";
    cin >> unit;
    while (unit != "feet" && unit != "meters") 
    cout << "Enter muzzle velocity: ";
    cin >> muzzle_velocity;
    cout << "Enter target distance: ";
    cin >> target_distance;  
    if (unit == "feet") 
    {
        muzzle_velocity *= 0.3048;
        target_distance *= 0.3048;
    }  
    double g = 9.81;
    double alpha_rad = 45.0 * (3.14159 / 180.0);
    double h_max = (muzzle_velocity * muzzle_velocity * sin(alpha_rad) * sin(alpha_rad)) / (2 * g);
    double flight_time = (2 * muzzle_velocity * sin(alpha_rad)) / g;
    double x_distance = (muzzle_velocity * muzzle_velocity * sin(2 * alpha_rad)) / g;
    double max_range = x_distance;
    bool within_range = target_distance <= max_range; 
    cout << "\nFlight time: " << flight_time << " seconds" << endl;
    cout << "Maximum height: " << h_max << " meters (" << h_max * 3.28 << " feet)" << endl;
    cout << "Horizontal distance: " << x_distance << " meters (" << x_distance * 3.28 << " feet)" << endl;
    cout << "Maximum range: " << max_range << " meters (" << max_range * 3.28 << " feet)" << endl;
    return 0;
}
