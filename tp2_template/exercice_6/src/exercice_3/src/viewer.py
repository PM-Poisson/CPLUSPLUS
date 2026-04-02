import matplotlib.pyplot as plt

with open('data.m') as f:
    for line in f:
        curve = line.split('=')[0]
        line = ''.join([x for x in line if x != '[' and x!=']'])
        data = [ p.split(';')[:2] for p in line.split('=')[1].split(',')]
        x = [float(point[0]) for point in data]
        y = [float(point[1]) for point in data]
        plt.plot(x, y, marker='o' if curve == 'polygon' else '', color='b' if curve == 'polygon' else 'r')
    plt.show()