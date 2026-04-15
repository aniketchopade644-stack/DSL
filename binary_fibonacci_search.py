# Binary Search
def binary_search(l):
    key = int(input("Enter the Roll No to be searched: "))
    low = 0
    high = len(l) - 1

    while low <= high:
        mid = (low + high) // 2
        if key == l[mid]:
            print("The student was present.")
            return
        elif key > l[mid]:
            low = mid + 1
        else:
            high = mid - 1

    print("The student was absent.")


# Fibonacci Search
def fibonacci_search(l):
    key = int(input("Enter the roll no to be searched: "))
    n = len(l)

    fib2 = 0
    fib1 = 1
    fib = fib1 + fib2

    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2

    offset = -1

    while fib > 1:
        i = min(offset + fib2, n - 1)

        if l[i] < key:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif l[i] > key:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i

    if fib1 and offset + 1 < n and l[offset + 1] == key:
        return offset + 1

    return -1


# Input list
def input_list():
    l = []
    n = int(input("Enter the number of students: "))
    for i in range(n):
        rollno = int(input(f"Enter roll no of student {i+1}: "))
        l.append(rollno)

    l.sort()
    return l


# Main
l = []

print("To input the details of students enter 'Yes'")
print("To do binary search enter 'B'")
print("To do Fibonacci Search enter 'F'")
print("To exit type 'No'")

ans = input()

while ans != 'No':
    if ans == 'Yes':
        l = input_list()
    elif ans == 'B':
        binary_search(l)
    elif ans == 'F':
        result = fibonacci_search(l)
        if result != -1:
            print("The student was present.\n")
        else:
            print("The student was absent.\n")

    print("\nEnter next choice (Yes / B / F / No): ", end='')
    ans = input()