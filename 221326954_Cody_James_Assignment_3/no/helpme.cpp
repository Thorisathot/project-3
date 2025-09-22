#include <iostream> 
#include <fstream>
#include <string>
#include <array>
#include <cmath>
#include <vector>

// #include "lib.h"

//prototypes
double stringToDouble(std::string numAsString);

struct months
{
    double january[31];
    double february[29];
    double march[31];
    double april[30];
    double may[31];
    double june[30];
    double july[31];
    double august[31];
    double september[30];
    double october[31];
    double november[30];
    double december[31];
};

int main()
{
  

    double wcmax = 0;
    double wcmin = 100;
    double wtmax = 0;
    double wtmin = 100;

    char reset = ' ';

    char corf = ' ';
    std::string dateread;
    std::string tempread;
    std::string valueread;
    std::string tempname;
    std::string tempnumber;
    std::string coursename;
    std::string coursenumber;

    std::string wtmaxdate;
    std::string wtmindate;

    std::string wcmaxdate;
    std::string wcmindate;

    std::string wtparam;
    std::string wcparam;

    std::vector <std::string> wtdate;
    std::vector <std::string> wcdate;
    std::vector <double> wttemp;
    std::vector <double> wclevel;

    std::vector <std::string> wtyear;
    std::vector <std::string> wtmonth;
    std::vector <std::string> wtday;




    int loop = 0;
    while (loop == 0)
    {

    
    std::fstream filewrite("log.txt");


    std::fstream fileread;

        fileread.open ("Data sets/clean/Water_Temperature/Water_Temperature.csv", std::ios::in);
        if (fileread)
        {    
            if (fileread.peek() != EOF)
            {
                std::getline(fileread, tempread, ',');
                std::getline(fileread, tempname, ',');
                std::getline(fileread, tempread);
                std::getline(fileread, tempread, ',');
                std::getline(fileread, tempnumber, ',');
                std::getline(fileread, tempread);
                std::getline(fileread, tempread);
                std::getline(fileread, tempread);
                std::getline(fileread, tempread, ',');
                std::getline(fileread, wtparam, ',');
                std::getline(fileread, tempread);
                
            }
            
            while (fileread.peek() == '#')
            {
                std::string skipline;
                std::getline(fileread, skipline);
            }
            while(fileread.peek() != EOF)
            {
                std::getline(fileread, dateread, 'T');
                std::getline(fileread, tempread, ',');
                std::getline(fileread, valueread, ',');
                std::getline (fileread, tempread);

                wtdate.push_back(dateread);
                wttemp.push_back(stringToDouble(valueread));
            }


            do
            {
                std::cout << "Would you like the variables in Celcius (C) or Farenheit (F)\n";   
                std::cin >> corf;
                if (corf != 'c' && corf != 'C' && corf != 'f' && corf != 'F')
                {
                    std::cout << "Please enter Celcius or Farenheit\n";
                }
            } while (corf != 'c' && corf != 'C' && corf != 'f' && corf !='F');

            switch (corf)
            {
                case 'C':
                case 'c':
                    break;
                case 'F':
                case 'f':
                for (int i = 0; i < wttemp.size(); i++)
                {
                    wttemp[i] = ((wttemp[i]*1.8)+32);
                }

            }
        for (int i = 0; i < wtdate.size(); i++) 
        {
            if (wttemp[i] > wtmax)
            {
                wtmax = wttemp[i];
                wtmaxdate = wtdate[i];
            }
            if (wttemp[i] < wtmin)
            {
                wtmin = wttemp[i];
                wtmindate = wtdate[i];
            }
        }
            fileread.close();    
        }
        else
        {
            std::cout << "Could not open file up for reading\n";
        }



    fileread.open ("Data sets/clean/Water_Course_Level/Water_Course_Level.csv", std::ios::in);
    if (fileread)
    {    
        if (fileread.peek() != EOF)
        {
            std::getline(fileread, tempread, ',');
            std::getline(fileread, coursename, ',');
            std::getline(fileread, tempread);
            std::getline(fileread, tempread, ',');
            std::getline(fileread, coursenumber, ',');
            std::getline(fileread, tempread);
            std::getline(fileread, tempread);
            std::getline(fileread, tempread);
            std::getline(fileread, tempread, ',');
            std::getline(fileread, wcparam, ',');
            std::getline(fileread, tempread);
        }
                
        while (fileread.peek() == '#')
        {
            std::string skipline;
            std::getline (fileread, skipline);
        }
        while(fileread.peek() != EOF)
        {
            std::getline(fileread, dateread, 'T');
            std::getline(fileread, tempread, ',');
            std::getline(fileread, valueread, ',');
            std::getline (fileread, tempread);

            wcdate.push_back(dateread);
            wclevel.push_back(stringToDouble(valueread));
        }
    
          for (int i = 0; i < wcdate.size(); i++) 
    {
        if (wclevel[i] > wcmax)
        {
            wcmax = wclevel[i];
            wcmaxdate = wcdate[i];
        }
        if (wclevel[i] < wcmin)
        {
            wcmin = wclevel[i];
            wcmindate = wcdate[i];
        }
    }

        fileread.close();    
    }
    else
    {
        std::cout << "Could not open file up for reading\n";
    } 

    FILE* fileprint;
    fileprint = fopen ("log.txt", "a");

    std::cout << "Station long name: " << tempname << "\n";
    fprintf(fileprint, "Station long name: %s\n", tempname.c_str());
    std::cout << "Station Number: " << tempnumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", tempnumber.c_str());
    std::cout << "Parameter: " << wtparam << "\n";
    fprintf(fileprint, "Parameter: %s\n", wtparam.c_str());

    printf("Water Temperature Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    fprintf(fileprint, "Water Temperature Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    printf("Water Temperature min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    fprintf(fileprint, "Water Temperature min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    


    std::cout << "Station long name: " << coursename << "\n";
    fprintf(fileprint, "Station long name: %s\n", coursename.c_str());
    std::cout << "Station Number: " << coursenumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", coursenumber.c_str());
    std::cout << "Parameter: " << wcparam << "\n";
    fprintf(fileprint, "Parameter: %s", wcparam.c_str());
    printf("Water Course Max: %0.3f, on this date: %s\n", wcmax, wcmaxdate.c_str());
    fprintf(fileprint, "Water Course Max: %0.3f, on this date: %s\n", wcmax, wcmaxdate.c_str());
    printf("Water Course min: %0.3f, on this date: %s\n", wcmin, wcmindate.c_str());
    fprintf(fileprint, "Water Course min: %0.3f, on this date: %s\n", wcmin, wcmindate.c_str());
    

      
    //End the program or continue
        std::cout << "Would you like to reset (R) or exit (E)?\n";
        std::cin >> reset;

        if (reset == 'e'|| reset == 'E')
            {
                std::cout << "Thank you for using the Turning Moore Water Safety Calculator 1.0!\n";
                break;
            }
        else if (reset == 'r' || reset == 'R')
        {
            std::cout << "Going back to the start\n";
            loop = 0;
        }
    }
    return 0;
}

/** 
* @brief Convert a string to a double
* 
* @param numAsString - string only containing the number to convert
* @retval either the value in the string as a double, or -999999999999999999999999999999.9 if a non-valid another character is encounted
*/
double stringToDouble(std::string numAsString)
{
	float value = 0;                        
	uint8_t isNegative = 0;                 
	uint8_t decimalPointReached = 0;        
	float floatToAdd = 0;                   
	int floatDigitCount = 0;                
	
	for (int i = 0; i < numAsString.length(); i++)
	{
		
		if (numAsString[i] != 0)
		{
			if (numAsString[i] == '.')
			{
				decimalPointReached = 1;        
			}
			
			else if (numAsString[i] == '-')
			{
				isNegative = 1;        
			}
			
			else if (numAsString[i] >= '0' && numAsString[i] <= '9')
			{
				
				if (decimalPointReached == 0)
				{
					value *= 10;                        
					value += (numAsString[i] - '0');    
				}
				else
				{
					floatDigitCount++;                 
					floatToAdd *= 10;
					floatToAdd += (numAsString[i] - '0');
				}
			}
			else
			{
				return -999999999999999999999999999999.9;      
			}
		}
		else
		{
			break;  
		}
	}

	
	for (int i = 0; i < floatDigitCount; i++)
	{
		floatToAdd /= 10;       
	}

	value = value + floatToAdd; 

	
	if (isNegative == 1)
	{
		value *= -1;    
	}

	return value;       

}