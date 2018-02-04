import base64
import requests

with open("sprite.jpg", "rb") as image_file:
    encoded_string = base64.b64encode(image_file.read())

print(encoded_string)

r = requests.post("http://34.201.113.132:3000/post_data", data={'img': encoded_string})
print(r.text)
