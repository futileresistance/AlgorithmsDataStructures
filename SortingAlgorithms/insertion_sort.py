def insertion_sort(array: list):
	array_length = len(array)
	for i in range(1, array_length):
		current_value = array[i]
		position = i
		while position > 0 and array[position] < array[position - 1]:
			array[position], array[position - 1] = array[position - 1], array[position]
			position -= 1
	return array
