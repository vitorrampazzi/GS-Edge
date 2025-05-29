// Declara bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Definição dos pinos usados
#define trigPin 9        // Pino do trigger do sensor ultrassônico
#define echoPin 10       // Pino do echo do sensor ultrassônico
#define ledVerde 2       // LED verde indicador
#define ledAmarelo 3     // LED amarelo indicador
#define ledVermelho 4    // LED vermelho indicador
#define buzzer 5         // Buzzer para alerta sonoro

void setup() {
  Serial.begin(9600);           // Inicializa comunicação serial para debug

  // Configura os pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Configura os pinos dos LEDs e buzzer como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Inicializa o display LCD e liga o backlight
  lcd.init();
  lcd.backlight();

  // Exibe mensagem inicial no LCD
  lcd.setCursor(0, 0);
  lcd.print("Alerta Enchente");
  delay(5000);  // Exibe a mensagem por 5 segundos antes de iniciar o loop
}

void loop() {
  long duracao;
  float distancia;

  // Envia pulso ultrassônico para medir distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Recebe o tempo do pulso de retorno (echo)
  duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância com base no tempo do pulso (em cm)
  distancia = duracao * 0.034 / 2;

  // Verifica a distância e controla LEDs, buzzer e mensagens no LCD
  if (distancia > 200) {
    // Nível normal: acende LED verde, apaga outros LEDs e buzzer
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);

    // Exibe mensagem "Nivel normal"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel normal");
    delay(2000);

    // Exibe a distância medida no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia:");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    lcd.print(" cm");
    delay(2000);

  } else if (distancia > 100) {
    // Nível alerta: acende LED amarelo, apaga outros LEDs e buzzer
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);

    // Exibe mensagem "Nivel alerta"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel alerta");
    delay(2000);

    // Exibe a distância medida no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia:");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    lcd.print(" cm");
    delay(2000);

  } else {
    // Nível crítico: acende LED vermelho e buzzer para alerta, apaga outros LEDs
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);

    // Exibe mensagem "Nivel critico"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel critico");
    delay(2000);

    // Exibe a distância medida no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia:");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    lcd.print(" cm");
    delay(2000);
  }
}
