import os
import subprocess
import json

def create_dictionary(text_string) :
    text_string = text_string.split("\n")
    dictionary_list = []

    for line in text_string:
        if len(line) > 0 and line[0] == "!":
            arr = [str(x) for x in line.split(";")]
            diction = {}
            diction["name"] = arr[0][1:]
            diction["prob"] = arr[1]
            diction["box"] = [int(x) for x in arr[2][1:-1].split(",")]
            dictionary_list.append(diction)

    return dictionary_list

os.chdir("../yolo-9000/darknet/")

cmd = [
    "./darknet",
    "detect",
    "cfg/tiny-yolo.cfg",
    "tiny-yolo.weights",
    "data/tmp.png",
    "-out",
    "results/tmp-prediction"
    # "./darknet",
    # "detector",
    # "test",
    # "cfg/combine9k.data",
    # "cfg/yolo9000.cfg",
    # "../yolo9000-weights/yolo9000.weights",
    # "data/tmp.png",
    # "-out",
    # "results/tmp-prediction"
]

proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output = proc.stdout.read().decode("utf-8")
print(json.dumps(create_dictionary(output)))
