import os
import subprocess

os.chdir("../yolo-9000/darknet/")

cmd = [
    "./darknet",
    "detector",
    "test",
    "cfg/combine9k.data",
    "cfg/yolo9000.cfg",
    "../yolo9000-weights/yolo9000.weights",
    "data/horses.jpg",
    "-out",
    "results/horses-prediction"
]

proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output = proc.stdout.read()
print(output.decode("utf-8"))
