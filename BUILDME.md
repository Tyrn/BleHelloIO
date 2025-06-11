# ESP32 on PlatformIO, arduino framework

## Deploy and configure

- Clone

```
git clone git@github.com:Tyrn/BleHelloIO.git
```

```
cd BleHelloIO
```

- Install platform (optional; `./lsupdate.sh` is enough)

```
pio pkg install -p "platformio/espressif32"
```

- Configure, or reconfigure at will

```
./lsupdate.sh
```

## Build

- Build and upload

```
pio run -t upload
```

## Format source

- Via Clang

```
clang-format -i **/*.(c|cpp|h|hh|hpp|ino)
```
