#include <Wire.h>
#include "boardcomms.pb.h"
#include "pb_decode.h"

uint8_t proto_buffer[CoralToATMega_size];
CoralToATMega rx_proto_msg = CoralToATMega_init_zero;

extern 
void setup()
{
  Wire.begin(GardianI2C_ATMEGA);                // join i2c bus with address 0xbeef
  Wire.onReceive(handle_coms); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

void print_rx_proto(){
  Serial.println("_CoralToATMega{");
  Serial.print("\tC2AMsgType message_type = ");
  Serial.println(rx_proto_msg.message_type);
  
  Serial.print("\tbool has_dx = ");
  Serial.println(rx_proto_msg.has_dx);
  Serial.print("\tint32_t dx = ");
  Serial.println(rx_proto_msg.dx);
  
  Serial.print("\tbool has_dy = ");
  Serial.println(rx_proto_msg.has_dy);
  Serial.print("\tint32_t dy = ");
  Serial.println(rx_proto_msg.dy);
  
  Serial.print("\tbool has_pingnum = ");
  Serial.println(rx_proto_msg.has_pingnum);
  Serial.print("\tint32_t pingnum = ");
  Serial.println(rx_proto_msg.pingnum);
  
  Serial.print("\tbool has_laser_on = ");
  Serial.println(rx_proto_msg.has_laser_on);
  Serial.print("\tint32_t laser_on = ");
  Serial.println(rx_proto_msg.laser_on);
  Serial.println("}");
}

void handle_coms(int howMany)
{
  int iter = 0;
  while(1 < Wire.available()) 
  {
    proto_buffer[iter++] = Wire.read();
  }
  proto_buffer[iter] = Wire.read();
  pb_istream_t stream = pb_istream_from_buffer(proto_buffer, iter+1);
  bool status = pb_decode(&stream, CoralToATMega_fields, &rx_proto_msg);
  
  if (!status)
  {
    Serial.print("Decoding failed: ");
    Serial.println(PB_GET_ERROR(&stream));
    return 1;
  }
  else{
    Serial.println("\nDecoding success: ");
    print_rx_proto();
    
//    Serial.print("\tC2AMsgType message_type = ");
//    Serial.println(rx_proto_msg.message_type);
    
  }
}
