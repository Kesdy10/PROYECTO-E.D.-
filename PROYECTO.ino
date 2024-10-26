//PROYECTO


//Variables
int sensor = 4;
int led1 = 2;
int led2 = 3;
int bz = 5;
int fr = 400;
int fr2 = 700;
boolean activo = false;
boolean alarma = false;
String clave;

//Declaracion de pines
void setup() {
  pinMode(sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(bz, OUTPUT);
  Serial.begin(9600);
}

//Activacion de alarma
void loop() {
  clave = Serial.readStringUntil('\r');
  // Activar sistema con clave "1234"
  if (clave == "1234" && activo == false) {
    alarma = false;
    activo = true;
    Serial.println("activado");
  }

// Comprobar si el proceso esta en modo activo
  if (activo == true) {
    if (digitalRead(sensor) == HIGH) {
      alarma = true;
      while (alarma == true && activo == true) {
        for (int i=0;i<=6;i++)
        {
          
// Enciende y apaga el LED 1 y buzzer
        digitalWrite(led1, HIGH);
        delay(20);
        digitalWrite(bz, HIGH);
        digitalWrite(led1, LOW);
        delay(20);
        digitalWrite(bz, LOW);

// Parpadeo de LED 2 y el buzzer por 7 veces, luego termina
        for (int i = 0; i <= 7; i++) {
          digitalWrite(led2, HIGH);
          delay(20);
          digitalWrite(bz, HIGH);
          digitalWrite(led2, LOW);
          delay(20);
          digitalWrite(bz, LOW);
        }

// Desactivacion de alarma
        clave = Serial.readStringUntil('\r');
        if (clave == "1111") {
          alarma = false;
          activo = false;
          Serial.println("desactivado");
        }
         clave = Serial.readStringUntil('\r');
        if (clave == "1111") {
          alarma = false;
          activo = false;
          {
          Serial.println("desactivado");
          }
      }
    }
  }
   }
    }
    }
