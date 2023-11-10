int Sensor = 0 ;             // Pin que lee la temperatura
int umbral = 30 ;            // Temperatura que activa el ventilador
const int control = 9 ;      // Pin que controla el ventilador

void setup()
{
  Serial.begin(115200);       // Inicializa la comunicación serial a 115200 baudios
  pinMode(control, OUTPUT);    // Configura el pin de control del ventilador como salida
}

void loop()
{
  int lectura = analogRead(Sensor);               // Lee el valor analógico del sensor de temperatura
  float voltaje = 5.0 / 1024 * lectura ;           // Convierte la lectura analógica a voltaje
  float temp = voltaje * 100 - 5 ;                 // Convierte el voltaje a temperatura en grados Celsius
  Serial.println(temp);                            // Imprime la temperatura en el monitor serial

  if (temp >= umbral)
    digitalWrite(control, HIGH);                  // Si la temperatura es mayor o igual al umbral, activa el ventilador
  else
    digitalWrite(control, LOW);                   // Si la temperatura es menor al umbral, apaga el ventilador

  delay(200);                                      // Espera 200 milisegundos antes de realizar la próxima lectura
}
