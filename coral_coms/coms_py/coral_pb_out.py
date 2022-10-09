from periphery import GPIO

led = GPIO("/dev/gpiochip0", 11, "out")

try:
    while True:
        led.write(True)
finally:
    led.write(False)
    led.close()


