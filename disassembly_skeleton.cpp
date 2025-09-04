#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          This is a limited disassembler: we can safely assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti, sltiu
//          c) has ONLY registers $a0 thru $a3, $t0 thru $t7, or $s0 thru $s7 in the instruction
//
int binary_to_decimal(string binary_num){
    int power = 0;
    int decimal_num = 0;
    for(int i = binary_num.length() - 1; i >= 0; --i) {
            if (binary_num[i] == '1') {
                decimal_num+= pow(2, power);
            }
            power++;
        }
    return decimal_num;
}

string convert_to_register(string reg_binary){
    string reg = "";
    int reg_num = binary_to_decimal(reg_binary);
    //registers $a0 thru $a3, $t0 thru $t7, or $s0 thru $s7
    switch(reg_num){
        case 4: reg = "$a0"; break;
        case 5: reg = "$a1"; break;
        case 6: reg = "$a2"; break;
        case 7: reg = "$a3"; break;
        case 8: reg = "$t0"; break;
        case 9: reg = "$t1"; break;
        case 10: reg = "$t2"; break;
        case 11: reg = "$t3"; break;
        case 12: reg = "$t4"; break;
        case 13: reg = "$t5"; break;
        case 14: reg = "$t6"; break;
        case 15: reg = "$t7"; break;
        case 16: reg = "$s0"; break;
        case 17: reg = "$s1"; break;
        case 18: reg = "$s2"; break;
        case 19: reg = "$s3"; break;
        case 20: reg = "$s4"; break;
        case 21: reg = "$s5"; break;
        case 22: reg = "$s6"; break;
        case 23: reg = "$s7"; break;
    }
    return reg;
}

string disassemble( string hex ) {

    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the 
    //      different parts of the hex instruction!
    
    // YOUR CODE GOES HERE!!
 
    // return "stub";  remove stub and replace it with correct variable

    //Convert to binary
    string binaryresult = "";
    for(int i = 0; i<hex.length();i++){
        switch (hex[i]) {
        case '0': 
            binaryresult.append("0000");
            break;
        case '1': 
            binaryresult.append("0001");
            break;
        case '2': 
            binaryresult.append("0010");
            break;
        case '3': 
            binaryresult.append("0011");
            break;
        case '4': 
            binaryresult.append( "0100");
            break;
        case '5': 
            binaryresult.append( "0101");
            break;
        case '6': 
            binaryresult.append("0110");
            break;
        case '7': 
            binaryresult.append("0111");
            break;
        case '8': 
            binaryresult.append("1000");
            break;
        case '9': 
            binaryresult.append( "1001");
            break;
        case 'A': case 'a': 
            binaryresult.append("1010");
            break;
        case 'B': case 'b': 
            binaryresult.append("1011");
            break;
        case 'C': case 'c': 
            binaryresult.append("1100");
            break;
        case 'D': case 'd': 
            binaryresult.append( "1101");
            break;
        case 'E': case 'e': 
            binaryresult.append("1110");
            break;
        case 'F': case 'f': 
            binaryresult.append("1111");
            break;
        
    }
    }
    
    //op
    string result = "";
    string op = binaryresult.substr(0,6);
    
    if (op == "001000") {
    result.append("addi ");
    } else if (op == "001001") {
    result.append("addiu ");
    } else if (op == "001100") {
    result.append("andi ");
    } else if (op == "001101") {
    result.append("ori ");
    } else if (op == "001010") {
    result.append("slti ");
    } else if (op == "001011") {
    result.append("sltiu ");
    }    
    string rs = convert_to_register(binaryresult.substr(6,5));
    string rt = convert_to_register(binaryresult.substr(11,5));
    
    int im_num = binary_to_decimal(binaryresult.substr(24,8));
    if(binaryresult.substr(16,1)=="1"){
        im_num -= 256;
    }
    result.append(rt);
    result.append(", ");
    result.append(rs);
    result.append(", ");
    result.append(to_string(im_num));
    return result;
}

int main() {
// Do NOT change ANY code in main() function!!
//      or you will fail this task (get a zero)

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
