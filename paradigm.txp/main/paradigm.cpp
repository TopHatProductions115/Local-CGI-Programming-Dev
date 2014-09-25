#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <dirent.h> // directory header

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;

//using std::cout;, using std::cin;, and using std::endl; are covered in std namespace

int taskmain(int argc, char **argv)
{

try {

	Cgicc cgi;

	// first off, we need to create a pointer to a directory

    DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!

    pdir = opendir ("paradigm.txp\plugins\"); // "." refers to the current directory

    struct dirent *pent = NULL;

    // I used the current directory, since this is one which will apply to anyone reading
    // this tutorial~ If I said "C:\\" and you're on Linux, it may get a little confusing!

    if (pdir == NULL) // if pdir wasn't initialised correctly
    { // print an error message and exit the program
        cout << "\nERROR! pdir could not be initialised correctly";

  ofstream LOGfile;
  LOGfile.open ("paradigm.txp\log\paradigm.log", ios::app);
  LOGfile << "\nERROR! pdir could not be initialised correctly";
  LOGfile.close();

        exit (3);
    } // end if

    while (pent = readdir (pdir)) // while there is still something in the directory to list
    {
        if (pent == NULL) // if pent has not been initialised correctly
        { // print an error message, and exit the program
            cout << "\nERROR! pent could not be initialised correctly";

  ofstream LOGfile;
  LOGfile.open ("paradigm.txp\log\paradigm.log", ios::app);
  LOGfile << "\nERROR! pent could not be initialised correctly";
  LOGfile.close();

            exit (3);
        }

        // otherwise, it was initialised correctly. Let's print it on the console:
        cout << pent->d_name << endl;

  ofstream LOGfile;
  LOGfile.open ("paradigm.txp\log\paradigm.log", ios::app);
  LOGfile << "\nDirectory read successfully. Files detected:\n" pent->d_name << endl;
  LOGfile << "\nWriting HTML/XML output file.";
  LOGfile.close();



   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>paradigm dir list</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << pent->d_name << endl;
   cout << "</body>\n";
   cout << "</html>\n";

    }

    // finally, let's close the directory
    closedir (pdir);

  ofstream LOGfile;
  LOGfile.open ("paradigm.txp\log\paradigm.log", ios::app);
  LOGfile << "\nDirectory closed.";
  LOGfile.close();

    cin.get (); // pause for input

  ofstream LOGfile;
  LOGfile.open ("paradigm.txp\log\paradigm.log", ios::app);
  LOGfile << "\nEnding paradigm.txp runtime execution: no errors detected.";
  LOGfile.close();

    return EXIT_SUCCESS; // everything went OK

      }

catch(exception& e) 
   {
      // handle any errors - omitted for brevity

   }

}


void detectGUIresource(int argc, char** argv)
{

std::ifstream gui("paradigm.txp/gui/paradigm.gui");
  std::string content( (std::istreambuf_iterator<char>(gui) ),
                       (std::istreambuf_iterator<char>()    ) );
ofstream outputFile("paradigm.txp/gui/paradigm.html");
outputFile.open("paradigm.txp/gui/paradigm.html")

outputFile << content;
outputFile.close();

	taskmain();

}


void readGUI()
{

std::ifstream file( "paradigm.txp/gui/paradigm.gui", std::ios::binary ) ;

if( !file )
{
        std::cerr << "ERR:100 - Minimum_Runtime_Resources_Abscent\n" ;
	return -1;
}

else if( file.peek() /*tellg()*/ == std::ifstream::traits_type::eof() )
{
	std::cerr << "ERR:099 - GUI_Data_Abscent\n" ;
	return -1;
}

else
{

	detectGUIresource();

{
        
}
}

}


void readAddondata()
{

ifstream data;
data.open("paradigm.txp/plugins/addons.log");
string dat;
vector<string> vecstring;
    while(getline(data, dat))
          vecstring.push_back(dat);

for (vector<string>::iterator i = values.begin(); i!=values.end(); ++i)
{
std::ifstream file( *i, std::ios::binary ) ;

if( !file )
{
        std::cerr << "ERR:103 - Declared_Plugins_Absent\n" ;
	return -1;
}

else
{
	readGUI();
}

}

}


void detectResources()
{

std::ifstream file( "paradigm.txp/plugins/addons.log", std::ios::binary ) ;

if( !file )
{
        std::cerr << "ERR:100 - Minimum_Runtime_Resources_Abscent\n" ;
	return -1;
}

else if( file.peek() /*tellg()*/ == std::ifstream::traits_type::eof() )
{
	std::cerr << "ERR:099 - AddOn_Data_Abscent\n" ;
	return -1;
}

else
{
	readAddondata();
}

}


int main()
{
   
   detectResources();
   
}
