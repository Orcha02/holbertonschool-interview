#!/usr/bin/python3
""" Method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    num_of_boxes = len(boxes)
    list_of_keys = boxes[0]
    box_locked = [False] + [True] * (num_of_boxes - 1)
    for key in list_of_keys:
        if ((key < num_of_boxes) and (box_locked[key] is True)):
            box_locked[key] = False
            list_of_keys.extend(boxes[key])
    return not any(box_locked)

# extend()-> Adds elements to the end of the list
# not-> Returns True if the statement is not "True" literally, otherwise returns False.
# any()-> Returns True if any item in "AN ITERABLE" are true, otherwise returns False
