""" knapsack.. capacity(M), item count(n),
value (p1, p2, p3, p4) = (15, 20, 9, 14)
weight (w1, w2, w3, w4) = (3, 5, 3, 4)

it can be split.
"""

class Knapsack:
    max = 0
    items[]

    def __init__(self, _max):
        self.max = _max

    def add(item):
        items.push(item)

class item:
    value = 0
    weight = 0
    vpw = 0 #value per weight

    def __init__(self, _value, _weight):
        self.value = _value
        self.weight = _weight
        self.vpw = float(_value)/_weight

M = 10
n = 4

itemList = [item(15, 3), item(20, 5), item(9, 3), item(14, 4)]
sortedList = sorted(itemList, key=lambda item:item.vpw, reverse = True)

#for o in sortedList:
