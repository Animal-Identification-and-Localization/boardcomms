# from periphery import GPIO

# led = GPIO("/dev/gpiochip0", line=11, direction="out", bias="pull_up")

# try:
#     while True:
#         led.write(True)
# finally:
#     led.write(False)
#     led.close()

from periphery import SysfsGPIO
from periphery import GPIO
import time
import boardcomms_pb2



# led = GPIO("/dev/gpiochip0", 22 ,"out") 
led = GPIO(
    "/dev/gpiochip0", 22, 
    "out", edge='none', 
    bias='default', drive='open_source', 
    inverted=True, label=None
)

# led = SysfsGPIO(409,"low") 

try:
        # if led.read(): print("High")
    while True:
        led.write(False)
        time.sleep(2)
        led.write(True)
        time.sleep(2)


        # print('hi')
finally:
    led.write(False)
    led.close()



