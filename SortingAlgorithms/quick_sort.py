def quick_sort(arr):
    if len(arr) < 2:
        return arr
    pivot = arr[0]
    less = [elem for elem in arr if elem < pivot]
    more = [elem for elem in arr if elem > pivot]
    return quick_sort(less) + [pivot] + quick_sort(more)
