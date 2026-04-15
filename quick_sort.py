def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Input: student percentages
percentages = [78.5, 92.3, 85.0, 67.4, 88.9, 91.2, 73.6, 95.4, 82.1, 89.7]

print("Original percentages:", percentages)

# Sort using quick sort
quick_sort(percentages, 0, len(percentages) - 1)

print("Sorted percentages:", percentages)

# Display top five scores
print("Top five scores:", percentages[-5:])
