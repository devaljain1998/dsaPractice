def evenDigitsNumber(a):
    even_digits = 0
    
    for num in a:
        if len(str(num)) % 2 == 0: even_digits += 1
        
    return even_digits

print(evenDigitsNumber([12, 134, 111, 1111, 10]))