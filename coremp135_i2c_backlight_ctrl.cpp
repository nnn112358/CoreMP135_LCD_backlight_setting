
// Copyright (c) 2024 @nnn112358<https://github.com/nnn112358/>
//$ arm-linux-gnueabihf-g++ coremp135_i2c_backlight_ctrl.cpp -o
//  coremp135_i2c_backlight_ctrl

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <bitset>
#include <iostream>

// Define constants for I2C communication
#define AXP2101_ADDR 0x34
#define AXP2101_REG_DLDO1_CFG 0x99
#define AXP2101_MAX_BACKLIGHT_REG 28  // Max register value for backlight (3.3v

// Main function
int main() {
  int file;                                 // File descriptor for I2C bus
  const char *filename = "/dev/i2c-0";      // I2C bus device file
  int deviceAddress = AXP2101_ADDR;         // I2C device address
  __u8 regAddress = AXP2101_REG_DLDO1_CFG;  // Register address to write to
  unsigned int number;  // Variable to hold the input integer

  // Open the I2C bus
  if ((file = open(filename, O_RDWR)) < 0) {
    std::cerr << "Failed to open the i2c bus" << std::endl;
    return 1;
  }

  // Set the I2C device address
  if (ioctl(file, I2C_SLAVE, deviceAddress) < 0) {
    std::cerr << "Failed to acquire bus access and/or talk to slave."
              << std::endl;
    close(file);
    return 1;
  }

  // Read an unsigned integer from the standard input
  std::cout << "Enter AXP2101 DLDO1 Setting integer: ";
  std::cin >> number;

  // Ensure the number does not exceed the max backlight register value
  if (number > AXP2101_MAX_BACKLIGHT_REG) {
    number = AXP2101_MAX_BACKLIGHT_REG;
  }

  // Display the number in decimal, hexadecimal, and binary formats
  std::cout << "---------------------------" << std::endl;
  std::cout << "AXP2101 DLDO1 Valtage: " << number * 0.1 + 0.5 << "[V]"
            << std::endl;
  std::cout << "Dec: " << number << std::endl;
  std::cout << std::hex << "Hex: " << number << std::endl;
  std::cout << std::dec << "Bi: " << std::bitset<8>(number) << std::endl;
  std::cout << "---------------------------" << std::endl;

  // Write the data to the register
  __u8 buffer[2] = {regAddress, static_cast<__u8>(number)};
  if (write(file, buffer, 2) != 2) {
    std::cerr << "Failed to write to the i2c bus." << std::endl;
    close(file);
    return 1;
  }

  // Close the I2C bus
  close(file);
  std::cout << "Data written successfully." << std::endl;

  return 0;
}
