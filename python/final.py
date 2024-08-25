def main():
    inputfile = input("Enter the input file name: ")  # Get the input file name from the user

    try:
        with open(inputfile, 'r') as input_file:  # Open the input file in read mode
            lines = input_file.readlines()  # Read all lines from the input file
    except FileNotFoundError:
        print("Input file not found.")  # Handle the case where input file is not found
        return

    output = []  # List to store the output binary instructions or error messages

    labels = {}  # Dictionary to store labels and their corresponding line numbers

    linenumber = 1  # Initialize line number

    while linenumber <= len(lines):  # Loop through each line of the input file
        line = lines[linenumber - 1].strip()  # Get the line and remove leading and trailing whitespaces

        if not line:  # Ignore empty lines
            linenumber += 1
            continue

        if line.endswith(":"):  # Check if it's a label
            label = line[:-1]  # Remove the colon
            if label in labels:  # Check for duplicate labels
                print(f"Error on line {linenumber}: Duplicate label '{label}'")
                break
            labels[label] = len(output)  # Store the label and its line number
            linenumber += 1
            continue

        tokens = line.split()  # Split the line into tokens based on whitespace

        opcodeb = {"beq": "000", "bne": "001", "blt": "100", "bge": "101", "bltu": "110", "bgeu": "111"}
        opcodeu = {"auipc": "0010111", "lui": "0110111"}

        if tokens[0] in opcodeb:
            encodedinstruction = encodebranchinstruction(tokens, opcodeb, labels, linenumber)
        elif tokens[0] in opcodeu:
            encodedinstruction = encodeunsignedinstruction(tokens, opcodeu)
        else:
            print(f"Error on line {linenumber}: Invalid instruction mnemonic")
            break

        if encodedinstruction:
            output.append(encodedinstruction)

        linenumber += 1

    if output:
        for item in output:
            print(item)
    else:
        print("No errors. Assembly successful.")

def encodebranchinstruction(tokens, opcodemap, labels, currentline):
    opcode = "1100011"
    funct3 = opcodemap[tokens[0]]

    if len(tokens) != 4:  # Check if there are enough operands
        return f"Error: Invalid number of operands for branch instruction on line {currentline}"

    rs1, rs2, imm = tokens[1], tokens[2], tokens[3]

    try:
        imm = int(imm)
    except ValueError:
        return f"Error: Invalid immediate value on line {currentline}"

    if imm in labels:  # If the immediate value is a label
        targetline = labels[imm]  # Get the line number corresponding to the label
        imm = targetline - currentline  # Calculate the relative offset

    immbits = format(imm, '012b')  # Format immediate to 12 bits
    instruction = immbits[0] + immbits[2:8] + rs2 + rs1 + funct3 + immbits[8:12] + immbits[1] + opcode
    return instruction

def encodeunsignedinstruction(tokens, opcodemap):
    opcode = opcodemap[tokens[0]]

    if len(tokens) != 3:  # Check if there are enough operands
        return f"Error: Invalid number of operands for unsigned instruction"

    rd, imm = tokens[1], tokens[2]

    try:
        imm = int(imm)
    except ValueError:
        return f"Error: Invalid immediate value"

    immbits = format(imm, '020b')  # Format immediate to 20 bits
    instruction =immbits + rd + opcode
    return instruction

if __name__ == "__main__":
    main()
