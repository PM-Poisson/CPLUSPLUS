import matplotlib.pyplot as plt
import numpy as np

data = {}
with open('data.m') as f:
    content = f.read()

exec(content.replace(';', '\n'), data)

curve = np.array(data['curve'])
polygon = np.array(data['polygon'])

dim = curve.shape[0]

if dim == 1:
    plt.plot(curve[0], 'r')
    plt.plot(polygon[0], 'bo-')

elif dim == 2:
    plt.plot(curve[0], curve[1], 'r')
    plt.plot(polygon[0], polygon[1], 'bo--')
    plt.axis('equal')

elif dim == 3:
    from mpl_toolkits.mplot3d import Axes3D
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot(curve[0], curve[1], curve[2], 'r')
    ax.plot(polygon[0], polygon[1], polygon[2], 'bo--')

plt.title("Bezier Curve Viewer")
plt.show()
