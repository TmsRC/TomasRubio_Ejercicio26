import numpy as np
import matplotlib.pyplot as plt

datos01 = np.loadtxt("rk4_01.dat").T
datos1 = np.loadtxt("rk4_1.dat").T
datos001 = np.loadtxt("rk4_001.dat").T

plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.plot(datos01[0],datos01[1])
plt.title("y vs. x  (delta=0.1)")

plt.subplot(3,3,2)
plt.plot(datos01[0],datos01[2])
plt.title("dy/dx vs. x  (delta=0.1)")

plt.subplot(3,3,3)
plt.plot(datos01[1],datos01[2])
plt.title("dy/dx vs. y  (delta=0.1)")

plt.subplot(3,3,4)
plt.plot(datos1[0],datos1[1])
plt.title("y vs. x  (delta=1)")

plt.subplot(3,3,5)
plt.plot(datos1[0],datos1[2])
plt.title("dy/dx vs. x  (delta=1)")

plt.subplot(3,3,6)
plt.plot(datos1[1],datos1[2])
plt.title("dy/dx vs. y  (delta=0.01)")

plt.subplot(3,3,7)
plt.plot(datos001[0],datos001[1])
plt.title("y vs. x  (delta=0.01)")

plt.subplot(3,3,8)
plt.plot(datos001[0],datos001[2])
plt.title("dy/dx vs. x  (delta=0.01)")

plt.subplot(3,3,9)
plt.plot(datos001[1],datos001[2])
plt.title("dy/dx vs. y  (delta=0.01)")

plt.savefig("rk4.png")