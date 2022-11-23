#include <Wire.h>
#include "boardcomms.pb.h"
#include "pb_decode.h"
#include <AccelStepper.h>

#define STEPS 200

#define stepsPerRev 200

const int dirPinX = 2;
const int stepPinX = 3;
const int dirPinY = 5;
const int stepPinY = 6;
const int laser_pin = 8;
const int speaker_pin = 9;

const int stepsAllowedX = 100;
const int stepsAllowedY = 150;

volatile int stepsDx = 0;
volatile int stepsDy = 0;
volatile bool update_waiting = false;
volatile bool new_data = false;
int totalStepsX = 0;
int totalStepsY = 0;

int dirX = 0;
int dirY = 0;

uint8_t proto_buffer[CoralToATMega_size];
CoralToATMega rx_proto_msg = CoralToATMega_init_zero;
void handle_coms();

//AccelStepper stepperX(1, stepPinX, dirPinX);
//AccelStepper stepperY(1, stepPinY, dirPinY);


extern 
void setup()
{
  Wire.begin(GardianI2C_ATMEGA);                // join i2c bus with address 0xbeef
  Wire.onReceive(handle_coms); // register event
  Serial.begin(9600);           // start serial for output

  // put your setup code here, to run once:
  pinMode(laser_pin, OUTPUT);
//  digitalWrite(laser_pin,HIGH);
  pinMode(speaker_pin, OUTPUT);
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);

  //configure stepper
//  stepperX.setMaxSpeed(2000);
//  stepperX.setAcceleration(50);
//  stepperX.setSpeed(200);
//  stepperX.moveTo(200);
}


void move_y_stepper(int dy){
  digitalWrite(laser_pin,LOW);
  totalStepsY += dirY;
  if (dy!=0){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(750);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(750);
  }
    
}

void move_x_stepper(int dx){
  digitalWrite(laser_pin,HIGH);
  totalStepsX += dirX;
  if (dx!=0){
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(750);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(750);
  }
}

volatile int readBufIter = 0;

void loop()
{
//  if(new_data && 1<Wire.available()){
//    proto_buffer[readBufIter++] = Wire.read();
////    Serial.println(readBufIter);
//
//    // done reading
//    if(1 == Wire.available()){
//      proto_buffer[readBufIter] = Wire.read();
//      pb_istream_t stream = pb_istream_from_buffer(proto_buffer, readBufIter+1);
//      bool status = pb_decode(&stream, CoralToATMega_fields, &rx_proto_msg);
//      readBufIter = 0;
//      if (!status)
//      {
////        Serial.print("Decoding failed: ");
//        Serial.println(PB_GET_ERROR(&stream));
//        return 1;
//      }
//      else{
////        Serial.println("\nDecoding success: ");
////        print_rx_proto();
//        update_waiting = true;
//    
//        int dy = rx_proto_msg.dy;
//        int dx = rx_proto_msg.dx;
//        
//        if (dx!=0)
//          digitalWrite(dirPinX, dx > 0 ? HIGH : LOW);
//        if (dy!=0)
//          digitalWrite(dirPinY, dy > 0 ? HIGH : LOW);
//    
//        dirX = dx > 0 ? 1 : -1;
//        dirY = dy > 0 ? 1 : -1;
//        
//        rx_proto_msg.dy=abs(dy);
//        rx_proto_msg.dx=abs(dx);
//    
////        print_rx_proto();
//    
//      }
//      new_data = false;
//    }
//  }
  if(update_waiting){
    if(rx_proto_msg.dx>0 ){
      move_x_stepper(1);
      --rx_proto_msg.dx;
    }
    if(rx_proto_msg.dy>0 ){
      move_y_stepper(1);
      --rx_proto_msg.dy;
    }
    update_waiting = !(rx_proto_msg.dy==0 && rx_proto_msg.dx==0);
  }
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

void handle_coms()
{
  new_data = true;
  int iter = 0;
  while(1 < Wire.available()) 
  {
    proto_buffer[iter++] = Wire.read();
//    Serial.println(iter);
  }
  proto_buffer[iter] = Wire.read();
  pb_istream_t stream = pb_istream_from_buffer(proto_buffer, iter+1);
  bool status = pb_decode(&stream, CoralToATMega_fields, &rx_proto_msg);

  if (!status)
  {
//    Serial.print("Decoding failed: ");
    Serial.println(PB_GET_ERROR(&stream));
    return 1;
  }
  else{
//    Serial.println("\nDecoding success: ");
    print_rx_proto();
    
    update_waiting = true;

    int dy = rx_proto_msg.dy;
    int dx = rx_proto_msg.dx;

//    Serial.println(dy > 0);
    
    if (dx!=0)
      digitalWrite(dirPinX, dx > 0 ? HIGH : LOW);
    if (dy!=0)
      digitalWrite(dirPinY, dy > 0 ? HIGH : LOW);

   
    dirX = dx > 0 ? 1 : -1;
    dirY = dy > 0 ? 1 : -1;
    
    rx_proto_msg.dy=abs(dy);
    rx_proto_msg.dx=abs(dx);

//    print_rx_proto();

   
  }
}
