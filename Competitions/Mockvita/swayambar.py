#Declaring constants
MOJITO = 'm'
RUM = 'r'

#declaring dictionary for keeping track of preferences
bride_preference = {RUM: 0, MOJITO: 0}
groom_preference = {RUM: 0, MOJITO: 0}

# def main():
#     pairs = int(input())
#     #fetching bride preferences:
#     brides = input()
#     if brides == '' or brides is None: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
#     for bride in brides:
#         if bride == RUM:
#             bride_preference[RUM] += 1
#         elif bride == MOJITO: bride_preference[MOJITO] += 1
#         else: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
        
#     #fetching groom preferences:
#     grooms = input()
#     if grooms == '' or grooms is None: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
#     for groom in grooms:
#         if groom == RUM:
#             groom_preference[RUM] += 1
#         elif groom == MOJITO: groom_preference[MOJITO] += 1
#         else: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
        
#     #The final answer will be the absolute difference between the
#     #rum and the mojito
#     answer = abs(bride_preference[RUM] - groom_preference[RUM]) +\
#         abs(bride_preference[MOJITO] - groom_preference[MOJITO])
        
#     print(answer)


# if __name__ == "__main__":
#     main()

pairs = int(input())
#fetching bride preferences:
brides = input()
if brides == '' or brides is None: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
for bride in brides:
    if bride == RUM:
        bride_preference[RUM] += 1
    elif bride == MOJITO: bride_preference[MOJITO] += 1
    else: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
    
#fetching groom preferences:
grooms = input()
if grooms == '' or grooms is None: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
for groom in grooms:
    if groom == RUM:
        groom_preference[RUM] += 1
    elif groom == MOJITO: groom_preference[MOJITO] += 1
    else: raise ValueError("Only 'r' and 'm' values are excpted for brides and groom.")
    
#The final answer will be the absolute difference between the
#rum and the mojito
answer = abs(bride_preference[RUM] - groom_preference[RUM]) +\
    abs(bride_preference[MOJITO] - groom_preference[MOJITO])
    
print(answer)