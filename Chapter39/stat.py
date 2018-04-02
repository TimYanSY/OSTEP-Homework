import os
import argparse
import sys

parser = argparse.ArgumentParser(description='Process file name')
parser.add_argument('name')
args = parser.parse_args()

f = args.__getattribute__('name')

print(os.stat(path=f))
