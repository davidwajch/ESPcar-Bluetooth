# ESPcar Bluetooth

Firmware para **ESP32** que recebe comandos via **Bluetooth Classic (BluetoothSerial)** e aciona dois motores (quatro pinos: frente/trás por motor). Pensado para carrinhos RC com dois motores, controlados a partir do celular ou de outro dispositivo pareado.

## Hardware

- Placa compatível com ESP32 e API `BluetoothSerial`
- Motores conectados aos pinos definidos em `ESPcar.ino` (ex.: `motorAF`, `motorAT`, `motorBF`, `motorBT`)

## Comandos (serial Bluetooth)

| Caractere | Ação |
|-----------|------|
| `W` | Frente |
| `S` | Trás |
| `A` | Esquerda |
| `D` | Direita |
| outros | Para motores |

## Como usar

1. Abra `ESPcar/ESPcar.ino` no **Arduino IDE** (ou PlatformIO, ajustando o ambiente ESP32).
2. Selecione a placa e a porta corretas.
3. Compile e envie para o ESP32.
4. Pareie o dispositivo com o nome configurado em `SerialBT.begin("...")`.
5. Envie os caracteres de comando a partir do app ou terminal serial Bluetooth.

## Licença

Veja [LICENSE](LICENSE).
