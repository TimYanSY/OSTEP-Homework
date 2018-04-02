import os

for file in os.listdir(os.getcwd()):
    print(os.stat(file))
