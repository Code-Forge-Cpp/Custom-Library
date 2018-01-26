/*
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // for exit(1)
#include <sstream> // FOR SSTR
#include <list>*/

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()


class fLibBasic
{
private:
	//Locally stored path of file 
	char *FilePath;
public:
	// Constructor
	fLibBasic (char * path) {
		FilePath = path;
		//Create fill is not exist
		if (!fileExists())
		{
			POST(1,"");
		}
	}

public:
	
// check path is correct
bool fileExists( ) 
{
  std::ifstream test(FilePath);
  return (test ? true : false);
}



// Get File Data else return std::string ERROR
std::string GET (  int nline)
{
    std::ifstream DATAFILE;
    DATAFILE.open(FilePath);

    //Chech for errors of path
     if (DATAFILE.fail())
       {
           return SSTR("ERROR_PATH_GET:[ " <<  FilePath << " ]");
        exit(1);
        }

        int c = 1;
        std::string item;
            // eof = End Of File
            while (!DATAFILE.eof())
                {
                 getline(DATAFILE,item);
                    if (c >= nline) // Keep Looking Break Line
                    {
                      return item;
                    }
                  //   std::cout << item<<std::endl;
                    c ++;
                }
             DATAFILE.close();
         if (nline >c){
             return SSTR("ERROR_SIZEOUT_GET:[ " <<  c <<" ]");
         }

return "ERROR_GET_ZERO";
}//GETFILE("file.txt",0)



// Auto push in file data or create mising file 
void POST ( int nline , std::string text) {
std::ifstream INDATAFILE;
std::ofstream OUTDATAFILE;


std::string item;
int fLen =0;
std::list<std::string> strArr;


        // if file not exist
        if ( !fileExists( ) )
        { // create new file
          OUTDATAFILE.open(FilePath);
          OUTDATAFILE.close();
        }
INDATAFILE.open(FilePath);//Open to Read

      while ( !INDATAFILE.eof() )
            {

                //std::cout <<item <<std::endl;;
                  getline(INDATAFILE,item);
                if (item.length()>0) //Check if string is not empty
                    {
                        strArr.push_back(item);
                      //  std::cout <<"READFILE: "<< strArr.back() <<std::endl;
                    }
            };

INDATAFILE.close(); // closing after all data was  saved in list array
///////////// Begin's Insertion
OUTDATAFILE.open(FilePath);//Open to Write

for (signed int c = 1 ; c <=nline;c++) {
std::string cp="";

   // Works only have strArr arguments
   if(!strArr.empty())
    {
             cp = strArr.front();
                  // Always remove first variable
            strArr.pop_front();

             if (c == nline)  // interpreter new text
                cp = text;




    }else  // Keep trying until finish loop
    {
        if (c == nline)  // interpreter new text
             cp = text;
    }
    // Output To File
    OUTDATAFILE << cp  << "\n";
}
 // Continue until finish last bit
 while (!strArr.empty())
    {
        std::string cpLeft;
         cpLeft = strArr.front();
            // Remove variable Front array
          strArr.pop_front();

         OUTDATAFILE << cpLeft  << "\n";
    };

//OUTDATAFILE << text  << std::endl;

OUTDATAFILE.close();
return;
} // POSTFILE("Horse.txt",0,"Hello Horse");



};

//std::string GETLINELONG (int line,)


































class fLibLongLine
{
private:	
	//Locally stored file path
	char *FilePath;
	//Locally stored constructor pattern index name 
	std::string TABLE_CHEME[35]; 
	//Localy sored constructor pattern length
	int TABLE_CHEME_LENGHT;
	//Key use for separate data in file /only one char is supported
	std::string SPECIALKEY;
	 
public:

	// constructor
	fLibLongLine (char* path,... array<char*>^ CREATE_TABLE_CHEME):SPECIALKEY("~") {
		FilePath = path;
		TABLE_CHEME_LENGHT = CREATE_TABLE_CHEME->Length+1; //  start from zero but i like start from 1
		for (int c=0;c < CREATE_TABLE_CHEME->Length;c++)
		{
			TABLE_CHEME[c+1]= CREATE_TABLE_CHEME[c];
		}
		//Create file if is not exist
		if (!fileExists())
		{
			POST(1,TABLE_CHEME[1],"");
		}
	}

private:///////////////////////////////// Private Functions 
	
	//Convert from string to char	
		char * To_Char (std::string strng ){
			char* cstrCopy = new  char [strng.length()+1];
			std::strcpy (cstrCopy, strng.c_str());
			return cstrCopy;
		}
	// Return choped line data in array or make empty while data not exist in file
		array<const char*> ^ GETLINEARRAY ( int nline , int textOffset = 0 ) //offset for get instatly ; 
	{  
		std::ifstream DATAFILE;
		DATAFILE.open(FilePath);	
		array<const char*> ^ lineData = gcnew array<const char*>(TABLE_CHEME_LENGHT); // 
		lineData[0]="false"; // return positive condition
		bool findWantedLine = false;
		int c = 1;
		std::string item;
		// eof = End Of File
		while (!DATAFILE.eof()) // while not reach end of file 
		{
			getline(DATAFILE,item);
			if (c == nline) // Keep Looking Break Line until find accepted new line 
			{
			
				findWantedLine = true; // mark if that line was successfully found for later fill void varables
				int indexPos;
				for (int c = 1;c<TABLE_CHEME_LENGHT;c++)
				{					
						     // mark data  between ";"	
							indexPos=item.find(SPECIALKEY);//+1 always get ; , need to jump that
							if (indexPos && item.length()>0) { //low error checking 
								std::string text = item.substr(0,indexPos+textOffset);
								item=item.substr(indexPos+1,item.length());//but add +1 in here 
								lineData[c]=To_Char(text);
								lineData[0]="true"; // To found bracket in steed nothing 
								//Console::WriteLine("True");
							}
							else{
								lineData[c]=" "; // '" "' not get correctly and delete original data
								// and find() function return same spot insteed blank string correct that
								//Console::WriteLine("False");
							}
							//Console::WriteLine("PotLen"+TABLE_CHEME_LENGHT+",Array:"+ToSystemString(lineData[c]));
				}
				
				return lineData; // item
			}
			//   std::cout << item<<std::endl;
			//Console::WriteLine("read End at: "+c+" searching for: "+nline);
			c ++;
		}
		DATAFILE.close();
		//Console::WriteLine("WRI");
		if (!findWantedLine) {
			
			for (int c = 1;c<TABLE_CHEME_LENGHT;c++)
			{
				lineData[c]=" "; // do this for fill void variables
				//Console::WriteLine("SPAWN "+c+":"+ToSystemString(lineData[c]));
			}
		}
			
		return lineData;
	}//GETFILE("file.txt",0)

		
public://///////////////////// Public Functions 
		
	
 // Check if file exist return boolean
	bool fileExists( ) // works beatyfully
	{
		std::ifstream test(FilePath);
		return (test ? true : false);
	};
 // Check if index name exist in constructor	
	bool IsIndexName (std::string index_name) {
		for (int c = 1;c < TABLE_CHEME_LENGHT; c++)
		{
			if (index_name == TABLE_CHEME[c])
			{
				return true;
			}
		}
		return false;
	}
  // Get index value/position in constructor
	int GetIndexNameValue (std::string index_name) {
		for (int c = 1;c < TABLE_CHEME_LENGHT; c++)
		{
			if (index_name == TABLE_CHEME[c])
			{
				return c;
			}
		}
		return 0;
	}
	std::string GetSpecelKey(){
		return SPECIALKEY;
	}
	bool IsSpecialKey(std::string full_text) {
		int x = full_text.find(SPECIALKEY);
		return (x>0)?true:false; // always getting 
	}

  //Post data by index name , creating  file if not exist
	std::string POST(int nline, std::string index_name,std::string data){
			
		if (IsIndexName(index_name))
		{
			//Read data
			
			
		///////////////////////////// Start posting	
			std::ifstream INDATAFILE;
			std::ofstream OUTDATAFILE;
		

			std::string item;
			int fLen =0;
			std::list<std::string> strArr;


			// if file not exist
			if ( !fileExists() )
			{ // create new file
				OUTDATAFILE.open(FilePath);
				OUTDATAFILE.close();
			}
			INDATAFILE.open(FilePath);//Open to Read

			while ( !INDATAFILE.eof() )
			{

				//std::cout <<item <<std::endl;;
				getline(INDATAFILE,item);
				if (item.length()>0 ) //Check if string is not empty
				{
					strArr.push_back(item);
					//  std::cout <<"READFILE: "<< strArr.back() <<std::endl;
				}
			};

			INDATAFILE.close(); // closing after all data was  saved in list array
			///////////// Begin's Insertion
			 array<const char*> ^ linearray =  GETLINEARRAY(nline);  //declarative array for later
			OUTDATAFILE.open(FilePath);//Open to Write
				
			for (signed int c = 1 ; c <=nline;c++) {
				std::string cp="";
				
				// Works only then tempory array have data,  strArr arguments
				if(!strArr.empty())
				{
				

					if (c == nline )  // interpreter new text						 
						{
						 // Posting Long string
							 
						for (int c2 =1 ; c2 < TABLE_CHEME_LENGHT;c2++)
						{
							std::string tostr = linearray[c2];
							//Console::WriteLine(c2+"c2:"+ToSystemString(tostr)+" in line: "+nline);
							// if that name exist try to insert then write in old one
							if (GetIndexNameValue(index_name) == c2 ) //  check if the same position in TABLE_CHEME is same  and then give permission to insert data
							{
								cp +=data+SPECIALKEY; 
							} 
							else
							{
								cp += tostr+SPECIALKEY;
							}
						}//  Posting Long string
						
					}else { // if nline not equal for searching for
						cp = strArr.front();	
					}
					// Always remove first variable
					strArr.pop_front();
				}else  // Keep trying until finish loop after nothing left in strArray
				{
					

					if (c == nline )  // interpreter new text
					{
						for (int c1 =1 ; c1 < TABLE_CHEME_LENGHT;c1++)
						{
							// if that name exist try to insert then write in old one
							std::string tostr = linearray[c1];
								//Console::WriteLine(c1+"c1:"+ToSystemString(tostr));
							if (GetIndexNameValue(index_name) == c1)
							{
								cp +=data+SPECIALKEY; 
								
							} 
							else
							{
								cp += tostr+SPECIALKEY;
							}
						}//  Posting Long string
					}
				}
				// Output To File
				OUTDATAFILE << cp  << "\n";
			}
			// Continue until finish last bit
			while (!strArr.empty())
			{
				std::string cpLeft;
				cpLeft = strArr.front();
				// Remove variable Front array
				strArr.pop_front();

				OUTDATAFILE << cpLeft  << "\n";
			};

			//OUTDATAFILE << text  << std::endl;

			OUTDATAFILE.close();
			//////////////// End posting 
		}


		// index not found
		return "false";
	}
	
	
 //Read data from file return same index name value as in querry
	std::string GET (int nline, std::string index_name){
				 
		 if (IsIndexName(index_name))
		 {
				array<const char*>^ data = GETLINEARRAY(nline);	
				
				 if (data[0]=="false") // data not exist at all return wiped string
				 {
					 return ""; // to void black " " string
				 }else
				 {
					 std::string thisData = data[GetIndexNameValue(index_name)];
						int x = thisData.find(" ");// looking empty space
						
						if (thisData.length()==1 && x == 0) // if found only empty space that mean return clean string
						{
							return ""; 
						}
						//else if not only empty string then return full data
				 return thisData;
				 }
				
		}
		 
 		  return  "false";
	}
	

};

