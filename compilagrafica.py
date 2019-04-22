import numpy as np
import matplotlib.pyplot as plt

x1=np.loadtxt("datos1.txt", usecols=0)
y1=np.loadtxt("datos1.txt", usecols=1)
x2=np.loadtxt("datos2.txt", usecols=0)
y2=np.loadtxt("datos2.txt", usecols=1)

def f(x):
    return np.exp(-10*x)
x=np.arange(0,0.4,0.01)

plt.figure()
plt.plot(x1,y1, label="Explicit Sheme")
plt.plot(x2,y2, label="Implicit Sheme")
plt.plot(x,f(x), label="Solución")
plt.legend()
plt.xlabel("t")
plt.ylabel("y")
plt.savefig("Solucionaprox.png")