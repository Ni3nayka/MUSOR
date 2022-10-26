from device.python_arduino_bluetooth import arduino_bluetooth

if __name__ == "__main__":
    arduino = arduino_bluetooth("20:16:06:23:04:27")
    arduino.start()
    '''
    arduino.write("test - 1")
    arduino.write("test - 2")
    while (1):
        if (arduino.available()):
            print(arduino.read())
    '''