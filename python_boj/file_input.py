

def readinput():
    f = open('input.txt', 'r')

    lines = f.readlines()

    for line in lines:
        print(line.strip())

    f.close()


readinput()
