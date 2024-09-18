#include "videocapture.hpp"
#include "sensorcapture.hpp"

#include <iostream>
#include <iomanip>

#include <opencv2/opencv.hpp>
// <---- Includes
int main(int argc, char *argv[])
{
    // ----> Silence unused warning
    (void)argc;
    (void)argv;
sl_oc::video::VideoCapture cap;
cap.initializeVideo();
const sl_oc::video::Frame frame = cap.getLastFrame();
sl_oc::sensors::SensorCapture sens;
std::vector<int> devs = sens.getDeviceList();
sens.initializeSensors( devs[0] );
const sl_oc::sensors::data::Imu imuData = sens.getLastIMUData(5000);
const sl_oc::sensors::data::Magnetometer magData = sens.getLastMagnetometerData(100);
const sl_oc::sensors::data::Environment envData = sens.getLastEnvironmentData(100);
const sl_oc::sensors::data::Temperature tempData = sens.getLastCameraTemperatureData(100);
std::cout << "**** New IMU data ****" << std::endl;
std::cout << " * Timestamp: " << imuData.timestamp << " nsec" << std::endl;
std::cout << " * Accelerations [m/s²]: " << imuData.aX << " " << imuData.aY << " " << imuData.aZ << std::endl;
std::cout << " * Angular Velocities [°/s]: " << imuData.gX << " " << imuData.gY << " " << imuData.gZ << std::endl;
}
