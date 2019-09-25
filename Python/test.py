def func(*args, **kwargs):
    print("Args:")
    for a in args:
        print(a, type(a))

    print("KArgs:")
    for kw, value in kwargs.items():
        print(kw, value)

    if kwargs['a']:
        print("exists")

        #Giving Error:
        #Have to test
    # if kwargs['c']:
    #     print("exists")
    # else:
    #     print('Not exists')

func(100, 25, a=5, b="Hello World")