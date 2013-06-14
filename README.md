# Raspotify
## Developed by http://antonio.sejas.es

### Things you need
* Raspberry Pi (RPi)
* Arduino (Leonardo)
* SRF05 (Dintance sensor)
* Computer with spotify


### Technologies I've used
* Shell scripting (Control Spotify)
* Node.js (Server, to call to the shell script)
* Arduino (Get the distance)
* Python (Comunicate with the arduino and send messages to Node.js)


### Libreries
* pyserial-2.6
* shpotify


### Usage
Run the server.js in your mac
Connect your arduino to the first usb of your raspberry (/dev/ttyACM0)
Run the raspotify.py in you raspberry

Play! :)

### Distances
*Next Song
if (averageDistance \< 70 && averageDistance \> 20 ) {

*Previous Song
} else if (averageDistance < 9 && averageDistance > 0) {
