# LDS006ESP32
library esp32 for LDS-006

using the lidar lds-006 with an ESP32

Based on the work of Aluminium-z https://github.com/Aluminum-z/Laser-Radar-LDS-006-Drive-Test

In this code, a distance, a position angle and a notion of rotation speed are shown.

The "angle" variable is entered from 0 to 360° in steps of 4 (0 4 8 12 ... 356 360)

The "distance" variable is entered in centimeters from 2 to 6000.

The "speed" variable is recovered in order to verify the reliability of the distance data.

These two variables are written to the serial monitor as they comming in the buffer.

A table of 2 lines and 90 columns is created to store the variables.

angle |0 |4 |8 |12 |16 |20 |...|360 |

distance |8 |8.2|14 |28 |54 |98 |...|5000|

Two commands are available to drive the lidar "startlds$" and "stoplds$"

In the code there is the possibility of controlling the lidar with the serial monitor simply by entering "s" for start and "p" for pause.

When it is written "s" the code sends the command "startlds$".

when it is written "p" the code sends the command "stoplds$".

The lidar work in Serial 115200 8N2 3.3V.
