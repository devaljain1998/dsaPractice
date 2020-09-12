import copy

def is_valid(target):
    return target >= 0


combinations = []


def get_combination_sum(numbers, index, target, combination):
    if target == 0:
        combinations.append(combination)
        return

    for i in range(index, len(numbers)):
        number = numbers[i]
        new_sum = target - number
        if is_valid(new_sum):
            # place
            new_combination = copy.deepcopy(combination)
            new_combination.append(number)

            # backtrack
            get_combination_sum(numbers, i + 1, new_sum, new_combination)


# A : [ 8, 10, 6, 11, 1, 16, 8 ]
# B : 28
# op = [[1 6 10 11 ] [1 8 8 11 ] [1 11 16 ]]

numbers = [ 8, 10, 6, 11, 1, 16, 8 ]
combination = []
target = 28

numbers.sort()

get_combination_sum(numbers, 0, target, combination)
print(combinations)
