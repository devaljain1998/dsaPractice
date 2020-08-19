#from crio.python.io import PrintMatrix


def twoSum(numbers, target):
    indexes = [0, 0]

    #Sorting the numbers first:
    numbers.sort()
    
    left_pointer, right_pointer = 0, len(numbers) - 1
    
    while(left_pointer < right_pointer):
        temp_sum = numbers[left_pointer][0] + numbers[right_pointer][0]
        
        if temp_sum == target:
            indexes = [numbers[left_pointer][1], numbers[right_pointer][1]]
            break
        elif temp_sum < target:
            left_pointer += 1
        else:
            right_pointer -= 1
    
    return indexes

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    # nums = [int(i) for i in nums]
    
    no = []
    for i in range(len(nums)):
        no.append((int(nums[i]), i))
    
    target = int(input())
    result = twoSum(no, target)
    print(f'{result[0]} {result[1]}')
    
