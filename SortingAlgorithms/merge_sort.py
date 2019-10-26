def split_array(array):
    array_length = len(array)
    midpoint = array_length // 2
    return array[:midpoint], array[midpoint:]

def merge_arrays(array_a, array_b):
    array_a_length = len(array_a)
    array_b_length = len(array_b)

    if array_a_length == 0:
        return array_b
    elif array_b_length == 0:
        return array_a

    idx_a = idx_b = 0
    merged_array = []
    target_length = array_a_length + array_b_length
    while len(merged_array) < target_length:
        if array_a[idx_a] <= array_b[idx_b]:
            merged_array.append(array_a[idx_a])
            idx_a += 1
        else:
            merged_array.append(array_b[idx_b])
            idx_b += 1

        if idx_b == array_b_length:
            merged_array += array_a[idx_a:]
            break
        elif idx_a == array_a_length:
            merged_array += array_b[idx_b:]
            break
    return merged_array

def merge_sort(array):
    array_length = len(array)
    if array_length <= 1:
        return array
    else:
        array_a, array_b = split_array(array)
        return merge_arrays(merge_sort(array_a), merge_sort(array_b))