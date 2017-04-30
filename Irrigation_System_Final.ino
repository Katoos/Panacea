const int LED1= 12;
const int LED2= 2;
const int LED3= 8;
#define RELAY1  7      
void setup(){
Serial.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(RELAY1, OUTPUT); 
}
void loop() {
int SensorReading= analogRead(A0);
Serial.println (SensorReading);
delay(1000); 
if (SensorReading >= 650 && SensorReading < 999){
digitalWrite(LED1,HIGH);
delay(500);
digitalWrite(LED1,LOW);
delay(500);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(RELAY1,0);          
Serial.println("WATER ON");  
}     
if (SensorReading > 200 && SensorReading < 650){
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(RELAY1,1);          
Serial.println("WATER OFF");

}
if (SensorReading > 1000 )
{
int Value = analogRead(A1);
float Celsius = ((Value/1024.0)*5000)/10; 
Serial.print("TEMPRATURE = ");
Serial.print(Celsius);
Serial.print("*C");
Serial.println();
delay(500);           
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,HIGH);
if (Value > 30 && Value < 50){
digitalWrite(RELAY1,0);
delay (3600000);
digitalWrite ( RELAY1,1);
delay (86400000);
}
if (Value > 10 && Value < 30){
digitalWrite(RELAY1,0);
delay (1550000);
digitalWrite ( RELAY1,1);
delay (86400000);
}
}
}

  
