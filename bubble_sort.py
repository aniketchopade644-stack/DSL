def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):   
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


def display_top_five(arr):
    top_five = arr[-5:][::-1]
    print("\nTop five scores are:")
    for score in top_five:   
        print(f"{score:.2f}%")


# Main program
percentages = []

n = int(input("Enter number of students: "))
for i in range(n):
    perc = float(input(f"Enter percentage for student {i+1}: "))
    percentages.append(perc)

print("\nChoose sorting method:")
print("1. Selection Sort")
print("2. Bubble Sort")

choice = int(input("Enter choice (1 or 2): "))

if choice == 1:
    sorted_arr = selection_sort(percentages.copy())
    print("\nSorted using Selection Sort:")
elif choice == 2:
    sorted_arr = bubble_sort(percentages.copy())
    print("\nSorted using Bubble Sort:")
else:
    print("Invalid choice.")
    exit()

print(sorted_arr)
display_top_five(sorted_arr)
