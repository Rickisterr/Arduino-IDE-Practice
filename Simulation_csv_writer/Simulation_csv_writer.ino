/* ==========================================================================
CSLV Simulation CSV file writer code

This code is purposed to write increasing values of simulted sensor data for
the simulation run of the Ground Control System

The sensor values have been increased each second by one so the graph for the
simulation inputs should be a linear curve sloping upwards. This comment is 
to enable checking of a proper simulation run.
=============================================================================*/

#include <EEPROM.h>

// structure array to contain all the elements to be inputter
struct SimData {
  int Stage;          // stage of the rocket in its flight path
  int Missiontime;    // mission time in seconds here
  float Pressure;     // pressure data
  float Altitude;     // altitude data
  float Temperature;  // temperature data
  float Velocity;     // instantaneous velocity data
  float Accel_Y;      // accelerometer yaw
  float Accel_P;      // accelerometer pitch
  float Accel_R;      // accelerometer roll
  float Magnet_Y;     // magnetometer yaw
  float Magnet_P;     // magnetometer pitch
  float Magnet_R;     // magnetometer roll
  float Gyro_Y;       // gyrometer yaw
  float Gyro_P;       // gyrometer pitch
  float Gyro_R;       // gyrometer roll
};

struct SimData Data;
float prev_Altitude = 0.0;                            // variable storing the previous altitude reading each iteration for velocity calculation

void updateData() {
  prev_Altitude = Data.Altitude;
  Data.Missiontime += 1;                              // Mission time increases by 1 second
  Data.Pressure += 10.00;                             // Pressure increases by 10 units
  Data.Altitude = Data.Pressure;    // Actual formula being used to convert Pressure to Altitude yet to be written ********
  Data.Temperature = Data.Altitude; // Actual formula being used to convert Altitude to Temperature yet to be written *******
  Data.Velocity = Data.Altitude - prev_Altitude;      // Velocity calculation done per second of mission
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Started simulated telemetry");

  // setting initial values for data at setup
  Data.Accel_Y = 0.0;
  Data.Accel_P = 0.0;
  Data.Accel_R = 0.0;
  Data.Magnet_Y = 0.0;
  Data.Magnet_P = 0.0;
  Data.Magnet_R = 0.0;
  Data.Gyro_Y = 0.0;
  Data.Gyro_P = 0.0;
  Data.Gyro_R = 0.0;
  Data.Stage = 0;
  Data.Missiontime = 0;
  Data.Pressure = 1013.00;
  Data.Altitude = 0.0;
  Data.Temperature = 0;
  Data.Velocity = 0.0;
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
}
