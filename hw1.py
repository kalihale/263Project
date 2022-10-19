# Homework 1
# Kali Hale
# Perceptron Algorithm
import random
import matplotlib.pyplot as plt
import numpy as np

def PLA(vecs, problemPart):
    # ／(^ㅅ^)＼ Generate w and vectors
    w = [0, 0, 0]
    vecsize = 3
    vecnum = vecs
    allVec = [[1 for vecsize in range(vecsize)] for vecnum in range(vecnum)]
    ys = [0 for i in range(vecnum)]

    for i in allVec:
        for j in range(1, 3):
            i[j] = random.random() * 100

    horiz = [allVec[i][1] for i in range(vecnum)]
    vert = [allVec[i][2] for i in range(vecnum)]

    # ／(^ㅅ^)＼ Generate slope and intercept for target function f
    m = random.randrange(-1, 1)
    b = random.randrange(0, 100)
    f = [((m * i) + b) for i in range(1, 100, 1)]

    # ／(^ㅅ^)＼ Classify points
    for i in range(vecnum):
        if allVec[i][2] > (m * allVec[i][1] + b):
            ys[i] = 1
        else:
            ys[i] = -1

    # ／(^ㅅ^)＼ Plot target
    plt.plot(f, label = 'Target')
    plt.scatter(horiz, vert, c=ys)
    # plt.title("Part " + problemPart + ": Target")
    # plt.savefig("Part" + problemPart + "Target.jpg")

    # ／(^ㅅ^)＼ PLA
    iterations = 0
    misclassified = True
    while misclassified:
        misclassified = False
        for i in range(vecnum):
            if np.sign(np.dot(w, allVec[i])) != ys[i]:
                w = w + np.dot(ys[i], allVec[i])
                misclassified = True
                iterations += 1
                break

    # ／(^ㅅ^)＼ PLA result and plot
    g = [(-(w[1] / w[2]) * i - w[0] / w[2]) for i in range(1, 100)]
    plt.plot(g, label = 'PLA')
    # plt.scatter(horiz, vert, c=ys)
    plt.title("Part " + problemPart + ": PLA")
    plt.suptitle("Iterations: " + str(iterations))
    plt.legend()
    plt.savefig("Part" + problemPart + "PLA.jpg")
    plt.clf()


# ／(^ㅅ^)＼ Generate with 20 points
PLA(20, "AB")
PLA(20, "C")
# ／(^ㅅ^)＼ Generate with 100 points
PLA(100, "D")
# ／(^ㅅ^)＼ Generate with 1000 points
PLA(1000, "E")
