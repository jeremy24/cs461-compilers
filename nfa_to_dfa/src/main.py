from __future__ import print_function
from __future__ import division
from __future__ import absolute_import

import fileinput




class Nfa:
    def __init__(initial, finals, total):
        self.initial = int(initial)
        self.finals = map(int, finals)
        self.states = range(total)
    def __str__():
        return "NFA:\nInitial: {}  Final: {}  total: {}".format(
            self.initial, self.finals, len(self.states)
        )


def get_nfa():
    lines = list()
    for line in fileinput.input():
        item = line.strip()
        lines.append(item)
        print("["+item+"]")
    initial = lines[0].replace("Initial State:", "").strip()
    initial = int(initial)

    finals = lines[1].replace("Final States:", "").strip()
    finals = finals.replace("{", "").replace("}", "").split(",")
    finals = map(int, finals)

    total = lines[2].replace("Total States:", "").strip()
    total = int(total)

    states = lines[3].replace("State", "").strip().split(" ")
    states = filter(lambda x: x, states)

    trans = map(lambda x: x.split(" "), lines[4:])
    trans = map( lambda y: filter(lambda x: x, y), trans)

    state_map = dict()


    print("Trans: ")
    for t in trans:
        # print(t)
        state = str(t[0])
        values = t[1:]
        values = map(lambda x: x.replace("{", "").replace("}", ""), values)
        values = map(lambda x:  [] if x == "" else map(lambda y: int(y), x.split(",")), values)
        values = zip(states, values)

        state = "0" + state if len(state) == 1 else state

        print("state:", state, "values:", values)

        state_map[str(state)] = values

    for key in sorted(list(state_map.keys())):
        print("State:", key)
        value = state_map[key]
        p = ""
        for trans, newstates in value:
            p += "\t{} => {}\n".format(trans, newstates)

        print(p)

    print("Initial =>", initial)
    print("Final =>", finals)
    print("Total =>", total)
    print("States =>", states)
    



def main():
    get_nfa()

main()   