#include <PKAE_Timer.h>

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

//==========================================================================================================
// SETUP                                                                                                   |
//==========================================================================================================
void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(115200);

}


//==========================================================================================================
// LOOP                                                                                                    |
//==========================================================================================================
void loop() {

  PKAE_Timer LED1_Flash(100), LED2_Flash(300), LED3_Flash(500), LED4_Flash(1000), ShowCount(3000);
  boolean LED1_State = LOW, LED2_State = LOW, LED3_State = LOW, LED4_State = LOW;


  while (true) {

    if (LED1_Flash.IsTimeUp()) {
      LED1_State = !LED1_State;
      digitalWrite(LED1, LED1_State);
    }

    if (LED2_Flash.IsTimeUp()) {
      LED2_State = !LED2_State;
      digitalWrite(LED2, LED2_State);
    }

    if (LED3_Flash.IsTimeUp()) {
      LED3_State = !LED3_State;
      digitalWrite(LED3, LED3_State);
    }

    if (LED4_Flash.IsTimeUp()) {
      LED4_State = !LED4_State;
      digitalWrite(LED4, LED4_State);
    }
    if (ShowCount.IsTimeUp()) {
        Serial.print ("Count 1 = ");  Serial.print   (LED1_Flash.nCount);
        Serial.print ("  Count 2 = ");Serial.print   (LED2_Flash.nCount);
        Serial.print ("  Count 3 = ");Serial.print   (LED3_Flash.nCount);
        Serial.print ("  Count 4 = ");Serial.println (LED4_Flash.nCount);
    }
  }
}
