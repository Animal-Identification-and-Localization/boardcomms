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


# if 0:
#     # led = GPIO("/dev/gpiochip0", 22 ,"out") 
#     led = GPIO(
#         "/dev/gpiochip0", 22, 
#         "out", edge='none', 
#         bias='default', drive='open_source', 
#         inverted=True, label=None
#     )

#     # led = SysfsGPIO(409,"low") 

#     try:
#             # if led.read(): print("High")
#         while True:
#             led.write(False)
#             time.sleep(2)
#             led.write(True)
#             time.sleep(2)


#             # print('hi')
#     finally:
#         led.write(False)
#         led.close()

def send_dx_dy(dx:int, dy:int, i2c="/dev/i2c-3"):
    i2c1 = I2C(i2c)
    # Read byte at address 0x100 of EEPROM at 0x50

    msg = boardcomms_pb2.CoralToATMega()
    msg.message_type = boardcomms_pb2.DXDY
    msg.dx = dx
    msg.dy = dy

    msg_str = msg.SerializeToString()

    msgs = [I2C.Message(msg_str), I2C.Message([0x00], read=True)]
    i2c1.transfer(boardcomms_pb2.ATMEGA, msgs)
    i2c1.close()
