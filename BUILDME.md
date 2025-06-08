# An Arduino sandbox for ESP32 Bluetooth BLE

## Boards

_ESP32 Dev Module_

## Libraries

By default, all the libraries are installed in the `~/Arduino/libraries`
directory via the
[Arduino IDE](https://github.com/Tyrn/dotfiles/blob/main/messy-notes/Arduino.md)
Library Manager, as well as manually.

- _TaskScheduler_ by Anatoli Arkhipenko
- _LiquidCrystal_I2C_ by Frank de Brabander
- _LCD_1602_RUS_ALL_ ([fork](https://github.com/Tyrn/LCD_1602_RUS_ALL))

```
git clone https://github.com/Tyrn/LCD_1602_RUS_ALL ~/Arduino/libraries/LCD_1602_RUS_ALL
```

or, if it's all yours

```
git clone git@github.com:Tyrn/LCD_1602_RUS_ALL.git ~/Arduino/libraries/LCD_1602_RUS_ALL
```

- _EasyButton_ by Evert Arias

## Format source

- Via Clang

```
clang-format -i **/*.(c|cpp|h|hh|hpp|ino)
```
