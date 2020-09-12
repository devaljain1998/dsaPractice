def get_last_soldier(soldiers, n, k, prev):
    if len(soldiers) == 1:
        return soldiers[0]
    
    death = (prev + k - 1) % n

    # delete the died soldier:
    del soldiers[death]
    
    return get_last_soldier(soldiers, n - 1, k, death)

n = 5
k = 2
soldiers = [i for i in range(1, n + 1)]

print(get_last_soldier(soldiers, n, k, 0))