import numpy as np
import matplotlib.pyplot as plt

datos01 = np.loadtxt("euler.dat").T
datos1 = np.loadtxt("rk4.dat").T
datos001 = np.loadtxt("leapfrog.dat").T

plt.figure(figsize=(10,10))

plt.subplot(3,3,1)
plt.plot(datos01[0],datos01[1])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")
plt.ylabel("Position")
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(datos1[0],datos1[1])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")
plt.title("RK")

plt.subplot(3,3,3)
plt.plot(datos001[0],datos001[1])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")
plt.title("Leapfrog")

plt.subplot(3,3,4)
plt.plot(datos01[0],datos01[2])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")
plt.ylabel("Velocity")

plt.subplot(3,3,5)
plt.plot(datos1[0],datos1[2])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")

plt.subplot(3,3,6)
plt.plot(datos001[0],datos001[2])
plt.xlim(0,15)
plt.ylim(-1.5,1.5)
plt.xlabel("Time")

plt.subplot(3,3,7)
plt.plot(datos01[1],datos01[2])
plt.xlim(-2,2)
plt.ylim(-2,2)
plt.xlabel("Position")

plt.subplot(3,3,8)
plt.plot(datos1[1],datos1[2])
plt.xlim(-2,2)
plt.ylim(-2,2)
plt.xlabel("Position")


plt.subplot(3,3,9)
plt.plot(datos001[1],datos001[2])
plt.xlim(-2,2)
plt.ylim(-2,2)
plt.xlabel("Position")

plt.savefig("resultados.png")