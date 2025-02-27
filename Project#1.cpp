#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    string unit;
    double alpha, muzzle_velocity, target_distance;
// user inputs units   
    cout << "Enter units (feet or meters): ";
    cin >> unit;
    if (unit == "feet") 
    {
        muzzle_velocity *= 0.3048;
        target_distance *= 0.3048;
    }
    else if (unit == "meters")
    {
       //This is just feet from above converted to meters
        muzzle_velocity *= 3.28;
        target_distance *= 3.28;
    }
//user enters the velocity (v_0) muzzle launches at
    cout << "Enter muzzle velocity: ";
    cin >> muzzle_velocity;
//user gives the distance of the target for program to check if it is in the max distance 
    cout << "Enter target distance: ";
    cin >> target_distance;
//user gives muzzle launch angle 
    cout << "Enter muzzle angle: ";
    cin >> alpha;

    //this is gravity
    double g = 9.81;
    double alpha_rad = 45.0 * (3.14159 / 180.0);
    //Starting with max height using the equation (Muzzle Velocity (V) V^2*(sin^2(alpha)/2*g))
    double h_max = (muzzle_velocity * muzzle_velocity * sin(alpha_rad) * sin(alpha_rad)) / (2 * g);
    //Flight time equation (2* Muzzle velocity*(sin(alpha)/g))
    double flight_time = (2 * muzzle_velocity * sin(alpha_rad)) / g;
    //distance traveled given by (V^2*sin(2*alpha)/g)
    double x_distance = (((muzzle_velocity * muzzle_velocity) * sin(2 * alpha_rad)) / g);
    // the max range is also given by the same equation as the distance traveled but at an optimal launch angle of 45 degrees
    double max_range = (((muzzle_velocity * muzzle_velocity) * sin(2 * 45.0 * alpha_rad )) / g);
    //if the enterd target range is within the max range
    bool within_range = target_distance <= max_range;

    cout << "\nFlight time: " << flight_time << " seconds" << endl;
    cout << "Maximum height: " << h_max << " meters (" << h_max * 3.28 << " feet)" << endl;
    cout << "Horizontal distance: " << x_distance << " meters (" << x_distance * 3.28 << " feet)" << endl;
    cout << "Maximum range: " << max_range << " meters (" << max_range * 3.28 << " feet)" << endl;
    
    if (target_distance <= max_range) 
    {
        cout << "Target is in range." << endl;
    }
    else 
    {
        cout << "Target is out of range." << endl;
    }
    
    return 0;
}
