# cubecell-ogn-tracker
OGN-Tracker implementation on the HELTEC CubeCell 6502 with GPS

## Functionality
As of now the OGN transmission and relaying are implemented and working well.
As well status and info messages are sent like other OGN-Trackers.
Serial console prints GPS NMEA and setting parameters is possible via $POGNS sentence,
however there is an issue with characters being lost thus this needs to be addressed.

## Parameters, which can be set
You can set the parameters with any terminal program which is able to send characters to the serial port emulated on the USB.
Ctrl-C lists all parameters and theie current values.
You can change a parameter value with sending:
```
$POGNS,<name>=<value>
```
Each time you change a parameter with $POGNS the full parameter set is written into flash thus permanently stored.


**Aircraft-type:** drone-type is 13 or 0xD
```
$POGNS,AcftType=13
```

**Transmitted power:** [dBm]
```
$POGNS,TxPower=14
```

**Info-parameters:** like registration, pilot name, aircraft type, model, manufacturer, other identification
Each parameter is a string up to 15 ASCII characters which are non-blank and within 7-bit range.
The names are: "Pilot", "Manuf", "Model", "Type", "SN", "Reg", "ID", "Class", "Task", "Base", "ICE", "PilotID", "Hard", Soft", "Crew"
```
$POGNS,Reg=XY-ABC
```

## Compile/upload
This project is compiled with PlatformIO and requires a forked HELTEC library
modified to enable OGN transmission and reception https://github.com/pjalocha/CubeCell-Arduino
This library should be placed under <i>lib</i> sub-folder of the project.

I include the commands which worked for me on Linux, it might be a little different on Windows

Install PlatformIO

```
sudo apt-get install python3-venv
python3 -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/master/scripts/get-platformio.py)"
```

Clone the repository code
```
git clone https://github.com/pjalocha/cubecell-ogn-tracker.git
cd cubecell-ogn-tracker
```

Clone the HELTEC library hacked for additional RF options
```
mkdir lib
cd lib
git clone https://github.com/pjalocha/CubeCell-Arduino.git
cd ..
```

Compile and upload
```
~/.platformio/penv/bin/pio run --target upload
```
