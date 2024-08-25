# Dictionary mapping assembly instruction mnemonics to their opcode values
opcodemap = {
    "beq": "1100011",
    "bne": "1100011",
    "blt": "1100011",
    "bge": "1100011",
    "bltu": "1100011",
    "bgeu": "1100011",
    "auipc": "0010111",
    "lui": "0110111"
}

# Dictionary mapping some instructions to their function values
functionmap = {
    "beq": "000",
    "bne": "001",
    "blt": "100",
    "bge": "101",
    "bltu": "110",
    "bgeu": "111"
}

# Function to convert a decimal number to a binary string
def decimaltobinary(num, width):
    return format(num, '0' + str(width) + 'b')

# Function to assemble an instruction
def assembleinstruction(instruction):
    parts = instruction.replace(",", "").split()  # Split the instruction into parts
    mnemonic = parts[0]  # The first part is the mnemonic (e.g., beq, lui, etc.)
    opcode = opcodemap.get(mnemonic)  # Get the opcode corresponding to the mnemonic
    
    if opcode is None:  # If the mnemonic is not recognized
        return None, "Unknown opcode"
    
    if mnemonic in ["beq", "bne", "blt", "bge", "bltu", "bgeu"]:  # For branch instructions
        rs1 = int(parts[1][1:])  # Extract the source register 1
        rs2 = int(parts[2][1:])  # Extract the source register 2
        imm = int(parts[3])  # Extract the immediate value
        function = functionmap.get(mnemonic)  # Get the function value for the instruction
        
        if function is None:  # If the instruction is not recognized
            return None, "Invalid instruction format"
        
        immbinary = decimaltobinary(imm, 12)  # Convert the immediate value to binary
        # Combine all parts to form the binary instruction
        binaryinstruction = opcode + immbinary[0] + immbinary[2:] + decimaltobinary(rs2, 5) + decimaltobinary(rs1, 5) + function
        return binaryinstruction, None  # Return the binary instruction and no error
        
    elif mnemonic in ["auipc", "lui"]:  # For U-type instructions
        rd = int(parts[1][1:])  # Extract the destination register
        imm = int(parts[2])  # Extract the immediate value
        
        immbinary = decimaltobinary(imm, 20)  # Convert the immediate value to binary
        # Combine all parts to form the binary instruction
        binaryinstruction = opcode + immbinary[:12] + decimaltobinary(rd, 5)
        return binaryinstruction, None  # Return the binary instruction and no error
    
    else:
        return None, "Invalid instruction"  # If the instruction is not recognized


def main():
    inputfile = input("Enter the input file name: ")
    outputfile = input("Enter the output file name: ")

    try:
        with open(inputfile, 'r') as file:
            lines = file.readlines()  # Read all lines from the input file
    except FileNotFoundError:
        print("Error: Input file not found")
        return

    binaryinstructions = []  # List to store binary instructions
    for index, line in enumerate(lines, start=1):
        line = line.strip()  # Remove leading/trailing whitespace
        if not line:  # If the line is empty
            continue
        parts = line.split(':')  # Split the line by ':'
        if len(parts) == 2:  # If it contains a label
            line = parts[1].strip()  # Get the instruction part
        binaryinstr, error = assembleinstruction(line)  # Assemble the instruction
        if error:  # If there is an error in assembling the instruction
            print(f"Error on line {index}: {error}")  # Print the error message
            return
        if binaryinstr:  # If the instruction is assembled successfully
            binaryinstructions.append(binaryinstr)  # Append it to the list of binary instructions

    # Write the binary instructions to the output file
    with open(outputfile, 'w') as file:
        for binaryinstr in binaryinstructions:
            file.write(binaryinstr + '\n')


if __name__ == "__main__":
     main()
