#!/usr/bin/env python

import csv
import random

numberOfRows = 100
sampleSize = {'low': 500, 'heigh': 1500}

with open('test_data.csv', 'w') as csvfile:
    writer = csv.writer(csvfile)
    for row in range(0, numberOfRows):
	size = random.randint(sampleSize['low'], sampleSize['heigh'])
        writer.writerow(random.sample(xrange(size), size))

