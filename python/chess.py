# Function to check if a position is valid on an 8x8 chessboard
def is_valid_position(row, col):
    return 1 <= row <= 8 and 1 <= col <= 8

# Function to calculate and print valid movements for a given piece
def calculate_valid_movements(piece_type, start_row, start_col):
    valid_moves = {
        'King': [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)],
        'Queen': [],
        'Bishop': [],
        'Rook': [],
        'Pawn': []
    }

    # Calculate valid moves for the Queen
    if piece_type == 'Queen':
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]
        for dr, dc in directions:
            for step in range(1, 9):
                row = start_row + dr * step
                col = start_col + dc * step
                if is_valid_position(row, col):
                    valid_moves['Queen'].append((row, col))
                else:
                    break

    # Calculate valid moves for the Bishop
    if piece_type == 'Bishop':
        directions = [(1, 1), (-1, -1), (1, -1), (-1, 1)]
        for dr, dc in directions:
            for step in range(1, 9):
                row = start_row + dr * step
                col = start_col + dc * step
                if is_valid_position(row, col):
                    valid_moves['Bishop'].append((row, col))
                else:
                    break

    # Calculate valid moves for the Rook
    if piece_type == 'Rook':
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dr, dc in directions:
            for step in range(1, 9):
                row = start_row + dr * step
                col = start_col + dc * step
                if is_valid_position(row, col):
                    valid_moves['Rook'].append((row, col))
                else:
                    break

    # Calculate valid moves for the Pawn
    if piece_type == 'Pawn':
        directions = [(1, 0), (1, 1), (1, -1)]
        for dr, dc in directions:
            row = start_row + dr
            col = start_col + dc
            if is_valid_position(row, col):
                valid_moves['Pawn'].append((row, col))

    # Print the valid movements
    print(f"Valid movements for {piece_type} at ({start_row},{start_col}):")
    for direction, moves in valid_moves.items():
        if moves:
            moves.sort()  # Sort the valid moves
            print(f"{direction}: {', '.join([f'({row},{col})' for row, col in moves])},", end=" ")
    print()

# Get input from the user
piece_type = input("Enter the piece type (King, Queen, Bishop, Rook, Pawn): ")
start_row = int(input("Enter the starting row position (1 to 8): "))
start_col = int(input("Enter the starting column position (1 to 8): "))

# Check if the input row and column positions are valid
if not is_valid_position(start_row, start_col):
    print("Invalid starting position. Row and column positions must be in the range 1 to 8.")
else:
    calculate_valid_movements(piece_type, start_row, start_col)
