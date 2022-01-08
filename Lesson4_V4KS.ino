int readValue = 0;
int writeValue = 0;
void setup() {
  pinMode(9,OUTPUT);      //Set up Pin 9 for green LED as output
  pinMode(10,OUTPUT);     //Set up Pin 10 for second green LED as output      
  pinMode(11,OUTPUT);     //Set up Pin 11 for third green LED as output
  pinMode(7,OUTPUT);      //declare pin 7 as output (first LED from the top)
  pinMode(6,OUTPUT);      //declare pin 6 as output (second LED)
  pinMode(5,OUTPUT);      //declare pin 5 as output (third LED)
  pinMode(4,INPUT);       //declare pin 2 as input (button)
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(A0);     //Store the value from the potentiometer
  writeValue = readValue / 4;     //Divide the readValue by 4 and store as the writeValue. Read value is in bits and write value is in BYTES.
                                  //From the above equation, if readValue is 1,023 (max bit) then writeValue will be 255 (Max Byte)
  analogWrite(9, writeValue);     //Set LED 1 brightness to writeValue
  analogWrite(10, writeValue);    //Set LED 2 brightness to writeValue
  analogWrite(11, writeValue);    //Set LED 3 brightness to writeValue
  if (readValue < 300) {          //If the value from the potentiomater is less than 300 then:
    digitalWrite(9,LOW);          //Turn off first LED. You could also use analogWrite(pin,0) for same effects on LEDs.
    digitalWrite(10,LOW);         //Turn off second LED. You could also use analogWrite(pin,0) for same effects on LEDs.
    digitalWrite(11,LOW);         //Turn off third LED. You could also use analogWrite(pin,0) for same effects on LEDs.
  }
  else if (readValue < 600) {        //If the value from the potentiometer is less than 600
    analogWrite(9, writeValue);     //Turn on 1st LED
    digitalWrite(10, LOW);         //Turn off 2nd LED
    digitalWrite(11, LOW);         //Turn off 3rd LED
  }
  else if (readValue < 900) {     //If the value from the potentionmeter is less than 900
    analogWrite(9, writeValue);   //Turn on 1st LED
    analogWrite(10, writeValue);  //Turn on 2nd LED
    digitalWrite(11,LOW);         //Turn off 3rd LED
  }
  else {                          //If readValue is greater than 900
    analogWrite(9, writeValue);   //Turn on 1st LED
    analogWrite(10, writeValue);  //Turn on 2nd LED
    analogWrite(11, writeValue);  //Tuen on 3rd LED
  }
  Serial.print(readValue);
  Serial.print(" : ");
  Serial.println(writeValue);     //The ln at the end indicates a linebreak that will happen at the end.    
  delay(100);                            
}
