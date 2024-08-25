def assign_lift(request_floor, request_movement, lifts):
    positions = []
    for i in range(3):
        current_position, movement, destination = lifts[i]

        if movement == 0:
            a = abs(current_position - request_floor)
            positions.append(a)
        elif movement == 1:
            if current_position < request_floor:
                b = abs(current_position - request_floor)
                positions.append(b)
            else:
                c = abs(current_position - destination) + abs(destination - request_floor)
                positions.append(c)
        elif movement == -1:
            if current_position > request_floor:
                b = abs(current_position - request_floor)
                positions.append(b)
            else:
                c = abs(current_position - destination) + abs(destination - request_floor)
                positions.append(c)
        else:
            exit()

    if positions[0] < positions[1] and positions[0] < positions[2] :
        return (1)
    if positions[1] < positions[0] and positions[1] < positions[2]:
        return (2)
    else:
        return (3)

lifts = []
for i in range(3):
    a = tuple(map(int, input().split()))
    lifts.append(a)

request_floor, request_movement = tuple(map(int, input().split()))
if 0 <= request_floor <= 100 and request_movement in [-1, 1]:
    result = assign_lift(request_floor, request_movement, lifts)
    print(result)
else:
    exit()






    