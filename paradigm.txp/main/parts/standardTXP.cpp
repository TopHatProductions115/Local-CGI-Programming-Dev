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