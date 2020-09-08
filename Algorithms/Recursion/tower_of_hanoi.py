SOURCE = 'S'
DESTINATION = 'D'
HELPER = 'H'

def tower_of_hanoi(n:int, source, destination, helper):
    if n == 1:
        print(f'Moving plate {n} from {source} to {destination}')
    else:
        tower_of_hanoi(n - 1, source, helper, destination)
        print(f'Moving plate {n} from {source} to {destination}')
        tower_of_hanoi(n - 1, helper, destination, source)
        
tower_of_hanoi(2, SOURCE, DESTINATION, HELPER)