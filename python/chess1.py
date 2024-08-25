piece = int(input("Enter a piece (1:King; 2:Queen; 3:Bishop; 4:Rook; 5:Pawn):"))

if piece > 5 or piece < 1:
    #do something
    print("Illegal piece...")
    exit()

pos_X = int(input("Enter the position of the piece (coloumn number):"))
pos_Y = int(input("Enter the position of the piece (row number):"))

step = 1 if piece == 1 or piece == 5 else 7

loc_X, loc_Y = pos_X, pos_Y
# move_up(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 4 or piece == 5:
  #do something
  countStep = 0
  while loc_Y < 8 and countStep < step:
    loc_Y += 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_down(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 4:
  #do something
  countStep = 0
  while loc_Y > 1 and countStep < step:
    loc_Y -= 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_left(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 4:
  #do something
  countStep = 0
  while loc_X < 8 and countStep < step:
    loc_X += 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_right(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 4:
  #do something
  countStep = 0
  while loc_X > 1 and countStep < step:
    loc_X -= 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_up_left(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 3 or piece == 5:
  #do something
  countStep = 0
  while loc_Y < 8 and loc_X > 1 and countStep < step:
    loc_Y += 1
    loc_X -= 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_up_right(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 3 or piece == 5:
  #do something
  countStep = 0
  while loc_Y < 8 and loc_X < 8 and countStep < step:
    loc_Y += 1
    loc_X += 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_down_left(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 3:
  #do something
  countStep = 0
  while loc_Y > 1 and loc_X > 1 and countStep < step:
    loc_Y -= 1
    loc_X -= 1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')

loc_X, loc_Y = pos_X, pos_Y
# move_down_right(loc_X, loc_Y, step):
if piece == 1 or piece == 2 or piece == 3:
  #do something
  countStep = 0
  while loc_Y > 1 and loc_X < 8 and countStep < step:
    loc_Y -= 1
    loc_X +=1
    countStep += 1
    print('(', loc_X, ',', loc_Y, ')', end=',')
  print('')