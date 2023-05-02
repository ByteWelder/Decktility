# I2C Pins:
#   GPIO2 -> SDA
#   GPIO3 -> SCL

from smbus2 import SMBus
import time
import struct

bus = SMBus(1)

deviceAddress = 0x2A
deviceId = 0
header = 42

def requestVbat():
  requestVbat = [header, 1] # request Vbat
  bus.write_block_data(deviceAddress, deviceId, requestVbat)
  data = bytes(bus.read_i2c_block_data(deviceAddress, deviceId, 4))
  return struct.unpack_from('<f', data, 0)[0]

def requestChargingState():
  requestChargingState = [header, 2] # request charge state
  bus.write_block_data(deviceAddress, deviceId, requestChargingState)
  chargingData = bytes(bus.read_i2c_block_data(deviceAddress, deviceId, 1))
  return struct.unpack_from('B', chargingData, 0)[0]

vbat = requestVbat()
print('Vbat: %.2f V' % vbat)

charging = requestChargingState()
if charging:
  print('charging: yes')
else:
  print('charging: no')

bus.close()

