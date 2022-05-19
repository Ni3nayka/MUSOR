import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

class my_button():
    
    def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.IN)
        
    def read(self):
        return GPIO.input(self.pin)