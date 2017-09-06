from __future__ import print_function
from __future__ import division
from __future__ import absolute_import

import fileinput




class Nfa:
    def __init__(self, initial, finals, total, transitions, state_map):
        self.initial = int(initial)
        self.finals = map(int, finals)
        self.states = range(total)
        self.total = total
        self.transitions = transitions
        self.state_map = state_map

        # make sure initial state is valid
        assert str(self.initial) in self.state_map.keys()

        # valid lengths of maps
        assert int(total) == len(self.state_map) == len(self.states)

        # make sure every state has options for all transitions
        # no transition ir repped as an empty list []
        for key in self.state_map:
            assert len(self.state_map[key]) == len(self.transitions), "{} is missing a transition".format(key)
  
        # make sure final states are valid
        for final in self.finals:
            assert str(final) in self.state_map.keys(), "{} not in keys".format(final)
        
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
    trans = map( lambda y: filter(lambda x: x, y), trans)

    state_map = dict()

    # print("Trans: ")
    for t in trans:
        state = int(t[0])
        values = t[1:]
        values = map(lambda x: x.replace("{", "").replace("}", ""), values)
        values = map(lambda x:  [] if x == "" else map(lambda y: int(y), x.split(",")), values)
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


def get_accessable(nfa, state, only_do_tran=None):
    trans = nfa.transitions
    states = nfa.state_map
    epi = "E"

    print("\nState: {} Trans: {}".format(state, only_do_tran))

    # print("\nGetting {} for state {}".format(only_do_tran, state))
    can_access = list()    

    # can_do_epi = len(can_access) == 0
    can_do_epi = True

    # if state has a transition for only_do_tran then we
    # cannot follow any epsilion transitions for state
    if only_do_tran is not None:
        if len(states[state][only_do_tran]) > 0:
            # if we have the desired trans we cannot take the epi first
            can_do_epi = False
        else:
            # if it has a episilion trans then it can stay at itself
            if len(states[state][epi]) > 0:
                can_access.append(state)
            

    # loop thru all possible transition states
    is_first = True
    for tran in trans:
        if only_do_tran is not None:
            if tran != only_do_tran:
                continue
        if len(states[state][tran]) == 0:
            pass
        for item in states[state][tran]:
            can_access.append(item)
        i = 0

    
        print("Can do epsilion: ", can_do_epi)
        print("Can access: {}".format(can_access))
        # this list will be reset for EACH possible transition
        # type since each one needs to be searched
        has_visited = list()
        while i < nfa.total:
            for item in can_access:
                item = str(item)
                try:
                    if len(states[item][epi]) == 0:
                        # print("{} has no epis, skipping".format(state))
                        # i += 1
                        continue
                    if item not in has_visited:
                        has_visited.append(item)
                        for epi_state in states[item][epi]:
                            if can_do_epi == False:
                                if int(item) == int(state):
                                    print("Skipping {} cant to epis".format(item))
                                    break
                            print("Checking state {} for epis".format(epi_state))
                            can_access.append(epi_state)
                except KeyError as ex:
                    print("KeyError: ", ex)
                    exit(1)
            i += 1
        is_first = False
    return list(set(can_access))

def make_dfa_states(nfa):
    start = nfa.initial
    trans = nfa.transitions
    states = nfa.state_map

    epi = "E"
    
    print("Start State:", start)
    print("Transitions:", trans)

    keys = list(states.keys())


    keys.sort(key=lambda x: int(x))
    print("Keys:")
    print(keys)

    new_states = list()


    ## debugging
    # l = list()
    # a = get_accessable(nfa, "3", "c")

    # print(a)
    # print("\n\n\n")
    # return

    print("\n")
    for state in keys:
        print("State:", state)

        # if state != 3:
        #     break

        for tran in nfa.transitions:
            if tran == epi:
                continue
            can_access = get_accessable(nfa, state, tran)
            can_access = map(int, can_access)
            can_access = list(set(can_access))
            can_access.sort()

            print("state: {} can access:".format(tran), can_access)
            # can_access = filter(lambda x: x!="", can_access)
            
            if len(can_access) == 0:
                continue
            # print("Adding: ", can_access)
            new_states.append(",".join(map(str,can_access)))

    

    new_states = list(set(new_states))
    new_states = map(lambda x: x.split(","), new_states)

    see_start = False
    see_end = [False for _ in nfa.finals]        
    for states in new_states:
        if str(nfa.initial) in states:
            see_start = True
        for i in range(len(nfa.finals)):
            x = nfa.finals[i]
            if str(x) in states:
                see_end[i] = True

    if not see_start:
        print("Don't see initial state, adding in")
        new_states.append([str(nfa.initial)])

    new_states.sort()

    hashable = map(lambda x: ",".join(x), new_states)
    
    new_states = zip(range(len(new_states)), hashable, new_states)

    table = dict()
    for (state, hashable, l) in new_states:
        table[hashable] = state

    return new_states, table





def main():
    nfa = get_nfa()

    for key in nfa.state_map:
        print("key: {}   {}".format(key, nfa.state_map[key]))

    print()
    dfa_states, dfa_table = make_dfa_states(nfa)
    
    print("\nNew DFA States")
    for state in dfa_states:
        print(state)

    print("\nDFA Table")
    for key in dfa_table:
        print(key, dfa_table[key])
    
    tmp = dfa_states[0]
    print("Tmp state: ", tmp)

    can_see = list()
    on_state = list()

    

    for (index, hashable, l) in dfa_states:
        print("New DFA state:  {}   -->   {}".format(index, "{" + hashable + "}"))





    exit(1)


    for trans in nfa.transitions:
        if trans == "E":
            continue
        gettable = list()
        for can_get in tmp[2]:
            local_gettable = get_accessable(nfa, can_get, trans)
            for item in local_gettable:
                item = int(item)
                if item not in gettable:
                    gettable.append(item)
                gettable.sort()
        gettable = map(str, gettable)
        key = ",".join(gettable)
        new_state = dfa_table[key]
        print("Can access dfa state {} via trans {}".format(new_state, trans))

            
        print("Can see {} from state {}".format(gettable, trans))



    


main() 