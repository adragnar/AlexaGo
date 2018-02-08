# AlexaGo
http://alexa-go.com/

Inspiration
Voice assistive technologies are changing the way we interact with our world. They have the potential to become our companions, loyal friends in our times of need. But in its current form, by only being able to act in the form of voice, these devices are fundamentally limited - unable to interact with us where it matters most, in the physical world. We look to change that through AlexaGo.

What it does
AlexaGo takes Amazon Alexa, the best in voice-assistive technology, and mounts it on a mobile robot exoskeleton. This allows AlexaGo to respond to your voice commands through physical actions: say fetching you a ca of pop or lighting your way down a dark hallway. The AlexaGo was designed with the elderly as a specific target group, with our device configurable to many mobility-based applications.

How we built it
To build AlexaGo, we first built a robotic exoskeleton which allowed for 2D motion and had an attached robot arm. Then, we programmed an Amazon Alexa to be able to translate our voice commands into physical commands in the Arduino programming language, which were then executed on the robot through an Arduino board. In order to analyze the surrounding environment, we used Darknet: a deep learning image recognition platform.

Challenges we ran into
We faced a variety of challenges in developing AlexaGo, namely involved with integration between all of the project’s software and hardware. Individually, both our hardware solution, our Amazon Alexa and our image recognition algorithms worked very well. However, we ran into many communication issues as we tried to get all of them to communicate with eachother. Our server side was non-functional.

What we learned
We’ve learned that robotic integration is a very difficult task: what seems simple in theory is actually really hard in practice.

What's next for AlexaGo
Looking into the AlexaGo’s future, our main goal is to increase the number of supported actuators and extensions. This will allow it to perform many more functions and become a versatile home assistant.

Built With
c
python
arduino
machine-learning
node.js
amazon-alexa
amazon-web-services
amazon-ec2
javascript
neural-network
