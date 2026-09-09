import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sb
from numpy.polynomial import Polynomial
import os, csv

time = 'Latest: Time (s)'
pos = 'Latest: Position (m)'
vel = 'Latest: Velocity (m/s)'
acc = 'Latest: Acceleration (m/s²)'
y_axis = pos

directory = 'C:\\Users\\Owner\\Desktop\\Lab 4 CSVs\\Results'

csvstring = "File Name, Ax^2, Bx, +C, \n"

# directory = str(input("Directory of CSV file? "))
# directory = directory.strip('"')
# print(directory)

for data_file in os.listdir(directory):
    pos_data = pd.read_csv(directory + "\\" + data_file)
    sb.scatterplot(data=pos_data, x = time, y = y_axis)
    pos_data = pos_data[pos_data[vel] > 0.10]  

    # pos_model = np.poly1d(np.polyfit(pos_data[time], pos_data[y_axis], 2))
    pos_model = Polynomial.fit(pos_data[time], pos_data[y_axis], 2)

    polyline = np.linspace(0, 2.2, 100)

    """plt.scatter(pos_data[time], pos_data[y_axis])
    plt.show()

    plt.scatter(pos_data[time], pos_data[y_axis])
    plt.plot(polyline, pos_model(polyline))
    plt.show()"""

    coefs = pos_model.convert().coef
    print(data_file, ",", coefs[0], ",", coefs[1], ",", coefs[2])
    csvstring += (data_file + "," + str(coefs[0]) + "," + str(coefs[1]) + "," + str(coefs[2]) + "\n")