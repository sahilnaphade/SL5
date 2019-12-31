/*
 * structures.h
 *
 *  Created on: 31-Dec-2019
 *      Author: pict
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_
#define SIZE 99
#include <string.h>

struct symtab{
	char symbol[5];
	int add,length;
};

struct littab{
	char literal[10];
	int add;
};

char pooltab[20];

struct mottab{
	char mnemonic_code[5],class[2];
	int machine_code,length;
};

struct pottab{
	char pseudo_opcode[6],class[2];
	int inter_machine_code;
};

struct ic{
	char class_code[20];
	int reg_no,sr_no;
};

struct table{
	char label[10],mnemonic_code[5],op1[10],op2[10];
};

struct registers{
	char reg_name[10];
	int reg_code;
};

void init(struct mottab m[14],struct pottab p[13],struct registers r[4]){
	//initialize machine code, class and length
	for(int i = 0;i<11;i++){
		strcpy(m[i].class,"IS");
		m[i].machine_code = i;
		m[i].length = 2;
	}

	strcpy(m[12].class,"DL");
	m[12].machine_code = 12;
	m[12].length = 1;

	strcpy(m[13].class,"DL");
	m[13].machine_code =13;
	m[13].length = 99;

	//initializes mnemonic code
	strcpy(m[0].mnemonic_code,"STOP");
	strcpy(m[1].mnemonic_code,"ADD");
	strcpy(m[2].mnemonic_code,"SUB");
	strcpy(m[3].mnemonic_code,"MULT");
	strcpy(m[4].mnemonic_code,"MOVER");
	strcpy(m[5].mnemonic_code,"MOVEM");
	strcpy(m[6].mnemonic_code,"COMP");
	strcpy(m[7].mnemonic_code,"BC");
	strcpy(m[8].mnemonic_code,"DIV");
	strcpy(m[9].mnemonic_code,"READ");
	strcpy(m[10].mnemonic_code,"PRINT");
	strcpy(m[11].mnemonic_code,"DC");
	strcpy(m[12].mnemonic_code,"DS");

	//initialization of Pseudo-opcode table
	for(int i = 0 ; i < 5;i++){
		strcpy(p[i].class,"AD");	//assembler directive
		p[i].inter_machine_code = i+1;
	}

	strcpy(p[0].pseudo_opcode,"START");
	strcpy(p[1].pseudo_opcode,"END");
	strcpy(p[2].pseudo_opcode,"LTORG");
	strcpy(p[3].pseudo_opcode,"ORIGIN");
	strcpy(p[4].pseudo_opcode,"EQU");

	//Initialization of Registers
	strcpy(r[0].reg_name,"AREG");
	r[0].reg_code = 1;
	strcpy(r[1].reg_name,"BREG");
	r[1].reg_code = 2;
	strcpy(r[2].reg_name,"CREG");
	r[2].reg_code = 3;
	strcpy(r[3].reg_name,"DREG");
	r[3].reg_code = 4;
}

#endif /* STRUCTURES_H_ */