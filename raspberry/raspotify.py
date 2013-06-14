import serial, urllib
ser = serial.Serial('/dev/ttyACM0', 9600)
url = "http://192.168.0.5:1337/"
while 1 :
     linea = ser.readline().rstrip('\r\n')
     if linea == 'prev':
        fp = urllib.urlopen(url+"?op="+linea)
        print('prev: '+linea)
     elif linea == 'next':
        fp = urllib.urlopen(url+"?op="+linea)
        print('next: '+linea)
     else:
        print("Line: " + linea)
        #print(linea.find('next'))
        #print type(linea)
        #print "Comparing '%r' with '%r'" % (linea, "anterior")