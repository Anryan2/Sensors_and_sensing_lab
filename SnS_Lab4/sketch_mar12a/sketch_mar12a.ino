#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Variables to hold raw sensor data
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
    Serial.begin(115200);
    
    // Initialize the MPU6050
    Wire.begin();
    mpu.initialize();
    
    // Check for connection
    if (mpu.testConnection()) {
        Serial.println("MPU6050 connection successful");
    } else {
        Serial.println("MPU6050 connection failed");
    }
}

void loop() {
    // Read raw accelerometer and gyroscope data
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    // Print the values to the Serial Monitor
    Serial.print("Accel X: "); Serial.print(ax);
    Serial.print(" | Accel Y: "); Serial.print(ay);
    Serial.print(" | Accel Z: "); Serial.print(az);
    Serial.print(" | Gyro X: "); Serial.print(gx);
    Serial.print(" | Gyro Y: "); Serial.print(gy);
    Serial.print(" | Gyro Z: "); Serial.println(gz);
    
    // Delay for a while to make the output readable
    delay(500);
}