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
from periphery import I2C
import time

import boardcomms_pb2


if 0:
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


i2c1 = I2C("/dev/i2c-3")
# Read byte at address 0x100 of EEPROM at 0x50

msg = boardcomms_pb2.CoralToATMega()
msg.message_type = boardcomms_pb2.DXDY
msg.dx = 30
msg.dy = 20

msg_str = msg.SerializeToString()

print(msg_str)

for i in range(0,101):
    msgs = [I2C.Message(msg_str), I2C.Message([0x00], read=True)]
    i2c1.transfer(boardcomms_pb2.ATMEGA, msgs)

print("0x100: 0x{:02x}".format(msgs[1].data[0]))

i2c1.close()
