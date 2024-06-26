import random
import sys

class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.insert(0,item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            raise IndexError("pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.items[0]
        else:
            return None

    def size(self):
        return len(self.items)

# Initialize global variables
error1 = 0
error2 = 0
too = 0
s = ""
ss = ""
v = []
mymap = {}

def utga(k):
    if k == 1:
        return random.randint(1, 9)
    elif k == 2:
        return random.randint(10, 99)
    elif k == 3:
        return random.randint(100, 999)
    elif k == 4:
        return random.randint(1000, 9999)
    elif k == 5:
        return random.randint(10000, 99999)
    elif k == 6:
        return random.randint(100000, 999999)
    elif k == 7:
        return random.randint(1000000, 9999999)
    elif k == 8:
        return random.randint(10000000, 99999999)
    return 0

# Functions for operations
def urj(x, y):
    d = f"{x}x{y}"
    v.append((x * y, d))
    return x * y

def huv(x, y):
    global error1
    d = f"{x}:{y}"
    if y == 0:
        error1 = 1
        return 1
    elif x % y != 0:
        error1 = 1
    else:
        v.append((x // y, d))
        return x // y

def nem(x, y):
    d = f"{x}+{y}"
    v.append((x + y, d))
    return x + y

def has(x, y):
    global error2
    d = f"{x}-{y}"
    v.append((x - y, d))
    if x - y < 0:
        error2 = 1
    return x - y

# Function to compress string representation
def compres(s1):
    s1 += ' '
    p = ''
    t = -1
    for i in range(len(s1)):
        t += 1
        if not s1[i].isdigit():
            p += chr(t + 48)
            t = -1
            if s1[i] != ' ':
                p += s1[i]
    return p

# Function to print results
def hevleh(x):
    global ss
    for i in range(1, len(ss) - 1):
        print(ss[i], end="")
    print()
    for i in range(len(v)):
        print(v[i][1], v[i][0], end=" ")
        s1 = compres(v[i][1])
        if s1 in mymap:
            print(mymap[s1])
    print()

# Function to initialize the map
def ID():
    global mymap
    mymap = {
        "1+1": 40, "2+1": 42, "1-1": 46, "1x1": 47, "2+2": 69, "2-1": 78,
        "2-2": 84, "2:1": 91, "2x1": 97, "2x4": 100, "3+2": 103, "3+3": 105,
        "3-2": 109, "3-3": 112, "3x2": 120, "3x3": 122, "4+4": 125, "4-4": 128,
        "4:1": 131, "4:2": 134, "4:3": 135, "4x1": 138, "4x2": 141, "4x3": 146,
        "4x4": 147, "5:2": 158, "5:3": 160, "5x3": 161, "6:1": 165, "6:2": 167,
        "6:3": 168, "6x2": 171, "7:1": 175, "7:2": 176, "7:4": 178, "7x1": 179,
        "1+1": 180, "1-1": 181, "1:1": 182, "1x1": 183, "1+2": 184, "1-2": 185,
        "1:2": 186, "1x2": 187, "1+3": 188, "1-3": 189, "1:3": 190, "1x3": 191,
        "1+4": 192, "1-4": 193, "1:4": 194, "1x4": 195, "1+5": 196, "1-5": 197,
        "1:5": 198, "1x5": 199, "1+6": 200, "1-6": 201, "1:6": 202, "1x6": 203,
        "1+7": 204, "1-7": 205, "1:7": 206, "1x7": 207, "2+1": 208, "2-1": 209,
        "2:1": 210, "2x1": 211, "2+2": 212, "2-2": 213, "2:2": 214, "2x2": 215,
        "2+3": 216, "2-3": 217, "2:3": 218, "2x3": 219, "2+4": 220, "2-4": 221,
        "2:4": 222, "2x4": 223, "2+5": 224, "2-5": 225, "2:5": 226, "2x5": 227,
        "2+6": 228, "2-6": 229, "2:6": 230, "2x6": 231, "2+7": 232, "2-7": 233,
        "2:7": 234, "2x7": 235, "3+1": 236, "3-1": 237, "3:1": 238, "3x1": 239,
        "3+2": 240, "3-2": 241, "3:2": 242, "3x2": 243, "3+3": 244, "3-3": 245,
        "3:3": 246, "3x3": 247, "3+4": 248, "3-4": 249, "3:4": 250, "3x4": 251,
        "3+5": 252, "3-5": 253, "3:5": 254, "3x5": 255, "3+6": 256, "3-6": 257,
        "3:6": 258, "3x6": 259, "3+7": 260, "3-7": 261, "3:7": 262, "3x7": 263,
        "4+1": 264, "4-1": 265, "4:1": 266, "4x1": 267, "4+2": 268, "4-2": 269,
        "4:2": 270, "4x2": 271, "4+3": 272, "4-3": 273, "4:3": 274, "4x3": 275,
        "4+4": 276, "4-4": 277, "4:4": 278, "4x4": 279, "4+5": 280, "4-5": 281,
        "4:5": 282, "4x5": 283, "4+6": 284, "4-6": 285, "4:6": 286, "4x6": 287,
        "4+7": 288, "4-7": 289, "4:7": 290, "4x7": 291, "5+1": 292, "5-1": 293,
        "5:1": 294, "5x1": 295, "5+2": 296, "5-2": 297, "5:2": 298, "5x2": 299,
        "5+3": 300, "5-3": 301, "5:3": 302, "5x3": 303, "5+4": 304, "5-4": 305,
        "5:4": 306, "5x4": 307, "5+5": 308, "5-5": 309, "5:5": 310, "5x5": 311,
        "5+6": 312, "5-6": 313, "5:6": 314, "5x6": 315, "5+7": 316, "5-7": 317,
        "5:7": 318, "5x7": 319, "6+1": 320, "6-1": 321, "6:1": 322, "6x1": 323,
        "6+2": 324, "6-2": 325, "6:2": 326, "6x2": 327, "6+3": 328, "6-3": 329,
        "6:3": 330, "6x3": 331, "6+4": 332, "6-4": 333, "6:4": 334, "6x4": 335,
        "6+5": 336, "6-5": 337, "6:5": 338, "6x5": 339, "6+6": 340, "6-6": 341,
        "6:6": 342, "6x6": 343, "6+7": 344, "6-7": 345, "6:7": 346, "6x7": 347,
        "7+1": 348, "7-1": 349, "7:1": 350, "7x1": 351, "7+2": 352, "7-2": 353,
        "7:2": 354, "7x2": 355, "7+3": 356, "7-3": 357, "7:3": 358, "7x3": 359,
        "7+4": 360, "7-4": 361, "7:4": 362, "7x4": 363, "7+5": 364, "7-5": 365,
        "7:5": 366, "7x5": 367, "7+6": 368, "7-6": 369, "7:6": 370, "7x6": 371,
        "7+7": 372, "7-7": 373, "7:7": 374, "7x7": 375
    }

if __name__ == "__main__":
    ID()
    random.seed()
    with open("input.txt", "r") as infile, open("output.txt", "w") as outfile:
        sys.stdin = infile
        sys.stdout = outfile

        for s in sys.stdin:
            s = s.strip()
            too = 10
            s = f'({s})'
            while too > 0:
                ss = ""
                v = []
                error2 = 0
                error1 = 0
                st1 = Stack()
                st2 = Stack()
                i = 0
                for i in range(len(s)):
                    if s[i] == '(':
                        st2.push('(')
                        ss += '('
                    elif s[i] =='+':
                        st2.push('+')
                        ss += '+'
                    elif s[i] =='-':
                        st2.push('-')
                        ss += '-'
                    elif s[i].isdigit():
                        st1.push(utga(int(s[i])))
                        ss += str(st1.items[0])
                    elif s[i] == 'x':
                        if s[i + 1] != '(':
                            k = st1.pop()
                            m = utga(int(s[i + 1]))
                            st1.push(urj(k, m))
                            ss += 'x' + str(m)
                            i += 1
                            continue
                        else:
                            st2.push('x')
                            ss += 'x'
                            continue
                    elif s[i] == ':':
                        if s[i + 1] != '(':
                            k = st1.pop()
                            m = utga(int(s[i + 1]))
                            st1.push(huv(k, m))
                            ss += ':' + str(m)
                            i += 1
                            continue
                        else:
                            st2.push(':')
                            ss += ':'
                            continue
                    elif s[i] == ')':
                        ss += ')'
                        v1 = Stack()
                        v2 = Stack()
                        while v2.size() > 0 and st2.size() > 0 and st2.peek() != '(':
                            v2.push(st2.pop())
                            v1.push(st1.pop())
                        b = st1.pop()
                        st2.pop()
                        while v2.size() > 0:
                            if v2.peek() == '+':
                                b = nem(b, v1.pop())
                            elif v2.peek() == '-':
                                b = has(b, v1.pop())
                            v2.pop()
                        if st2 and st2.peek() == 'x':
                            m = st1.pop()
                            st1.push(urj(m, b))
                            st2.pop()
                        elif st2 and st2.peek() == ':':
                            m = st1.pop()
                            st1.push(huv(m, b))
                            st2.pop()
                        else:
                            st1.push(b)
                if error1 + error2 == 0:
                    hevleh(st1.items[0])
                    st1.pop()
                    too -= 1
