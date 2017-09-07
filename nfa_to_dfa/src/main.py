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
        # if state S has not transition on A then it is represented as an empty list
        for key in self.state_map:
            assert len(self.state_map[key]) == len(self.transitions), "{} is missing a transition".format(key)

        # make sure final states are valid
        for final in self.finals:
            assert final in self.state_map.keys(), "{} not in keys".format(final)

    # dump the nfa as a table
    def dump(self):
        print("NFA:")
        print("\tInitial: {}".format(self.initial))
        print("\tFinals: {}".format(self.finals))
        print("\tTotal: {}".format(self.total))
        print("\tTransitions: {}".format(self.transitions))
        print("\tState keys: {}".format(  sorted(map(int, self.state_map.keys())) ))
        print("\tStates: {}".format(self.states))
        for key in map(str, sorted(map(int, self.state_map.keys()))):
            print("\nState: {}".format(key))
            for trans in self.transitions:
                print("\t{} => {}".format(trans, self.state_map[key][trans]))


# parse in an nfa from stdin
# lots of random map and filter calls since
# that's the slow but easy way to do it
def get_nfa():
    print("Starting NFA input parse...")
    lines = list()

    lines = map(lambda x: x.strip(), fileinput.input())

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


def e_closure_one(nfa, state):
    epi = "E"

    # see it with the given states
    ret = set()
    ret.add(state)

    todo = [state]
    have_seen = list()

    while len(todo) > 0:
        state = str(todo.pop(0))
        if state in have_seen:
            continue
        have_seen.append(state)
        for reachable_state in nfa.state_map[state][epi]:
            todo.append(reachable_state)
            ret.add(reachable_state)

    val = map(str, list(set(ret)))
    return val


def move_one(nfa, state, transition):
    can_access = set()

    assert int(state) > 0, "Invalid state passed in to move_one: {}".format(state)
    assert type(state) == str, "State passed to move one must be a string"

    map(can_access.add, nfa.state_map[state][transition])

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
    e_clos = e_closure(nfa, move(nfa, state, transition))
    result = set(map(str, e_clos))
    return list(result)


def do_work(nfa, state):
    epi = "E"
    results = list()

    if type(state) != list:
        state = [state]

    for transition in nfa.transitions:
        if transition != epi:
            new_state = do_work_trans(nfa, state, transition)
            pair = (transition, new_state)
            results.append(pair)

    return results


def do_sort(states):
    return map(str, sorted(map(int, states)))


def get_start(nfa):
    return do_sort(e_closure(nfa, [nfa.initial]))

# sort a list and then return a comma joined list
# this is because python is too stupid to hash its own lists
# so we use this like a "fingerprint" for a list to use them in sets
# becasue frozensets are stupid
def hashable_list(l):
    return ",".join(do_sort(l))

# debugging
def get_correct_for_three():
    ret = set()
    ret.add("1,3,4,5,6,8,9,10,11,13,14,16,19,20,21,22,24,25,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,24,25,26,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,28,30")
    ret.add("1,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30")
    ret.add("1,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,29,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,24,25,26,27,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,30")
    ret.add("1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30")
    ret.add("1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,29,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30")
    ret.add("1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30")
    assert len(ret) == 13, "Correct has bad size"
    return ret


def main():
    nfa = get_nfa()
    print("reading NFA ... done.\n\n\n")
    epi = "E"

    # debugging
    # correct = get_correct_for_three()

    # nfa.dump()
    # exit(1)

    # the QUEUE used for processing
    todo = list()

    # for debugging
    from_todo = set()

    # what we have seen and the final resulting tuples
    have_seen = set()
    results = list()

    # lookup tables for when the states are reindexed below
    new_to_old = dict()
    old_to_new = dict()

    start = get_start(nfa)

    # print("Start: {}".format(hashable_list(start)))

    todo.append(start)

    # for debugging to see the order that things are processed
    from_todo.add(hashable_list(start))

    print("creating corresponding DFA ...")
    j = 0

    while len(todo) > 0:
        item = todo.pop(0)

        hashable = hashable_list(item)
        if hashable in have_seen:
            continue

        have_seen.add(hashable)
        res = do_work(nfa, item)

        for pair in res:
            transition = pair[0]
            new_state = pair[1]
            # print("Adding from trans: ", transition)
            if new_state:
                todo.append(new_state)
                hashable = hashable_list(new_state)
                from_todo.add(hashable)

        results.append([item, res])
        j += 1


    # reindex all of the resulting states and make the lookup tables
    index = 1
    for i in range(len(results)):
        item = results[i]
        old = hashable_list(item[0])
        new = index
        index += 1
        new_to_old[new] = old
        old_to_new[old] = new

        results[i][0] = new
        print("new DFA state:  {:<5}  -->  {}".format(new, "{" + old + "}"))

    print("done.\n")

    new_states = list()
    new_finals = set()
    # set the correct new index for all of the reachable
    # states for each transition
    for row in results:
        new_items = list()
        index = row[0]
        for (transition, reachable) in row[1]:
            if reachable == []:
                new_items.append((transition, []))
                continue
            key = hashable_list(reachable)
            for final in nfa.finals:
                if final in reachable:
                    new_finals.add(old_to_new[key])
            # print(key)
            new_transition = (transition, old_to_new[key])
            new_items.append(new_transition)

        new_state = [index, new_items]
        new_states.append(new_state)


    # check if initial can be final
    # since for some reason is gets skipped
    for state in get_start(nfa):
        if state in nfa.finals:
            new_finals.add(old_to_new[hashable_list(get_start(nfa))])

    print("final DFA:")
    print("Initial State:  {}".format(old_to_new[hashable_list(get_start(nfa))]))
    print("Final States:   {}".format("{" + hashable_list(list(new_finals)) + "}"))
    print("total States:   {}".format(len(new_states)))

    string = '{:<8}'.format("State")

    for transition in nfa.transitions:
        if transition == epi:
            continue
        string += "{:<10}".format(transition)
    print(string)

    for row in new_states:
        state = row[0]
        pairs = row[1]
        string = "{:<8}".format(str(state))
        for (trans, reachable) in pairs:
            # print(trans, reachable)
            if type(reachable) != list:
                reachable = map(str, [reachable])
            string += "{:<10}".format("{" + ",".join(reachable) + "}")
            if len(reachable) == 0:
                "{:>6}".format("{}")
        print(string)

main()
