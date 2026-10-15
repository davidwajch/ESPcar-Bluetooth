# ESPcar Bluetooth

Firmware para ESP32 que controla um carrinho RC com dois motores via Bluetooth Classic. Recebe comandos seriais (W/A/S/D) e aciona os GPIOs conectados aos drivers dos motores.

## O que faz

O projeto implementa um controle remoto simples para carrinhos RC de dois motores. O ESP32 atua como receptor Bluetooth e traduz comandos de texto em sinais digitais para os pinos de controle dos motores. Cada motor tem dois pinos (frente/trás), permitindo controle bidirecional.

## Hardware

**MCU:** ESP32 (qualquer placa compatível com `BluetoothSerial`)

**Pinos utilizados:**
- GPIO 32: Motor A - Frente
- GPIO 18: Motor A - Trás  
- GPIO 19: Motor B - Frente
- GPIO 21: Motor B - Trás

**Motores:** Dois motores DC com driver (ponte H, L298N, etc). Os pinos do ESP32 conectam nos inputs do driver, não diretamente nos motores.

## Como compilar

### Arduino IDE

1. Instale o [suporte para ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) no Arduino IDE
2. Abra `ESPcar/ESPcar.ino`
3. Selecione a placa (ex: ESP32 Dev Module) e porta serial
4. Clique em Upload

### PlatformIO

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
```

Comando: `pio run --target upload`

## Como usar

1. Carregue o firmware no ESP32
2. O dispositivo Bluetooth aparecerá como **"LENDA"**
3. Pareie com celular/computador
4. Conecte via app serial Bluetooth (ex: Serial Bluetooth Terminal)
5. Envie os comandos:

| Comando | Ação |
|---------|------|
| `W` | Frente |
| `S` | Trás |
| `A` | Esquerda (gira) |
| `D` | Direita (gira) |
| Outros | Para |

## Estrutura

```
.
├── ESPcar/
│   └── ESPcar.ino    # Firmware completo
├── LICENSE           # MIT
└── README.md
```

## Configuração

Para mudar o nome Bluetooth, edite a linha 10 em `ESPcar.ino`:

```cpp
SerialBT.begin("LENDA"); // Altere aqui
```

Para usar pinos diferentes, modifique as constantes no início do arquivo:

```cpp
const int motorAF = 32;  // Motor A - Frente
const int motorAT = 18;  // Motor A - Trás
const int motorBF = 19;  // Motor B - Frente
const int motorBT = 21;  // Motor B - Trás
```

## Próximos passos

- Adicionar controle de velocidade (PWM)
- Implementar timeout de segurança (parar se perder conexão)
- Suporte para comandos de velocidade variável
- Adicionar modo de calibração dos motores

## Licença

MIT - veja [LICENSE](LICENSE)
