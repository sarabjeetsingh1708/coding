def assembleinstruction(instruction, labels, linenumber):
    opcodemap = {
        'jal': '1101111'
    }
    
    parts = instruction.split()
    
    if len(parts) == 0:  # Empty line
        return None, None
    elif len(parts) == 1:  # Label
        labels[parts[0][:-1]] = linenumber  # Remove the ':' from label and store its line number
        return None, None
    elif len(parts) == 2:  # Instruction without a label
        opcode = opcodemap.get(parts[0])
        if opcode:
            try:
                imm = int(parts[1])
                if imm < -524288 or imm > 1000000:  # Check immediate value range
                    return None, f"Immediate value out of range on line {linenumber}"
                binaryinstruction = f"{opcode}{'{0:020b}'.format(imm & 0xFFFFF)}"
                return binaryinstruction, None
            except ValueError:
                return None, f"Invalid immediate value on line {linenumber}"
        else:
            return None, f"Unknown instruction on line {linenumber}: {parts[0]}"
    else:
        return None, f"Invalid instruction format on line {linenumber}"

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

    lines = readinputfile(inputfile)
    if not lines:
        return
    
    labels = {}
    binaryinstructions = []
    errors = []

    for linenumber, line in enumerate(lines, start=1):
        line = line.strip()
        if not line:
            continue
        binaryinstr, error = assembleinstruction(line, labels, linenumber)
        if error:
            errors.append(error)
        if binaryinstr:
            binaryinstructions.append(binaryinstr)

    if errors:
        writeoutputfile(outputfile, errors[0])  # Write only the first error
    else:
        content = '\n'.join(binaryinstructions)
        writeoutputfile(outputfile, content)

if __name__ == "__main__":
    main()
