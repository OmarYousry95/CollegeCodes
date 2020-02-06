/*Header file for IC Tester*/
#include <reg52.h>


/*Functions protoypes for ICs to be tested*/
/*Function to test 7411: Triple 3-input AND gate IC*/
unsigned int test_7411();
/*Function to test 7486: Quad 2-input XOR gate IC*/
unsigned int test_7486();
/*Function to test 7408: Quad 2-input AND gate IC*/
unsigned int test_7408();
/*Function to test 7432: Quad 2-input OR gate IC*/
unsigned int test_7432();
/*Function to test 7400: Quad 2-input NAND gate IC*/
unsigned int test_7400();
/*Function to test 7404: Hex NOT gate IC*/
unsigned int test_7404();