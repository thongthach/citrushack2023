import serial
import requests

url = 'http://34.125.240.67/api/Robot'
ser = serial.Serial('/dev/ttyACM0', 9600)

s = [0]
while True:
    s[0] = ser.readline()
    if 'dist' in str(s[0]):
        requests.post(url, params={'type':'R','val':s[0]})
    else:
        requests.post(url, params={'type':'N','val':s[0]})
    print(s[0])