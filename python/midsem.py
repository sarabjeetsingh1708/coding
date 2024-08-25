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

functionmap = {
    "beq": "000",
    "bne": "001",
    "blt": "100",
    "bge": "101",
    "bltu": "110",
    "bgeu": "111"
}

def decimaltobinary(num, width):
    return format(num, '0' + str(width) + 'b')

def assembleinstruction(instruction):
    parts = instruction.replace(",", " ").split()
    mnemonic = parts[0]
    opcode = opcodemap.get(mnemonic)
    
    if opcode is None:
        return None, "Unknown opcode"
    
    if mnemonic in ["beq", "bne", "blt", "bge", "bltu", "bgeu"]:
        if len(parts) != 4:
            return None, "Invalid instruction format"
        rs1, rs2 = parts[1][1:], parts[2][1:]
        try:
            imm = int(parts[3])
        except ValueError:
            return None, "Invalid immediate value"
        
        function = functionmap.get(mnemonic)
        
        if function is None:
            return None, "Invalid instruction format"
        
        immbinary = decimaltobinary(imm, 12)
        binaryinstruction = opcode + immbinary[0] + immbinary[2:] + decimaltobinary(int(rs2), 5) + decimaltobinary(int(rs1), 5) + function
        return binaryinstruction, None
        
    elif mnemonic in ["auipc", "lui"]:
        if len(parts) != 3:
            return None, "Invalid instruction format"
        rd = parts[1][1:]
        try:
            imm = int(parts[2])
        except ValueError:
            return None, "Invalid immediate value"
        
        immbinary = decimaltobinary(imm, 20)
        binaryinstruction = opcode + immbinary[:12] + decimaltobinary(int(rd), 5)
        return binaryinstruction, None
    
    else:
        return None, "Invalid instruction"

def main():
    inputfile = input("Enter the input file name: ")
    outputfile = input("Enter the output file name: ")

    try:
        with open(inputfile, 'r') as file:
            lines = file.readlines()
    except FileNotFoundError:
        print("Error: Input file not found")
        return

    binaryinstructions = []
    for line in lines:
        line = line.strip()
        if not line:
            continue
        binaryinstr, error = assembleinstruction(line)
        if error:
            print(f"Error: {error}")
            return
        if binaryinstr:
            binaryinstructions.append(binaryinstr)

    with open(outputfile, 'w') as file:
        for binaryinstr in binaryinstructions:
            file.write(binaryinstr + '\n')


if __name__ == "__main__":
     main()
