from flask import Flask
from flask_ask import Ask, statement, question
import serial
import cv2
import time
import requests
import base64
import json
inHand = "Nothing"

#camera functions
def save_image():
	camera_port=0
	ramp_frames = 30
	camera = cv2.VideoCapture(camera_port)

	for i in xrange(ramp_frames):
		temp = get_image(camera)
	camera_capture = get_image(camera)
	file = "/home/linaro/Desktop/image.jpg"
	cv2.imwrite(file, camera_capture)

	del(camera)

def get_image(cam):
	retval, im = cam.read()
	return im

#POST function
def post(r):
	with open("/home/linaro/Desktop/image.jpg", "rb") as f:
		data = f.read()
		image = data.encode("base64")
		r = requests.post("http://34.201.113.132:3000/post_data", data={"img":image})
		return r

#start of flask app
app = Flask(__name__)

ask = Ask(app, '/')

ser = serial.Serial("/dev/ttyUSB0", 9600)

@ask.launch
def default():
	inHand = "Nothing"
	ser.write(b'i') #initialize
	return question("Hi, I am Alexa Go Bot!")

@ask.intent("bringObject", mapping={'Object': 'Object'})
def bringObject(Object):
	global inHand
	ser.write(b't')	
	time.sleep(5)
	inHand = str(Object)
	return question("The can has been picked up.")

@ask.intent("putObject", mapping={'Object': 'Object'})
def putObject(Object):
	global inHand
	if (Object == inHand):
		ser.write('d') #put_down
		inHand = "Nothing"	
	else: return question("I am not holding " + str(Object))
	return question("The " + str(Object) + " has been put down.")

@ask.intent("turnAround")
def turnAround():
	ser.write("o")
	time.sleep(1)
	return question("Oh, hello there.")

@ask.intent("comeBack")
def comeBack():
	ser.write("q")
	time.sleep(2)
	return statement("Don't worry, I am right here.")

@ask.intent("backward")
def backward():
	ser.write("y")
	time.sleep(1)
	return statement("Done")

@ask.intent("forward")
def forward():
	ser.write("x")
	time.sleep(1)
	return statement("Done")

@ask.intent("turnLeft")
def turnLeft():
	ser.write("l")
	time.sleep(1)
	return statement("Done")

@ask.intent("turnRight")
def turnRight():
	ser.write("r")
	time.sleep(1)
	return statement("Done")


'''@ask.intent("captureImage")
def captureImage():
	r = ""
	save_image()
	r = json.loads(post(r).text)["data"]
	print(r[0]["name"])

	if (r[0]["name"] == "Coca Cola" or r[0]["name"] == "cup" or r[0]["name"] == "bottle" or r[0]["name"] == "orange soda"):
		box = r[0]["box"]
		x_diff = box[3] - box[1]
		x_center = box[1] + x_diff/2
		x_offset = x_center - 320

		if (x_diff < 0):
			ser.write(b'x')
			x_diff = -x_diff
			ser.write(x_diff)
		else:
			ser.write(b'y')
		
		if (x_offset >= 0):
			ser.write(b'l')
			ser.write(x_offset/5)
		else:
			ser.write(b'r')
			x_offset = -x_offset
			ser.write(x_offset/5)
		
	return question("image has been captured and uploaded")'''

@ask.intent("patMe")
def patMe():
	ser.write(b'p')
	time.sleep(2)
	return question("There, there, are you alright?")

@ask.intent('AMAZON.StopIntent')
def stop():
	return statement("good bye!")

@ask.session_ended
def session_ended():
	return "{}", 200

if __name__ == "__main__":
	app.run(debug=True)
