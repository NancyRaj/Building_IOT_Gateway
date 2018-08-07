
#Building a IOT Gateway - Raspberry Pi
#Securing Mosquitto in Pi,by creating Username and PW-for clients to connect. 
#Multiple Publishing Clients connect to Raspberry PI-Local n/w Gateway
# From Gateway to Cloud-iot.eclipse.org
import paho.mqtt.client as mq
c1=mq.Client()
c2=mq.Client()
c1.username_pw_set('nancy','123456')
c1.connect('192.168.0.100',1883)
def onc(c1,userdata,flag,rc):
    print('The value of RC is',rc)
    c1.subscribe('iot/local')
def onm(c1,userdata,msg):
    m=msg.payload.decode()
    print(m)
    c2.connect('iot.eclipse.org',1883)
    c2.publish('iot/global',m)
    c2.disconnect()
    
c1.on_connect=onc
c1.on_message=onm
c1.loop_forever()

