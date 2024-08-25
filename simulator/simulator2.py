class RiscVSimulator:
    def __init__(self, memory_size=1024):
        self.memory = [0] * memory_size
        self.registers = [0] * 32
        self.pc = 0  # Program counter

    def load_program(self, program):
        for i, instr in enumerate(program):
            self.memory[i] = instr

    def sign_extend(self, imm, bits):
        sign_bit = 1 << (bits - 1)
        return (imm & (sign_bit - 1)) - (imm & sign_bit)

    def execute(self):
        while self.pc < len(self.memory):
            instr = self.memory[self.pc]
            opcode = instr & 0b1111111
            rd = (instr >> 7) & 0b11111
            rs1 = (instr >> 15) & 0b11111
            rs2 = (instr >> 20) & 0b11111
            imm_i = self.sign_extend((instr >> 20), 12)
            imm_s = self.sign_extend(((instr >> 25) << 5) | (instr >> 7), 12)
            imm_b = self.sign_extend(((instr >> 31) << 12) | ((instr >> 7) & 0b1111) | (((instr >> 25) & 0b1111111) << 5) | (((instr >> 8) & 0b1) << 11), 13)
            imm_u = (instr & 0xfffff000)
            imm_j = self.sign_extend(((instr >> 31) << 20) | (((instr >> 21) & 0b1111111111) << 1) | (((instr >> 20) & 0b1) << 11) | (((instr >> 12) & 0xff) << 12), 21)

            if opcode == 0b0010011:  # I-type
                funct3 = (instr >> 12) & 0b111
                if funct3 == 0b000:  # ADDI
                    self.registers[rd] = self.registers[rs1] + imm_i
                elif funct3 == 0b111:  # ANDI
                    self.registers[rd] = self.registers[rs1] & imm_i
                elif funct3 == 0b110:  # ORI
                    self.registers[rd] = self.registers[rs1] | imm_i
                # Add more I-type instructions as needed

            elif opcode == 0b0110011:  # R-type
                funct3 = (instr >> 12) & 0b111
                funct7 = (instr >> 25)
                if funct3 == 0b000 and funct7 == 0b0000000:  # ADD
                    self.registers[rd] = self.registers[rs1] + self.registers[rs2]
                elif funct3 == 0b000 and funct7 == 0b0100000:  # SUB
                    self.registers[rd] = self.registers[rs1] - self.registers[rs2]
                elif funct3 == 0b001:  # SLL
                    self.registers[rd] = self.registers[rs1] << (self.registers[rs2] & 0b11111)
                elif funct3 == 0b010:  # SLT
                    self.registers[rd] = 1 if self.registers[rs1] < self.registers[rs2] else 0
                elif funct3 == 0b011:  # SLTU
                    self.registers[rd] = 1 if self.registers[rs1] < self.registers[rs2] else 0  # assuming unsigned comparison
                elif funct3 == 0b100:  # XOR
                    self.registers[rd] = self.registers[rs1] ^ self.registers[rs2]
                elif funct3 == 0b101:  # SRL
                    self.registers[rd] = self.registers[rs1] >> (self.registers[rs2] & 0b11111)
                elif funct3 == 0b110:  # OR
                    self.registers[rd] = self.registers[rs1] | self.registers[rs2]
                elif funct3 == 0b111:  # AND
                    self.registers[rd] = self.registers[rs1] & self.registers[rs2]
                # Add more R-type instructions as needed

            elif opcode == 0b0100011:  # S-type
                funct3 = (instr >> 12) & 0b111
                if funct3 == 0b010:  # SW
                    addr = self.registers[rs1] + imm_s
                    self.memory[addr >> 2] = self.registers[rs2]  # Store word (4 bytes)
                # Add more S-type instructions as needed


            elif opcode == 0b1100011:  # B-type
                funct3 = (instr >> 12) & 0b111
                if funct3 == 0b000:  # BEQ
                    if self.registers[rs1] == self.registers[rs2]:
                        self.pc += imm_b
                    else:
                        self.pc += 4
                # Add more B-type instructions as needed

            elif opcode == 0b0110111:  # U-type (LUI)
                self.registers[rd] = imm_u

            elif opcode == 0b1101111:  # J-type
                self.registers[rd] = self.pc + 4
                self.pc += imm_j

            elif opcode == 0b1100111:  # JALR
                self.registers[rd] = self.pc + 4
                self.pc = (self.registers[rs1] + imm_i) & ~1

            elif opcode == 0b0000011:  # I-type (Load)
                funct3 = (instr >> 12) & 0b111
                if funct3 == 0b000:  # LB
                    addr = self.registers[rs1] + imm_i
                    self.registers[rd] = (self.memory[addr] << 24) >> 24
                # Add more load instructions as needed


            else:
                break

            self.pc += 4

        # Print the contents of the registers after executing the program
        print("Register values after executing the program:")
        for i, val in enumerate(self.registers):
            print(f"Register {i}: {val:032b}")



# Example program to compute the sum of integers from 1 to 5
program = [
    0b00000000000100010000000010010011,  # li a0, 1
    0b00000000001000010000000100010011,  # li a1, 2
    0b00000000001100010000000110010011,  # li a2, 3
    0b00000000010000010000001000010011,  # li a3, 4
    0b00000000010100010000001010010011,  # li a4, 5
    0b00000000000100101000000110010011,  # addi t0, a0, 1
    0b00000000001001001000001100010011,  # addi t1, a1, 2
    0b00000000001101001000010010010011,  # addi t2, a2, 3
    0b00000000010001001000011000010011,  # addi t3, a3, 4
    0b00000000010101001000011110010011,  # addi t4, a4, 5
    0b00000001000010010000010010010011,  # add  a0, a0, t0
    0b00000001001010010000010100010011,  # add  a1, a1, t1
    0b00000001010010010000010110010011,  # add  a2, a2, t2
    0b00000001011010010000011000010011,  # add  a3, a3, t3
    0b00000001100010010000011010010011,  # add  a4, a4, t4
]

simulator = RiscVSimulator()
simulator.load_program(program)
simulator.execute() 
