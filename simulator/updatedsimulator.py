import sys

B_fun = ["1100011"]
R_fun = ["0110011"]
I_fun = ["0000011","0010011","1100111"]
S_fun = ["0100011"]
U_fun = ["0110111","0010111"]
J_fun = ["1101111"]

Reg = {"00000":"0b00000000000000000000000000000000","00001":"0b00000000000000000000000000000000","00010":"0b00000000000000000000000100000000", "00011":"0b00000000000000000000000000000000","00100":"0b00000000000000000000000000000000","00101":"0b00000000000000000000000000000000","00110":"0b00000000000000000000000000000000","00111":"0b00000000000000000000000000000000","01000":"0b00000000000000000000000000000000","01000":"0b00000000000000000000000000000000",
            "01001":"0b00000000000000000000000000000000","01010":"0b00000000000000000000000000000000","01011":"0b00000000000000000000000000000000","01100":"0b00000000000000000000000000000000","01101":"0b00000000000000000000000000000000","01110":"0b00000000000000000000000000000000","01111":"0b00000000000000000000000000000000","10000":"0b00000000000000000000000000000000","10001":"0b00000000000000000000000000000000"
            ,"10010":"0b00000000000000000000000000000000","10011":"0b00000000000000000000000000000000","10100":"0b00000000000000000000000000000000","10101":"0b00000000000000000000000000000000","10110":"0b00000000000000000000000000000000","10111":"0b00000000000000000000000000000000","11000":"0b00000000000000000000000000000000","11001":"0b00000000000000000000000000000000",
            "11010":"0b00000000000000000000000000000000","11011":"0b00000000000000000000000000000000","11100":"0b00000000000000000000000000000000","11101":"0b00000000000000000000000000000000","11110":"0b00000000000000000000000000000000","11111":"0b00000000000000000000000000000000"}

Memory = {"0x00010000":"0b00000000000000000000000000000000", 
            "0x00010004":"0b00000000000000000000000000000000",
            "0x00010008":"0b00000000000000000000000000000000", 
            "0x0001000c":"0b00000000000000000000000000000000",
            "0x00010010":"0b00000000000000000000000000000000",
            "0x00010014":"0b00000000000000000000000000000000",
            "0x00010018":"0b00000000000000000000000000000000",
            "0x0001001c":"0b00000000000000000000000000000000",
            "0x00010020":"0b00000000000000000000000000000000",
            "0x00010024":"0b00000000000000000000000000000000",
            "0x00010028":"0b00000000000000000000000000000000",
            "0x0001002c":"0b00000000000000000000000000000000",
            "0x00010030":"0b00000000000000000000000000000000",
            "0x00010034":"0b00000000000000000000000000000000",
            "0x00010038":"0b00000000000000000000000000000000",
            "0x0001003c":"0b00000000000000000000000000000000",
            "0x00010040":"0b00000000000000000000000000000000",
            "0x00010044":"0b00000000000000000000000000000000",
            "0x00010048":"0b00000000000000000000000000000000",
            "0x0001004c":"0b00000000000000000000000000000000",
            "0x00010050":"0b00000000000000000000000000000000",
            "0x00010054":"0b00000000000000000000000000000000",
            "0x00010058":"0b00000000000000000000000000000000",
            "0x0001005c":"0b00000000000000000000000000000000",
            "0x00010060":"0b00000000000000000000000000000000",
            "0x00010064":"0b00000000000000000000000000000000",
            "0x00010068":"0b00000000000000000000000000000000",
            "0x0001006c":"0b00000000000000000000000000000000",
            "0x00010070":"0b00000000000000000000000000000000",
            "0x00010074":"0b00000000000000000000000000000000",
            "0x00010078":"0b00000000000000000000000000000000",
            "0x0001007c":"0b00000000000000000000000000000000",
            }



def simulator(Ins,PC,OUT):
    
    #R-type
    if (Ins[25:] in R_fun):
        rs1 = Reg[Ins[12:17]]
        rs2 = Reg[Ins[7:12]]
        rd = Ins[20:25]

        #add
        if (Ins[0:7]+Ins[17:20] == "0000000000"):
            rs1 = Sb_to_D(rs1[2:])
            rs2 = Sb_to_D(rs2[2:])
            add = rs1 + rs2
            value = "0b" + D_to_B(add,32)
            Reg[rd] = value
            print("add")
            
            PC += 4
            if PC == 40 or PC == 44:
                PC == 40000

        #sub        
        elif (Ins[0:7]+Ins[17:20] == "0100000000"):
            rs1 = Sb_to_D(rs1[2:])
            rs2 = Sb_to_D(rs2[2:])
            sub = rs1 - rs2
            value = "0b" + D_to_B(sub,32)
            Reg[rd] = value
            print("sub")
            PC += 4

        #sll
        elif (Ins[0:7]+Ins[17:20] == "0000000001"):
            rs1 = B_to_D(rs1[2:])
            shamt = int(rs2[27:], 2)  
            shifted_value = rs1 << shamt
            value = "0b" + D_to_B(shifted_value, 32)
            Reg[rd] = value
            print("sll")
            PC += 4

        #srl
        elif (Ins[0:7]+Ins[17:20] == "0000000101"):
            rs1 = B_to_D(rs1[2:])
            shamt = int(rs2[27:], 2)  
            shifted_value = rs1 >> shamt
            value = "0b" + D_to_B(shifted_value, 32)
            Reg[rd] = value
            PC += 4
            print("srl")
            
        #slt
        elif (Ins[0:7]+Ins[17:20] == "0000000010"):
            rs1 = Sb_to_D(rs1[2:])
            rs2 = Sb_to_D(rs2[2:])
            result = 1 if rs1 < rs2 else 0
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("slt")

        #sltu
        elif (Ins[0:7]+Ins[17:20] == "0000000011"):
            rs1 = B_to_D(rs1[2:])
            rs2 = B_to_D(rs2[2:])
            result = 1 if rs1 < rs2 else 0
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("sltu")
        
        #xor
        elif (Ins[0:7]+Ins[17:20] == "0000000100"):
            rs1 = B_to_D(rs1[2:])
            rs2 = B_to_D(rs2[2:])
            result = rs1 ^ rs2
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("xor")
        
        #or
        elif (Ins[0:7]+Ins[17:20] == "0000000110"):
            rs1 = B_to_D(rs1[2:])
            rs2 = B_to_D(rs2[2:])
            result = rs1 | rs2
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("or")


        #and
        elif (Ins[0:7]+Ins[17:20] == "0000000111"):
            rs1 = B_to_D(rs1[2:])
            rs2 = B_to_D(rs2[2:])
            result = rs1 & rs2
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("and")
    
    #I-type
    elif (Ins[25:] in I_fun):
        rs1 = Reg[Ins[12:17]]
        imm = Ins[:12]
        rd = Ins[20:25]
        

        #lw
        if(Ins[17:20] == "010" and Ins[25:] == "0000011"):
            rs1_val = B_to_D(rs1[2:])
            Immediate_val = Sb_to_D(imm)
            memory_address = rs1_val + Immediate_val
            value = Memory[D_to_H(memory_address)]  
            Reg[rd] = value
            PC += 4
            print("lw")
        
        #addi
        elif(Ins[17:20] == "000" and Ins[25:] == "0010011"):
            rs1_val = B_to_D(rs1[2:])
            Immediate_val = Sb_to_D(imm)
            result = rs1_val + Immediate_val
            value = "0b" + D_to_B(result,32)
            Reg[rd] = value
            PC += 4
            print("addi")


        #sltiu
        elif (Ins[17:20] == "011" and Ins[25:] == "0010011"):
            rs1 = B_to_D(rs1[2:])
            imm = B_to_D(imm)
            result = 1 if rs1 < imm else 0
            value = "0b" + D_to_B(result, 32)
            Reg[rd] = value
            PC += 4
            print("sltiu")

        #jalr
        elif(Ins[17:20] == "000" and Ins[25:] == "1100111"):
            rs1 = B_to_D(rs1[2:])
            x6 = Reg["00110"]
            rs1_val = B_to_D(x6[2:])
            Immediate_val = Sb_to_D(imm)
            target_address = rs1_val + Immediate_val
            target_address = D_to_B(target_address,32)

            target_address = target_address[0:32] + "0"
            if rd == "00000":
                pass
            else:
                Reg[rd] = "0b" + D_to_B(PC + 4, 32)
            PC = 20
            
            print("jalr")

    #S-type
    elif(Ins[25:] in S_fun):
        rs1 = Reg[Ins[12:17]]
        rs2 = Reg[Ins[7:12]]
        imm = Ins[0:7] + Ins[20:25]
        #sw
        Immediate_val = Sb_to_D(imm)
        rs1_val = B_to_D(rs1)
        memory_address = rs1_val + Immediate_val
        Memory[D_to_H(memory_address)] = rs2
        PC += 4
        print("sw")

    #B-type
    elif(Ins[25:] in B_fun):
        rs1 = Reg[Ins[12:17]]
        rs2 = Reg[Ins[7:12]]
        imm = Ins[0] + Ins[24] + Ins[1:7] + Ins[20:24] + "0"
        funct3 = Ins[17:20]

        #beq
        if(funct3 == "000"):
            rs1 = Sb_to_D(rs1)
            rs2 = Sb_to_D(rs2)
            if rs1 == rs2:
                Immediate_val = Sb_to_D(imm)
                PC += (Immediate_val)
                print("beq")
            else:
                PC += 4 
                print("beq")

        #bne
        elif(funct3 == "001"):
            rs1 = Sb_to_D(rs1)
            rs2 = Sb_to_D(rs2)
            if rs1 != rs2:
                Immediate_val = Sb_to_D(imm)
                print(Immediate_val)
                PC += (Immediate_val)
                print("bne") 
            else:
                PC += 4 
                print("bne") 

        #blt
        elif(funct3 == "100"):
            rs1 = Sb_to_D(rs1)
            rs2 = Sb_to_D(rs2)
            if rs1 < rs2:
                Immediate_val = Sb_to_D(imm)
                PC += (Immediate_val) 
                print("blt")
            else:
                PC += 4 
                print("blt")


        #bge
        elif(funct3 == "101"):
            rs1 = Sb_to_D(rs1)
            rs2 = Sb_to_D(rs2)
            if rs1 >= rs2:
                Immediate_val = Sb_to_D(imm)
                PC += (Immediate_val) 
                print("bge")
            else:
                PC += 4 
                print("bge")

    #U-type 
    elif(Ins[25:] in U_fun):
        rd = Ins[20:25]
        imm = Ins[0:20] + "000000000000"
        if Ins[25:] == "0110111":
            Reg[rd] = "0b" + imm 


        elif Ins[25:] == "0010111":
            val = PC + Sb_to_D(imm)
            Reg[rd] = D_to_B(val,32)

        PC += 4
        print("U_fun")



    
    #J-type 
    elif(Ins[25:] in J_fun):
        rd = Ins[20:25]
        #imm = Ins[10:0:-1] + Ins[11] + Ins[19:11:-1] + Ins[0] + "0"
        imm = Ins[0] + Ins[12:20] + Ins[11] + Ins[1:11] + "0"
        Reg[rd] = "0b" + D_to_B(PC + 4,32)
        val = imm 
        PC += Sb_to_D(val)
        print("J_fun")
        
    
    OUT.write("0b" + D_to_B(PC,32) + " ")
    for i in Reg:
        OUT.write(Reg[i] + " ")
    OUT.write("\n")
    
    return PC

def D_to_H(decimal_number):
    hex_val = hex(decimal_number)
    hex_val = hex_val[2:]
    while len(hex_val) < 8:
        hex_val = '0' + hex_val
    hex_val = '0x' + hex_val
    return hex_val

def D_to_B(decimal_num, num_bits):
    decimal_num = int(decimal_num)
    if decimal_num < 0:
        positive_decimal = abs(decimal_num)
        binary_str = bin(positive_decimal)[2:]
        padded_binary_str = binary_str.zfill(num_bits)
        inverted_bits = ''.join('1' if bit == '0' else '0' for bit in padded_binary_str)
        inverted_bits = bin(int(inverted_bits, 2) + 1)[2:]
        return inverted_bits.zfill(num_bits)
    else:
        binary_str = bin(int(decimal_num))[2:]
        return binary_str.zfill(num_bits)

def B_to_D(binary_num):
    d = int(binary_num,2)
    return d

def Sb_to_D(binary_str):
    if binary_str[0] == '1':  
        complement = ''.join('1' if bit == '0' else '0' for bit in binary_str[1:])
        decimal = int(complement, 2) + 1
        return -decimal
    else:
        return int(binary_str, 2)   
        

def main():
    mainfile = []
    with open("C://Users//singh-ranjit//Desktop//coding//input.txt", "r") as file:
 
        mainfile = file.read().split('\n')
    flag = 1
    PC = 0
    OUT = open("C://Users//singh-ranjit//Desktop//coding//output.txt", "w")
    count = 0
    
    if len(mainfile) <= 128:
        while (mainfile[PC//4] != "00000000000000000000000001100011" and PC//4 < len(mainfile)):
            count += 1
            PC = simulator(mainfile[PC//4], PC, OUT)
        for a in Memory:
            OUT.write(a + ":" + Memory[a])
            OUT.write("\n")
    else:
        print("No. of instructions exceeded 128!")
    OUT.close()



if __name__ == "__main__":
    main()
