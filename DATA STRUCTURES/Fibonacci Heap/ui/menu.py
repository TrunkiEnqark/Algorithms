def choose_option(lst) -> int:
    while True:
        i = 1
        for item in lst:
            print(f'{i}. {item}')
            i += 1
        choosen = int(input(f'Choose 1 option from 1 to {len(lst)}: '))
        if choosen in range(1, len(lst) + 1):
            return choosen
        print("Error: Can't find your option, please press again")
        
