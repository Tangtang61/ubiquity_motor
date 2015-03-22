#include <ubiquity_motor/motor_command.h>
#include <ubiquity_motor/motor_serial.h>
#include <gtest/gtest.h>
#include <unistd.h>

TEST(ubiquity_motor_serial, motor_serial) {
	MotorSerial motor_serial("/dev/ttyUSB0", 9600);
	//sleep(1);
	while(!motor_serial.commandAvailable()){
		usleep(100);
	}
	MotorCommand mc = motor_serial.receiveCommand();
	ASSERT_EQ(0x07, mc.getRegister());
}