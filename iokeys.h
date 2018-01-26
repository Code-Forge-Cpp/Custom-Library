/*
#include <windows.h>
#include <winable.h> // For INPUT
#include <Winuser.h>
#include <string>
#include <stdio.h> // sprintf, _sprintf_l
#include <iostream> //
#include <sstream>*/

using std::string;

class ContversionString {
private:
	int gay;
public:

	WORD VirtualKeyCode (string letter,string datatype="none"){

		


		const int LEN_ARR = 95;
		WORD isInt[LEN_ARR];
		//WORD isHex[LEN_ARR];
		std::string isLetter[LEN_ARR];

		isInt[0]=32;   isLetter[0]=" ";		
		isInt[1]=97;   isLetter[1]="a";
		isInt[2]=98;   isLetter[2]="b";
		isInt[3]=99;   isLetter[3]="c";
		isInt[4]=100;   isLetter[4]="d";
		isInt[5]=101;   isLetter[5]="e";
		isInt[6]=102;   isLetter[6]="f";
		isInt[7]=103;   isLetter[7]="g";
		isInt[8]=104;   isLetter[8]="h";
		isInt[9]=105;   isLetter[9]="i";
		isInt[10]=106;   isLetter[10]="j" ;
		isInt[11]=107;   isLetter[11]="k" ;
		isInt[12]=108;   isLetter[12]="l" ;
		isInt[13]=109;   isLetter[13]="m" ;
		isInt[14]=110;   isLetter[14]="n" ;
		isInt[15]=111;   isLetter[15]="o" ;
		isInt[16]=112;   isLetter[16]="p" ;
		isInt[17]=113;   isLetter[17]="q" ;
		isInt[18]=114;   isLetter[18]="r" ;
		isInt[19]=116;   isLetter[19]="t" ;
		isInt[20]=117;   isLetter[20]="u" ;
		isInt[21]=118;   isLetter[21]="v" ;
		isInt[22]=119;   isLetter[22]="w" ;
		isInt[23]=120;   isLetter[23]="x" ;
		isInt[24]=122;   isLetter[24]="z" ;
		//Finish Small Letters
		isInt[25]=65;   isLetter[25]="A" ;
		isInt[26]=66;   isLetter[26]="B" ;
		isInt[27]=67;   isLetter[27]="C" ;
		isInt[28]=68;   isLetter[28]="D" ;
		isInt[29]=69;   isLetter[29]="E" ;
		isInt[30]=70;   isLetter[30]="F" ;
		isInt[31]=71;   isLetter[31]="G" ;
		isInt[32]=72;   isLetter[32]="H" ;
		isInt[33]=73;   isLetter[33]="I" ;
		isInt[34]=74;   isLetter[34]="J" ;
		isInt[35]=75;   isLetter[35]="K" ;
		isInt[36]=76;   isLetter[36]="L" ;
		isInt[37]=77;   isLetter[37]="M" ;
		isInt[38]=78;   isLetter[38]="N" ;
		isInt[39]=79;   isLetter[39]="O" ;
		isInt[40]=80;   isLetter[40]="P" ;
		isInt[41]=81;   isLetter[41]="Q" ;
		isInt[42]=82;   isLetter[42]="R" ;
		isInt[43]=84;   isLetter[43]="T" ;
		isInt[44]=85;   isLetter[44]="U" ;
		isInt[45]=86;   isLetter[45]="V" ;
		isInt[46]=87;   isLetter[46]="W" ;
		isInt[47]=88;   isLetter[47]="X" ;
		isInt[48]=90;   isLetter[48]="Z" ;

		isInt[49]=49;   isLetter[49]="1" ;
		isInt[50]=50;   isLetter[50]="2" ;
		isInt[51]=51;   isLetter[51]="3" ;
		isInt[52]=52;   isLetter[52]="4" ;
		isInt[53]=53;   isLetter[53]="5" ;
		isInt[54]=54;   isLetter[54]="6" ;
		isInt[55]=55;   isLetter[55]="7" ;
		isInt[56]=56;   isLetter[56]="8" ;
		isInt[57]=57;   isLetter[57]="9" ;
		isInt[58]=48;   isLetter[58]="0" ;
		//PEDRP
		isInt[59]=121;   isLetter[59]="y" ;
		isInt[60]=89;   isLetter[60]="Y" ;

		isInt[61]=115;   isLetter[61]="s" ;
		isInt[62]=83;   isLetter[62]="S" ;
		//symbols
		isInt[63]=58;   isLetter[63]=":" ;
		isInt[64]=59;   isLetter[64]=";" ;
		isInt[65]=60;   isLetter[65]="<" ;
		isInt[66]=61;   isLetter[66]="=" ;
		isInt[67]=62;   isLetter[67]=">" ;
		isInt[68]=63;   isLetter[68]="?" ;
		isInt[69]=64;   isLetter[69]="@" ;
		isInt[70]=44;   isLetter[70]="," ; //reapeting

		isInt[71]=33;   isLetter[71]="!" ;
		isInt[72]=34;   isLetter[72]="\""; 
		isInt[73]=35;   isLetter[73]="#" ;
		isInt[74]=36;   isLetter[74]="$" ;
		isInt[75]=37;   isLetter[75]="%" ;
		isInt[76]=38;   isLetter[76]="&" ;
		isInt[77]=39;   isLetter[77]="'" ;
		isInt[78]=40;   isLetter[78]="(" ;
		isInt[79]=41;   isLetter[79]=")" ;
		isInt[80]=42;   isLetter[80]="*" ;

		isInt[81]=43 ;   isLetter[81]="+";
		isInt[82]=44 ;   isLetter[82]=","; //Reapeting
		isInt[83]=45 ;   isLetter[83]="-";
		isInt[84]=46 ;   isLetter[84]=".";
		isInt[85]=47 ;   isLetter[85]="/";
		isInt[86]=91 ;   isLetter[86]="[";
		isInt[87]=92 ;   isLetter[87]="\\";
		isInt[88]=93 ;   isLetter[88]="]";
		isInt[89]=94 ;   isLetter[89]="^";
		isInt[90]=95 ;   isLetter[90]="_";
		isInt[91]=123 ;   isLetter[91]="{";
		isInt[92]=124 ;   isLetter[92]="|";
		isInt[93]=125 ;   isLetter[93]="}";
		isInt[94]=126 ;   isLetter[94]="~";
		

		int len = sizeof(isLetter)/sizeof(isLetter[0]);

		letter = letter.substr(0,1); // read only one letter
		int line = 0;
		for ( int c = 0 ; c <= len ; c++){
			if ( letter == isLetter[c]   )
			{
				if  (datatype == "hex")  {line = c;};
				if (datatype == "int" ) {line = c;};
				break;
			}

		}
		
		//if  (datatype == "hex")  {return isHex[line];};
		if (datatype == "int" ) {return isInt[line];};
		return '~';
	};


	std::string SVirtualKeyCode (const char *letter) {
		const char *ch;
		ch = letter; // '\0x5'
		std::ostringstream oss;
		oss << static_cast<int>(ch[0]);
		const std::string& str = oss.str(); // str now contains "5"
		return str;
	}

};


// Class that takes key event  input or  output



class SetOutput {
private:
	INPUT ip;
	ContversionString toStr;
public:

	void send_keys(std::string keysSet , short int timeToWrite ) {

		short int keysLenght=keysSet.length();
		std::string txt;
		WORD letter;

		// input event.
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.time = 0;
		ip.ki.dwFlags = 0x0004; // Specify the key as a unicode character: KEYEVENTF_UNICODE
		ip.ki.wScan = 'd'; // Which keypress to simulate
		ip.ki.wVk = 0;
		ip.ki.dwExtraInfo = 0;




		for (signed int c = 0 ; c < keysLenght; c++  ){

			txt = keysSet.substr(c,1);
			letter = toStr.VirtualKeyCode(txt,"int");

			ip.ki.wScan =letter; // Which keypress to simulate

			//  std::cout <<"Key:"<<c<<",char:   "<<letter<<" , Letter: "<<txt<<std::endl;

			SendInput(1, &ip, sizeof(INPUT));
			Sleep(timeToWrite);
		};
	};

};



