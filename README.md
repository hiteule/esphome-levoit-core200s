# ESPHome

An electronic board designed to replace the Levoit Core 200s air purifier control board (because I broke it).
Only the "Fan speed" and "Power" buttons are functional.
The air purifier is exposed via [ESPHome], which enables integration with [HomeAssistant].

## PCB

The board must be connected to the "power board" of the air purifier via the JST connector on J1.
This connector supplies 5V on pin 1. Take care to connect it the right way.

The ESP32 should be flashed with ESPHome via J2(TX), J3(RX), J6(RTS), J7(DTR) J8(3.3V), J9(GND).
For this, you can use my [ESP/Atmega programmer].

The card was designed with [Kicad]. The sources (schematic & board) are in the "pcb" folder.

## Software

The ESP32 is exposing the Air Purifier in Home Assisant. To do it, we use [ESPHome].
To do so:
* Install the ESPHome module on [HomeAssistant].
* Plug the board to your computer with J2(TX), J3(RX), J6(RTS), J7(DTR) J8(3.3V), J9(GND) and the [ESP/Atmega programmer].
* In the ESPHome module, create a new device.
* Update your ESPHome device with the `levoit-core200s.yaml` file.
* Install it on the ESP.

Now you can unplug the ESP from your computer, install it into the air purifier and connect it via J1.
ESP should boot normally and the air purifier should be visible in [HomeAssistant].

[HomeAssistant]: https://www.home-assistant.io
[ESPHome]: https://esphome.io/
[ESP/Atmega programmer]: https://github.com/hiteule/programmer-esp-atmega
[Kicad]: https://www.kicad.org
