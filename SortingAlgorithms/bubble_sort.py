def bubble_sort(array: list):
    array_length = len(array)
    for i in range(array_length):
        for j in range(array_length - 1 - i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array