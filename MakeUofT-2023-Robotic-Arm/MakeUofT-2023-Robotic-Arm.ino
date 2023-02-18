#include <Servo.h>

Servo servo4; //base roation
Servo servo2; //base extension 
Servo servo3; //arm extension 

//servo postions 

//servo 4
int s4pos1 =0; //start pos
int s4pos2 =0; //end pos


//servo3

int toggle = 5; //robot on/off swtich

int servo_position = 0;    //servo position
 
void setup() {

  //servo motors
  servo4.attach(2);
  servo2.attach(3);
  servo3.attach(4);

  //robot on/off swtich
  pinMode(toggle, INPUT);

  Serial.begin(9600);

}

void servo4CW(int s4pos1, int s4pos2){ //servo4 clock wise rotation
  for (int pos = s4pos1; pos <= s4pos2; pos += 1){
    if (digitalRead(toggle) == LOW) break;
    delay(8);
    servo4.write(pos);
  }
}

void servo4CCW(int s4pos1, int s4pos2){ //servo4 counter clock wise rotation
  for (int pos = s4pos2; pos >= s4pos1; pos -= 1){
    if (digitalRead(toggle) == LOW) break;
    delay(8);
    servo4.write(pos);
  }
}



void loop() {

  while(digitalRead(toggle) == HIGH){

  

  //functions to move servos and take in cords
  
  servo4CW(0, 180);
  delay(200);
  servo4CCW(180, 0);
  delay(200);

  }
}








   
