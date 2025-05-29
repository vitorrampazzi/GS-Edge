# 🚨 Projeto: Alerta de Enchentes com Arduino

Este projeto utiliza um sensor ultrassônico para medir a distância do nível da água e, com base nessa medição, emite alertas visuais e sonoros. Ideal para regiões suscetíveis a enchentes, o sistema alerta a população com LEDs, buzzer e um display LCD.

## 📦 Componentes Utilizados

- Arduino UNO
- Sensor ultrassônico HC-SR04
- Display LCD 16x2 com comunicação I2C
- LEDs (Verde, Amarelo e Vermelho)
- Buzzer (ativo)
- Jumpers
- Protoboard

## ⚙️ Esquema de Conexão

| Componente     | Pino Arduino |
|----------------|--------------|
| HC-SR04 - Trig | 9            |
| HC-SR04 - Echo | 10           |
| LED Verde      | 2            |
| LED Amarelo    | 3            |
| LED Vermelho   | 4            |
| Buzzer         | 5            |
| LCD I2C        | SDA -> A4    |
|                | SCL -> A5    |


## 🧠 Funcionamento

1. O sensor ultrassônico mede a distância entre ele e a superfície da água.
2. O sistema classifica o nível de risco baseado na distância:
   - **> 200 cm**: `Nível normal` – LED verde aceso.
   - **100 a 200 cm**: `Nível de alerta` – LED amarelo aceso.
   - **< 100 cm**: `Nível crítico` – LED vermelho e buzzer ativado.
3. O display LCD mostra o status atual e a distância medida.
