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

from . import boardcomms_pb2


def send_dx_dy(dx:int, dy:int, i2c, laser_on=False):

    msg = boardcomms_pb2.CoralToATMega()
    msg.message_type = boardcomms_pb2.DXDY
    msg.dx = dx
    msg.dy = dy
    msg.laser_on = laser_on

    msg_str = msg.SerializeToString()

    msgs = [I2C.Message(msg_str), I2C.Message([0x00], read=True)]
    i2c.transfer(boardcomms_pb2.ATMEGA, msgs)
