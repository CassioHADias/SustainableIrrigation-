// C++ code
//
int moisture = 0;

//Pino Bomba D'água 
const int motor = 13;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  
  //Definir pinos de saída
  pinMode(motor, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture); //Mostrar umidade

  if (moisture < 200) { // 200 = 20% de umidade do solo
    digitalWrite(motor, HIGH); 
    delay(5000); //Tempo de Irrigação
  }
  digitalWrite(motor, LOW); //Deliga a Bomba
  delay(1000); // Tempo de espera entre as verificações
}