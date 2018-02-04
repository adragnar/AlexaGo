import subprocess

cmd = [
    "../yolo-9000/darknet/darknet",
    "detector",
    "test",
    "../yolo-9000/darknet/cfg/combine9k.data",
    "../yolo-9000/darknet/cfg/yolo9000.cfg"
    "../yolo-9000/yolo9000-weights/yolo9000.weights",
    "~/Desktop/yuka.jpg",
    "-out",
    "~/Desktop/yuka-prediction"
]

proc = subprocess.Popen(cmd, stdout=subprocess.PIPE)
output = proc.stdout.read()
print(output)
