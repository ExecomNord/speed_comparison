#!/usr/bin/env python

from datetime import datetime
import csv

def shortBubbleSort(alist):
    start = datetime.now()
    exchanges = True
    passnum = len(alist) - 1
    while passnum > 0 and exchanges:
        exchanges = False
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                exchanges = True
                temp = alist[i]
                alist[i] = alist[i + 1]
                alist[i + 1] = temp
        passnum = passnum-1
    dt = datetime.now() - start
    time = ((dt.days * 24 * 60 * 60 + dt.seconds) * 1000.0 + dt.microseconds / 1000.0) / 1000.0
    return time

totalTime = 0

with open('test_data.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    lines = 0
    for row in reader:
	time = shortBubbleSort(row)
        print("Number of elements: %d done in: %fs" % (len(row), time))
	totalTime += time
	lines += 1
print("Total time: %fs" % (totalTime))

