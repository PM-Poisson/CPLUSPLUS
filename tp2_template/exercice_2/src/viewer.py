import matplotlib.pyplot as plt
import numpy as np
import re

def read_matrix(content, name):
    pattern = rf"{name}\s*=\s*\[(.*?)\];"
    match = re.search(pattern, content, re.S)
    if not match:
        return None

    block = match.group(1).strip()
    rows = block.split(';')
    matrix = []

    for row in rows:
        row = row.strip()
        if row:
            matrix.append([float(x) for x in row.split()])

    return np.array(matrix)

with open("data.m") as f:
    content = f.read()

curve = read_matrix(content, "curve")
polygon = read_matrix(content, "polygon")

if curve is None or polygon is None:
    raise RuntimeError("Impossible de lire data.m")

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
