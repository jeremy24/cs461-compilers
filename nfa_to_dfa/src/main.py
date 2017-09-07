from __future__ import print_function
from __future__ import division
from __future__ import absolute_import

import fileinput


class Nfa:
    def __init__(self, initial, finals, total, transitions, state_map):
        self.initial = str(initial)
        self.finals = map(str, finals)
        self.states = [key for key in state_map.keys()]
        self.total = total
        self.transitions = transitions
        self.state_map = state_map


        # make sure initial state is valid
        assert self.initial in self.state_map.keys()

        # valid lengths of maps
        assert int(total) == len(self.state_map) == len(self.states)

        # make sure every state has options for all transitions
        # no transition ir repped as an empty list []
        for key in self.state_map:
            assert len(self.state_map[key]) == len(self.transitions), "{} is missing a transition".format(key)

        # make sure final states are valid
        for final in self.finals:
            assert final in self.state_map.keys(), "{} not in keys".format(final)

    def dump(self):
        print("NFA:")
        print("\tInitial: {}".format(self.initial))
        print("\tFinals: {}".format(self.finals))
        print("\tTotal: {}".format(self.total))
        print("\tTransitions: {}".format(self.transitions))
        print("\tState keys: {}".format(self.state_map.keys()))
        print("\tStates: {}".format(self.states))
    def __str__(self):
        return "NFA:\nInitial: {}  Final: {}  total: {}".format(
            self.initial, self.finals, len(self.states)
        )


def get_nfa():
    print("Starting NFA input parse...")
    lines = list()
    for line in fileinput.input():
        item = line.strip()
        lines.append(item)
        # print("["+item+"]")
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
    trans = map(lambda y: filter(lambda x: x, y), trans)

    state_map = dict()

    # print("Trans: ")
    for t in trans:
        state = int(t[0])
        values = t[1:]
        values = map(lambda x: x.replace("{", "").replace("}", ""), values)
        values = map(lambda x: [] if x == "" else map(lambda y: int(y), x.split(",")), values)
        values = zip(states, values)

        state_map[str(state)] = values

    for key in state_map.keys():
        value = state_map[key]
        tran_map = dict()
        for trans, newstates in value:
            tran_map[trans] = newstates
        state_map[key] = tran_map

    # print("Initial =>", initial)
    # print("Final =>", finals)
    # print("Total =>", total)
    # print("States =>", states)
    nfa = Nfa(initial, finals, total, states, state_map)
    assert isinstance(nfa, Nfa)
    print("NFA built")
    return nfa


def e_closure(nfa, states):
    assert type(states) == list, "States passed to e_closure must be a list"

    results = set()
    for state in states:
        results = results.union(e_closure_one(nfa, state))

    return list(set(results))


e_closure_cache = dict()

def e_closure_one(nfa, state):
    epi = "E"
    global e_closure_cache

    if str(state) in e_closure_cache.keys():
        # print("Cached")
        return e_closure_cache[str(state)]

    # see it with the given states
    ret = set([state])

    todo = [state]
    have_seen = list()

    while len(todo) > 0:
        state = str(todo.pop())

        if state in have_seen:
            continue
        have_seen.append(state)
        for reachable_state in nfa.state_map[state][epi]:
            todo.append(reachable_state)
            ret.add(reachable_state)

    val = map(str, list(set(ret)))
    e_closure_cache[str(state)] = val

    return val


def move_one(nfa, state, transition):
    can_access = set()

    assert int(state) > 0, "Invalid state passed in to move_one: {}".format(state)
    assert type(state) == str, "State passed to move one must be a string"

    for item in nfa.state_map[state][transition]:
        can_access.add(item)

    return can_access


def move(nfa, states, transition):
    res = set()
    assert type(states) == list, "States passed to move must be a list"

    for state in states:
        assert int(state) > 0, "Invalid state given to move: {}".format(state)
        mv = move_one(nfa, state, transition)
        # print("mv {} on {}:   {}".format(state, transition, mv))
        res = res.union(mv)
    return list(res)



def do_work_trans(nfa, state, transition):
    print()
    mv = move(nfa, state, transition)
    e_clos = e_closure(nfa, mv)

    mv = map(str, mv)
    e_clos = map(str, e_clos)

    res = set(mv).union(set(e_clos))

    # print("\nState {} trans: {}".format(state, transition))
    # print("eclos: ", e_clos)
    # print("move: ", mv)
    # print("Result: ", res)

    return list(res)

def do_work(nfa, state):
    epi = "E"
    results = list()

    print("\tIn do work with: {}".format(state))

    if type(state) != list:
        state = [state]


    for transition in nfa.transitions:
        if transition == epi:
            continue
        new_state = do_work_trans(nfa, state, transition)
        pair = (transition, new_state)
        results.append(pair)

    return results



def do_sort(states):
    states = map(int, states)
    states.sort()
    return map(str, states)

def get_start(nfa):
    start = e_closure(nfa, [nfa.initial])
    return do_sort(start)

def hashable_list(l):
    l = do_sort(l)
    return ",".join(l)

def main():
    nfa = get_nfa()
    print("reading NFA ... done.\n\n\n")
    epi = "E"


    # nfa.dump()
    # exit(1)

    todo = list()
    have_seen = list()
    results = list()

    new_to_old = dict()
    old_to_new = dict()

    start = get_start(nfa)

    todo.append(start)
    print("creating corresponding DFA ...")
    j = 0
    stop = 2
    while len(todo) > 0 and j < stop:
        item = todo.pop()

        hashable = hashable_list(item)
        if hashable in have_seen:
            continue

        have_seen.append(hashable)

        # print("Doing work with item: {} of type: {}".format(item, type(item)))
        res = do_work(nfa, item)

        for pair in res:
            transition = pair[0]
            new_state = pair[1]
            print("Adding from trans: ", transition)
            if new_state:
                todo.append(new_state)

        results.append([item, res])
        j += 1

    print("Calculated states for {} states".format(len(have_seen)))

    row = results[0]
    head = hashable_list(row[0])
    print(head)
    can_see = row[1]
    for (trans, reach) in can_see:
        print("\t{}:  {}".format(trans, hashable_list(reach)))


    print("\nTODO")
    for t in todo:
        print(hashable_list(t))
    exit(1)


    # reindex the provided initial state
    index = 1
    # new_to_old[""] = []
    # old_to_new[""] = []

    for i in range(len(results)):
        item = results[i]
        old = hashable_list(item[0])
        new = index
        index += 1
        new_to_old[new] = old
        old_to_new[old] = new

        results[i][0] = new
        print("{:<8}  -->  {}".format(new, old))

    # sort the indexes
    # index = 1
    # for key in old_to_new.keys():
    #     new = index
    #     old_to_new[key] = new
    #     new_to_old[new]  = key
    #     old = key
    #     print("{:<8}  -->  {}".format(new, old))
    #     index += 1


    # for row in results:
    #     print("\n", row[0])
    #     for c in row[1]:
    #         print("\t", c)


    new_states = list()
    # reindex the reachable states
    for row in results:
        new_items = list()
        index = row[0]
        for (transition, reachable) in row[1]:
            if reachable == []:
                new_items.append((transition, []))
                continue
            key = hashable_list(reachable)
            # print(key)
            new_transition = (transition, old_to_new[key])
            new_items.append(new_transition)


        new_state = [index, new_items]
        new_states.append(new_state)

    # print(results[0])
    # print(new_states[0])

    string = '{:<8}'.format("State")

    for transition in nfa.transitions:
        if transition == epi:
            continue
        string += "{:>6}".format(transition)
    print(string)

    for row in new_states:
        state = row[0]
        pairs = row[1]
        string = "{:<8}".format(str(state))
        for (trans, reachable) in pairs:
            # print(trans, reachable)
            if type(reachable) != list:
                reachable = map(str, [reachable])
            string += "{:>6}".format("{" + ",".join(reachable) +"}")
            if len(reachable) == 0:
                "{:>6}".format("{}")
        print(string)

    # for row in

    # # exit(1)
    # header = map(lambda x: x[1], reresults[0])
    #
    # string = "{:<8}".format("State")
    # for state in header:
    #     string += "{:<8}".format(state)
    # print(string)
    #
    # for row in reresults:
    #     state = row[0][0]
    #     string = "{:<8}".format(state)
    #     print("\n")
    #     for x in row:
    #         print(x)
    #     for chunk in row:
    #         chunk = map(str, chunk[2])
    #         string += "{:<8}".format("{" + "".join(chunk) + "}")
    #
    #         # print(string)
    #
    #

    # for row in results:
    #     print(row)


# def main():
#     nfa = get_nfa()
#     print("reading NFA ... done.\n\n\n")
#     epi = "E"
#
#     # precompute all the e_closures and cache them
#     # ahead of time for speed
#     # for state in nfa.states:
#     #     e_closure_one(nfa, str(state + 1))
#
#
#     # for the search
#     to_do = list()
#     have_seen = list()
#
#     start = e_closure(nfa, nfa.initial)
#
#     start = map(int, start)
#     start.sort()
#     start = map(str, start)
#
#     results = list()
#     to_do.append(start)
#
#     print("creating corresponding DFA ...")
#
#     while len(to_do) > 0:
#         item = to_do.pop()
#         hashable = ",".join(item)
#         if hashable in have_seen:
#             continue
#
#         have_seen.append(hashable)
#         res = do_work(nfa, item)
#
#         results.append([item, res])
#         for (trans, l) in res:
#             for x in l:
#                 to_do.append(x)
#
#
#
#
#
#     reindex = dict()
#     rerev = dict()
#
#     results.sort(key=lambda l: l[0])
#
#     for row in results:
#         start_state = row[0]
#         print("\nState: ", start_state)
#         # print(row[1])
#         for transition in row[1]:
#             t_type = transition[0]
#             can_reach = transition[1:]
#             print("On {} can reach:".format(t_type))
#             print("\t", can_reach)
#
#     # sort the states for printing later
#     for row in results:
#         row[0] = map(int, row[0])
#         row[0].sort()
#         row[0] = map(str, row[0])
#
#
#
#     for row in results:
#         print(row)
#
#     exit(1)

    # for i in range(len(results)):
    #     old = ",".join(results[i][0])
    #     print("old: ", old)
    #     new = i + 1
    #     reindex[new] = old
    #     rerev[old] = new
    #     results[i][0] = new
    #
    # for key in reindex:
    #     print("new DFA state:   {}   -->  {}".format(
    #         key, "{" + reindex[key] + "}"
    #     ))
    # print("done.\n")

    # finals = list()
    # for res in results:
    #     state = res[0]
    #     for (trans, states) in res[1]:
    #         # print("states:", states)
    #         j = 0
    #         for big_state in states:
    #             for final in nfa.finals:
    #                 if final in big_state:
    #                     # print("state: ", state)
    #                     try:
    #                         state = map(int, big_state)
    #                     except Exception as ex:
    #                         print(ex)
    #                         print("FAILURE")
    #                         exit(1)
    #                     state.sort()
    #                     state = map(str, state)
    #                     state = ",".join(state)
    #                     finals.append(state)
    #             j += 1
    # finals = list(set(finals))
    # finals.sort()
    # # finals = map(lambda k: (rerev[k], k), finals)
    # finals = map(lambda k: int(rerev[k]), finals)
    #
    # start = ",".join(start)
    # start = (rerev[start], start)
    #
    # finals = map(str, finals)
    #
    # print("final DFA:")
    # print("Initial State:  {}".format(start[0]))
    # print("Final States:  {}".format("{" + ",".join(finals) + "}"))
    # print("Total States:  {}".format(len(rerev.keys())))

    # reresults = list()
    #
    # for item in results:
    #     id = item[0]
    #     states = item[1]
    #     restates = list()
    #     for (trans, l) in states:
    #         ll = []
    #         for chunk in l:
    #             chunk = map(int, chunk)
    #             chunk.sort()
    #             chunk = map(str, chunk)
    #             key = ",".join(chunk)
    #             ll.append(rerev[key])
    #         restates.append((id, trans, ll))
    #     reresults.append(restates)
    #
    # # exit(1)
    # header = map(lambda x: x[1], reresults[0])
    #
    # string = "{:<8}".format("State")
    # for state in header:
    #     string += "{:<8}".format(state)
    # print(string)
    #
    # for row in reresults:
    #     state = row[0][0]
    #     string = "{:<8}".format(state)
    #     print("\n")
    #     for x in row:
    #         print(x)
    #     for chunk in row:
    #         chunk = map(str, chunk[2])
    #         string += "{:<8}".format("{" + "".join(chunk) + "}")
    #
    #         # print(string)
    #
    #




main()
