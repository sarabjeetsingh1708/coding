def assembleinstruction(instruction, labels=None, linenumber=None):
    opcodemap = {
        "beq": "1100011",
        "bne": "1100011",
        "blt": "1100011",
        "bge": "1100011",
        "bltu": "1100011",
        "bgeu": "1100011",
        "auipc": "0010111",
        "lui": "0110111",
        'jal': '1101111'
    }

    functionmap = {
        "beq": "000",
        "bne": "001",
        "blt": "100",
        "bge": "101",
        "bltu": "110",
        "bgeu": "111"
    }

    if labels is None:  # Assembling single instruction
        parts = instruction.replace(",", "").split()
    else:  # Assembling instruction in a file with labels
        parts = instruction.split()

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

        immbinary = format(imm, '012b')
        binaryinstruction = opcode + immbinary[0] + immbinary[2:] + format(rs2, '05b') + format(rs1, '05b') + function
        return binaryinstruction, None

    elif mnemonic in ["auipc", "lui"]:
        rd = int(parts[1][1:])
        imm = int(parts[2])

        immbinary = format(imm, '020b')
        binaryinstruction = opcode + immbinary[:12] + format(rd, '05b')
        return binaryinstruction, None

    elif mnemonic == 'jal':
        rd = int(parts[1][1:])
        imm = int(parts[2])

        if labels is None or linenumber is None:
            return None, "Labels and line number required for 'jal' instruction assembly."

        if parts[3] in labels:
            target_address = labels[parts[3]]
        else:
            return None, f"Label '{parts[3]}' not found."

        imm = target_address - linenumber

        if imm < -524288 or imm > 1048575:  # Check immediate value range
            return None, f"Immediate value out of range on line {linenumber}"

        immbinary = format(imm, '020b')
        binaryinstruction = opcode + immbinary[:20] + format(rd, '05b')
        return binaryinstruction, None

    else:
        return None, "Invalid instruction"


def readinputfile(inputfile):
    try:
        with open(inputfile, 'r') as f:
            lines = f.readlines()
        return lines
    except FileNotFoundError:
        print(f"Error: File '{inputfile}' not found.")
        return []


def writeoutputfile(outputfile, content):
    try:
        with open(outputfile, 'w') as f:
            f.write(content)
    except FileNotFoundError:
        print(f"Error: Unable to write to file '{outputfile}'.")


def main():
    inputfile = input("Enter the input filename: ")
    outputfile = input("Enter the output filename: ")

    try:
        with open(inputfile, 'r') as file:
            lines = file.readlines()
    except FileNotFoundError:
        print("Error: Input file not found")
        return

    labels = {}
    binaryinstructions = []
    errors = []

    for i, line in enumerate(lines, start=1):
        line = line.strip()
        if not line:
            continue
        parts = line.split(':')
        if len(parts) == 2:  # Label found
            labels[parts[0]] = i
            line = parts[1].strip()

        binaryinstruction, error = assembleinstruction(line, labels, i)
        if error:
            print(f"Error on line {i}: {error}")
            return
        if binaryinstruction:
            binaryinstructions.append(binaryinstruction)

    content = '\n'.join(binaryinstructions)
    writeoutputfile(outputfile, content)


if __name__ == "__main__":
    main()
