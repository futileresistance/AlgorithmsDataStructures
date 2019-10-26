def insertion_sort(array: list):
	array_length = len(array)
	for i in range(1, array_length):
		n = i
		while n > 0 and array[n] < array[n - 1]:
			array[n], array[n - 1] = array[n - 1], array[n]
			n -= 1
	return array