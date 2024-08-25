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
    parts = instruction.replace(",", "").split()
    mnemonic = parts[0]
    opcode = opcodemap.get(mnemonic)
    
    if opcode is None:
        return None, "Unknown opcode"
    
    if mnemonic in ["beq", "bne", "blt", "bge", "bltu", "bgeu"]:
        rs1 = int(parts[1][1:])
        rs2 = int(parts[2][1:])
        imm = int(parts[3])
        function = functionmap.get(mnemonic)
        
        if function is None:
            return None, "Invalid instruction format"
        
        immbinary = decimaltobinary(imm, 12)
        binaryinstruction = opcode + immbinary[0] + immbinary[2:] + decimaltobinary(rs2, 5) + decimaltobinary(rs1, 5) + function
        return binaryinstruction, None
        
    elif mnemonic in ["auipc", "lui"]:
        rd = int(parts[1][1:])
        imm = int(parts[2])
        
        immbinary = decimaltobinary(imm, 20)
        binaryinstruction = opcode + immbinary[:12] + decimaltobinary(rd, 5)
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
    for index, line in enumerate(lines, start=1):
        #line = line.strip()
        if not line:
            continue
        parts = line.split(' ')
        P1=parts[0]
        P2=parts[1].split(',')
        if len(parts) == 2:
            line = parts[1].strip()
        binaryinstr, error = assembleinstruction(line)
        if error:
            print(f"Error on line {index}: {error}")
            return
        if binaryinstr:
            binaryinstructions.append(binaryinstr)

    with open(outputfile, 'w') as file:
        for binaryinstr in binaryinstructions:
            file.write(binaryinstr + '\n')


if __name__ == "__main__":
     main()
