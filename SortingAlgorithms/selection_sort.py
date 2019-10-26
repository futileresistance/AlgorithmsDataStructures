def selection_sort(array: list): 
    array_length = len(array)
    for i in range(array_length - 1):
        min_idx = i
        for j in range(i + 1, array_length):
            if array[j] < array[min_idx]:
                min_idx = j
        array[i], array[min_idx] = array[min_idx], array[i]
    return array