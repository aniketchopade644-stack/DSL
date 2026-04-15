 
def input_roll_numbers(): 
    roll_numbers = []    
    n = int(input("Enter number of students who attended the training: "))     
    for i in range(n): 
        roll = int(input(f"Enter roll number of student {i+1}: "))        
        roll_numbers.append(roll)     
    return roll_numbers 
 
def linear_search(roll_numbers, key):   
    for roll in roll_numbers: 
        if roll == key:             
            return True    
    return False 
 
# Function for Sentinel Search 
def sentinel_search(roll_numbers, key): 
    n = len(roll_numbers)     
    last = roll_numbers[-1]     
    roll_numbers[-1] = key  
    # Set last element as key (sentinel) 
    i = 0     
    while roll_numbers[i] != key:         
        i += 1 
 
    roll_numbers[-1] = last   # Restore last element 
 
    if (i < n - 1) or (roll_numbers[-1] == key): 
        return True    
    else: 
        return False 
 
# Main Program 
roll_numbers = input_roll_numbers() 
 
key = int(input("\nEnter roll number to search: ")) 
 
found_linear = linear_search(roll_numbers, key) 
print("Linear Search: ", "Student attended." if found_linear else "Student did not attend.") 
 
found_sentinel = sentinel_search(roll_numbers.copy(), key)
print("Sentinel Search: ", "Student attended." if found_sentinel else "Student did not attend.")
