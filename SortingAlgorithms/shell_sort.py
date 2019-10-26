def shell_sort(array):
    sublistcount = len(array)//2
    while sublistcount > 0:
        for start_position in range(sublistcount):
            gap_insertion_sort(array, start_position, sublistcount)
        sublistcount = sublistcount // 2
    return array

def gap_insertion_sort(array,start,gap):
    array_length = len(array)
    for i in range(start + gap, array_length, gap):
        current_value = array[i]
        position = i
        while position >= gap and array[position - gap] > current_value:
            array[position] = array[position-gap]
            position = position - gap
        array[position] = current_value
