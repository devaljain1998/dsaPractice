n , x = map(int , input().strip().split())
s = input().strip()

#binary of x:
binary_x = bin(x)[2:]

zeros = ''
for i in range(len(s) - len(binary_x)):
    zeros += '0'
    
binary_x = zeros + binary_x


#Finding multiplication power of zero
zero_power = 0
for i in range(len(binary_x)):
    if(binary_x[i] == '1'):
        break
    zero_power += 1
    
zero_multiplication_power = 2 ** zero_power

#Finding multiplication power of after 1's
index_of_first_one = zero_power

main_multiplicative_power = 0

# for i in range(index_of_first_one, len(binary_x)):
#     #If 1 encounters then do nothing
#     #if 0 is encountered then run the recursion
#     #then increase the multiplicative_power by
#     # exp(2, and remainging length of the string)
#     if (binary_x[i] == '0'):
#         main_multiplicative_power += 2 ** (len(binary_x) - i + 1)
    
# ans = zero_multiplication_power * (main_multiplicative_power if main_multiplicative_power else 1)
# print(ans)



#Start dynamic programming
multiplicative_powers = []

#start iterating from the last of the string:
reverse_binary_x = "".join(reversed(binary_x))

for i in range(len(reverse_binary_x) - index_of_first_one):
    #if the character is 1 then do nothing
    #if character is 0
    if (reverse_binary_x[i] == '0'):
        prev_multiplication_sum = 0
        
        for power in multiplicative_powers:
            prev_multiplication_sum += power
            
        multiplication = (2 ** i) + prev_multiplication_sum
        
        multiplicative_powers.append(multiplication)
        
# main_multiplicative_power = multiplicative_powers[-1] if multiplicative_powers != [] else 0

for power in multiplicative_powers:
    if (main_multiplicative_power == 0):
        main_multiplicative_power = power
    else:
        main_multiplicative_power *= power

ans = zero_multiplication_power * (main_multiplicative_power if main_multiplicative_power else 1)
print(ans)