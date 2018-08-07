# Publishing Client
#Broker - Raspberry pi, with mosquitto secured with username and password

import paho.mqtt.client as mq
c=mq.Client()
c.username_pw_set('nancy','123456')
c.connect('192.168.0.100',1883)
c.publish('iot/local','Hi This is from PC')
c.disconnect()