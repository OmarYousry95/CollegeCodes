;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Project #8
; Scrambling Encryption
; Omar Yousry Mahmoud Abdel-Aty
; Section #5
; Seat No #128 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

org 100h

.data

STR1 dB "Please, Enter the word (2,4,8 or 16 letters) you want to encrypte: $"
INSTR1 dB 20 dup ("$")



STR2 dB "The Encrypted Word is: $"
OUTSTR2 20 dup ("$")

STR3 dB "The Decrypted Word is: $"
OUTSTR3 20 dup ("$")

STR4 dB "ERROR!.. You Must Enter a Word of (2,4,8 or 16 letters) only $"
                                                  
NEWLINE dB 10,13,"$"
     
     
.code

JMP START


ERROR:
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H
;Print STR4 on the screen for the encrypted word
LEA DX,STR4
MOV AH,09H
INT 21H
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H


START:

;Print STR1 on the screen for the user input
LEA DX,STR1
MOV AH,09H
INT 21H

;Take the user input to DS:DX
LEA DX, INSTR1
MOV AH, 0AH
INT 21H


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Enryption 

Encrypt:
LEA SI,INSTR1
LEA DI,OUTSTR2

;BX to compare in decryption
MOV BH,00H
MOV BL,INSTR1+1

CMP [SI+1],0002H ;TWO CHAR
JE  TWO_ENC

CMP [SI+1],0004H ;FOUR CHAR
JE  FOUR_ENC

CMP [SI+1],0008H ;EIGHT CHAR
JE  EIGHT_ENC

CMP [SI+1],0010H ;Sixteen CHAR
JE  SIXTEEN_ENC

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Error Detection
CMP [SI+1],0002H ;TWO CHAR 
JNE ERROR


CMP [SI+1],0004H ;FOUR CHAR
JNE ERROR 


CMP [SI+1],0008H ;EIGHT CHAR
JNE ERROR
     
     
CMP [SI+1],0010H ;Sixteen CHAR
JNE ERROR


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
 
;INPUT: Two letters 
TWO_ENC:
MOV CX,[SI+2]
MOV [DI],CX

MOV CX,[SI+3]
MOV [DI+1],CX

JMP PRINT_ENC

;INPUT: Four letters
FOUR_ENC:
MOV CX,[SI+2]
MOV [DI],CX

MOV CX,[SI+4]
MOV [DI+1],CX 

MOV CX,[SI+3]
MOV [DI+2],CX

MOV CX,[SI+5]
MOV [DI+3],CX

JMP PRINT_ENC

;INPUT: Eight letters
EIGHT_ENC:
MOV CX,[SI+2]
MOV [DI],CX

MOV CX,[SI+6]
MOV [DI+1],CX 

MOV CX,[SI+4]
MOV [DI+2],CX

MOV CX,[SI+8]
MOV [DI+3],CX

MOV CX,[SI+3]
MOV [DI+4],CX

MOV CX,[SI+7]
MOV [DI+5],CX

MOV CX,[SI+5]
MOV [DI+6],CX

MOV CX,[SI+9]
MOV [DI+7],CX

JMP PRINT_ENC

;INPUT: Sixteen letters
SIXTEEN_ENC:
MOV CX,[SI+2]
MOV [DI],CX

MOV CX,[SI+10]
MOV [DI+1],CX 

MOV CX,[SI+6]
MOV [DI+2],CX

MOV CX,[SI+14]
MOV [DI+3],CX

MOV CX,[SI+4]
MOV [DI+4],CX

MOV CX,[SI+12]
MOV [DI+5],CX

MOV CX,[SI+8]
MOV [DI+6],CX

MOV CX,[SI+16]
MOV [DI+7],CX

MOV CX,[SI+3]
MOV [DI+8],CX

MOV CX,[SI+11]
MOV [DI+9],CX 

MOV CX,[SI+7]
MOV [DI+10],CX

MOV CX,[SI+15]
MOV [DI+11],CX

MOV CX,[SI+5]
MOV [DI+12],CX

MOV CX,[SI+13]
MOV [DI+13],CX

MOV CX,[SI+9]
MOV [DI+14],CX

MOV CX,[SI+17]
MOV [DI+15],CX

JMP PRINT_ENC


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Print function for encryption

PRINT_ENC:
          
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H

;Print STR2 on the screen for the encrypted word
LEA DX,STR2
MOV AH,09H
INT 21H


;Print Encrypted Word
LEA DX,DI
MOV AH,09H
INT 21H 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
;Decryption
Decrypt:
LEA SI,OUTSTR2
LEA DI,OUTSTR3

CMP BX,0002H ;TWO CHAR
JE  TWO_DEC

CMP BX,0004H ;FOUR CHAR
JE  FOUR_DEC

CMP BX,0008H ;EIGHT CHAR
JE  EIGHT_DEC

CMP BX,0010H ;Sixteen CHAR
JE  SIXTEEN_DEC
 
 
;INPUT: Two letters 
TWO_DEC:
MOV CX,[SI]
MOV [DI],CX

MOV CX,[SI+1]
MOV [DI+1],CX

JMP PRINT_DEC


;INPUT: Four letters
FOUR_DEC:
MOV CX,[SI]
MOV [DI],CX

MOV CX,[SI+2]
MOV [DI+1],CX 

MOV CX,[SI+1]
MOV [DI+2],CX

MOV CX,[SI+3]
MOV [DI+3],CX

JMP PRINT_DEC

;INPUT: Eight letters
EIGHT_DEC:
MOV CX,[SI]
MOV [DI],CX

MOV CX,[SI+4]
MOV [DI+1],CX 

MOV CX,[SI+2]
MOV [DI+2],CX

MOV CX,[SI+6]
MOV [DI+3],CX

MOV CX,[SI+1]
MOV [DI+4],CX

MOV CX,[SI+5]
MOV [DI+5],CX

MOV CX,[SI+3]
MOV [DI+6],CX

MOV CX,[SI+7]
MOV [DI+7],CX

JMP PRINT_DEC

;INPUT: Sixteen letters
SIXTEEN_DEC:
MOV CX,[SI]
MOV [DI],CX

MOV CX,[SI+8]
MOV [DI+1],CX 

MOV CX,[SI+4]
MOV [DI+2],CX

MOV CX,[SI+12]
MOV [DI+3],CX

MOV CX,[SI+2]
MOV [DI+4],CX

MOV CX,[SI+10]
MOV [DI+5],CX

MOV CX,[SI+6]
MOV [DI+6],CX

MOV CX,[SI+14]
MOV [DI+7],CX

MOV CX,[SI+1]
MOV [DI+8],CX

MOV CX,[SI+9]
MOV [DI+9],CX 

MOV CX,[SI+5]
MOV [DI+10],CX

MOV CX,[SI+13]
MOV [DI+11],CX

MOV CX,[SI+3]
MOV [DI+12],CX

MOV CX,[SI+11]
MOV [DI+13],CX

MOV CX,[SI+7]
MOV [DI+14],CX

MOV CX,[SI+15]
MOV [DI+15],CX

JMP PRINT_DEC


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Print function for decryption

PRINT_DEC:

;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H

;Print STR3 on the screen for the decrypted word
LEA DX,STR3
MOV AH,09H
INT 21H

;Print Decrypted Word
LEA DX,DI
MOV AH,09H
INT 21H 

;PRINT 2 NEWLINES
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H
;Print a Newline
LEA DX, NEWLINE
MOV AH, 09H
INT 21H


;Infinite Loop
JMP START

ret




