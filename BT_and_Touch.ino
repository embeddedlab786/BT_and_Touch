#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7); // RX, TX
#include <EEPROM.h>

char bt_data; // variable to receive data from the serial port

int relay1 = 5;
int relay2 = 4;
int relay3 = 3;
int relay4 = 2;

int L1, L2, L3, L4, stop=0;

int touch1 = A0;
int touch2 = A1;
int touch3 = A2;
int touch4 = A3;


void setup() {
L1 = EEPROM.read(1);
L2 = EEPROM.read(2);
L3 = EEPROM.read(3);
L4 = EEPROM.read(4);

pinMode(touch1, INPUT);
pinMode(touch2, INPUT);
pinMode(touch3, INPUT);
pinMode(touch4, INPUT);

pinMode(relay1, OUTPUT); digitalWrite(relay1, L1); 
pinMode(relay2, OUTPUT); digitalWrite(relay2, L2);
pinMode(relay3, OUTPUT); digitalWrite(relay3, L3);
pinMode(relay4, OUTPUT); digitalWrite(relay4, L4);

mySerial.begin(9600); // start serial communication at 9600bps
delay(500);
}

void loop() {
  
if(mySerial.available()>0){bt_data = mySerial.read();}

if(bt_data == 'a'){L1=1;EEPROM.write(1, L1);}
if(bt_data == 'A'){L1=0;EEPROM.write(1, L1);}

if(bt_data == 'b'){L2=1;EEPROM.write(2, L2);}
if(bt_data == 'B'){L2=0;EEPROM.write(2, L2);}

if(bt_data == 'c'){L3=1;EEPROM.write(3, L3);}
if(bt_data == 'C'){L3=0;EEPROM.write(3, L3);}

if(bt_data == 'd'){L4=1;EEPROM.write(4, L4);}
if(bt_data == 'D'){L4=0;EEPROM.write(4, L4);}

bt_data='0';

if (digitalRead (touch1) == 1 && stop==0){stop=1; 
L1 = L1+1;
if(L1>1){L1=0;} 
EEPROM.write(1, L1);
delay(100);
}


if (digitalRead (touch2) == 1 && stop==0){stop=1; 
L2 = L2+1;
if(L2>1){L2=0;}
EEPROM.write(2, L2);
delay(100);
}

if (digitalRead (touch3) == 1 && stop==0){stop=1; 
L3 = L3+1;
if(L3>1){L3=0;}
EEPROM.write(3, L3);
delay(100);
}

if (digitalRead (touch4) == 1 && stop==0){stop=1; 
L4 = L4+1;
if(L4>1){L4=0;}
EEPROM.write(4, L4);
delay(100);
}


if (digitalRead (touch1) == 0 && digitalRead (touch2) == 0 && digitalRead (touch3) == 0 && digitalRead (touch4) == 0){stop=0;}

digitalWrite(relay1, L1);
digitalWrite(relay2, L2);
digitalWrite(relay3, L3);
digitalWrite(relay4, L4);
delay(100);
}
