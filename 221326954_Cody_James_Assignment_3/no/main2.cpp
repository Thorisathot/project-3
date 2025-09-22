#include <iostream> 
#include <fstream>
#include <string>
#include <array>
#include <cmath>
#include <vector>

// #include "lib.h"

//prototypes
double stringToDouble(std::string numAsString);
int stringtoint(std::string numAsString);
double monthlyaverage(const std::vector<double> days[], int numdays);
double findmedian(std::vector<double> temps);
void skipheader(std::fstream &fileread, std::string &name, std::string &number, std::string &param);
void readdata(std::fstream &fileread, std::vector<std::string> &wdate, std::vector<double> &wtemp);
void celorfar (char &corf, std::vector<double> &wtemp);



struct months
{
    std::vector<double> january[31];
    std::vector<double> february[29];
    std::vector<double> march[31];
    std::vector<double> april[30];
    std::vector<double> may[31];
    std::vector<double> june[30];
    std::vector<double> july[31];
    std::vector<double> august[31];
    std::vector<double> september[30];
    std::vector<double> october[31];
    std::vector<double> november[30];
    std::vector<double> december[31];

    
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
    double coursemax = 0;
    double coursemin = 5;
    std::string maxcoursemonth;
    std::string mincoursemonth;

    std::string wtmaxdate;
    std::string wtmindate;

    std::string wcmaxdate;
    std::string wcmindate;

    std::string wtparam;
    std::string wcparam;

    std::array<months, 12> date;
    std::array<months, 12> coursedate; 

    std::string wtname;
    std::string wtnumber;
    

    std::string wcname;
    std::string wcnumber;
    


    std::vector <std::string> wtdate;
    std::vector <std::string> wcdate;
    std::vector <double> wttemp;
    std::vector <double> wclevel;

    std::string wtyear;
    std::string wtmonth;
    std::string wtday;
    double year = 0;
    double month = 0;
    double day = 0; 
    double watertemp;


    std::string monthnames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int daysinmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    const std::vector<double>* alltempmonths[12] = 
    {
        date[0].january,   
        date[1].february,  
        date[2].march,     
        date[3].april,     
        date[4].may,       
        date[5].june,      
        date[6].july,     
        date[7].august,    
        date[8].september, 
        date[9].october,   
        date[10].november, 
        date[11].december  
    };
    const std::vector<double>* allcoursemonths[12] =
    {
    coursedate[0].january,   
    coursedate[1].february,  
    coursedate[2].march,     
    coursedate[3].april,     
    coursedate[4].may,       
    coursedate[5].june,      
    coursedate[6].july,     
    coursedate[7].august,    
    coursedate[8].september, 
    coursedate[9].october,   
    coursedate[10].november, 
    coursedate[11].december  
    };




    int loop = 0;
    while (loop == 0)
    {

    
    std::fstream filewrite("log.txt");


    std::fstream fileread;

    fileread.open ("Data sets/clean/Water_Temperature/Water_Temperature.csv", std::ios::in);
    if (fileread)
    {    
        std::string name;
        std::string number;
        std::string wtparam;
        std::vector<std::string> wtdate;
        std::vector<double>wttemps;
        skipheader(fileread, name, number, wtparam);
        readdata(fileread, wtdate, wttemps);

        std::vector<double> sortedtemps = wttemps;
        double median = findmedian(sortedtemps);
        
        std::cout << "Median water temp: " << median << "\n";

        do
        {
            std::cout << "Would you like the variables in Celcius (C) or Farenheit (F)\n";   
            std::cin >> corf;
            if (corf != 'c' && corf != 'C' && corf != 'f' && corf != 'F')
            {
                std::cout << "Please enter Celcius or Farenheit\n";
            }
        } while (corf != 'c' && corf != 'C' && corf != 'f' && corf !='F');

        celorfar(corf, wttemp);

        for (int i = 0; i < wtdate.size(); i++) 
        {
            if (wttemps[i] > wtmax)
            {
                wtmax = wttemps[i];
                wtmaxdate = wtdate[i];
            }
            if (wttemps[i] < wtmin)
            {
                wtmin = wttemps[i];
                wtmindate = wtdate[i];
            }
        }
            fileread.close();    
        }
        else
        {
            std::cout << "Could not open file up for reading\n";
        }


    fileread.open ("Data sets/clean/Water_Temperature/Water_Temperature.csv", std::ios::in);
        if (fileread)
        {    
                      
            while (fileread.peek() == '#')
            {
                std::string skipline;
                std::getline(fileread, skipline);
            }
            while(fileread.peek() != EOF)
            {
                std::getline(fileread, wtyear, '-');
                std::getline(fileread, wtmonth, '-');
                std::getline(fileread, wtday, 'T');
                std::getline(fileread, tempread, ',');
                std::getline(fileread, valueread, ',');
                std::getline (fileread, tempread);

                year = stringToDouble(wtyear);
                day = stringToDouble(wtday);
                watertemp = stringToDouble(valueread);
                int monthno = stringtoint(wtmonth);
                if (corf == 'f' || corf == 'F')
                {
                    watertemp = ((watertemp * 1.8) + 32);
                }
                
                switch (monthno)
                {
                    case 1: 
                        date[0].january[(int)day-1].push_back(watertemp);
                        break;
                    case 2: 
                        date[1].february[(int)day-1].push_back(watertemp);
                        break;
                    case 3:
                        date[2].march[(int)day-1].push_back(watertemp);
                        break;
                    case 4:
                        date[3].april[(int)day-1].push_back(watertemp);
                        break;
                    case 5:
                        date[4].may[(int)day-1].push_back(watertemp);
                        break;
                    case 6:
                        date[5].june[(int)day-1].push_back(watertemp);
                        break;
                    case 7:
                        date[6].july[(int)day-1].push_back(watertemp);
                        break;
                    case 8:
                        date[7].august[(int)day-1].push_back(watertemp);
                        break;
                    case 9:
                        date[8].september[(int)day-1].push_back(watertemp);
                        break;
                    case 10:
                        date[9].october[(int)day-1].push_back(watertemp);
                        break;
                    case 11:
                        date[10].november[(int)day-1].push_back(watertemp);
                        break;
                    case 12:
                        date[11].december[(int)day-1].push_back(watertemp);
                        break;

                }
            }
        fileread.close();
        }
        
        else
        {
            std::cout << "Could not open file up for reading\n";
        }
    

        double max = 0;
        double min = 50;
        std::string maxmonth;
        std::string minmonth;
            
        for (int m = 0; m < 12; m++)
        {
            double avg = monthlyaverage(alltempmonths[m], daysinmonth[m]);
            if (avg !=0)
            {
                if (avg > max)
                {
                    max = avg;
                    maxmonth = monthnames[m];
                }
                if (avg < min)
                {
                    min = avg;
                    minmonth = monthnames[m];
                }
                
                
            }
            
        }
       
            
        
    
    fileread.open ("Data sets/clean/Water_Course_Level/Water_Course_Level.csv", std::ios::in);
    if (fileread)
    {    
        std::string name;
        std::string number;
        std::string param;
        std::vector<std::string> wcdate;
        std::vector<double>wclevel;
        skipheader(fileread, name, number, param);
        readdata(fileread, wcdate, wclevel);

        wtname = name;
        wtnumber = number;
        wtparam = param;
        
    
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

        std::vector<double> values = wclevel;
        double median = findmedian(values);
        std::cout << "The median water course level:  " << median << "\n";
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
            std::getline(fileread, wtyear, '-');
            std::getline(fileread, wtmonth, '-');
            std::getline(fileread, wtday, 'T');
            std::getline(fileread, tempread, ',');
            std::getline(fileread, valueread, ',');
            std::getline(fileread, tempread);

            year = stringToDouble(wtyear);
            day = stringToDouble(wtday);
            double level = stringToDouble(valueread);
            int monthno = stringtoint(wtmonth);

            switch (monthno)
                {
                    case 1: 
                        coursedate[0].january[(int)day-1].push_back(level);
                        break;
                    case 2: 
                        coursedate[1].february[(int)day-1].push_back(level);
                        break;
                    case 3:
                        coursedate[2].march[(int)day-1].push_back(level);
                        break;
                    case 4:
                        coursedate[3].april[(int)day-1].push_back(level);
                        break;
                    case 5:
                        coursedate[4].may[(int)day-1].push_back(level);
                        break;
                    case 6:
                        coursedate[5].june[(int)day-1].push_back(level);
                        break;
                    case 7:
                        coursedate[6].july[(int)day-1].push_back(level);
                        break;
                    case 8:
                        coursedate[7].august[(int)day-1].push_back(level);
                        break;
                    case 9:
                        coursedate[8].september[(int)day-1].push_back(level);
                        break;
                    case 10:
                        coursedate[9].october[(int)day-1].push_back(level);
                        break;
                    case 11:
                        coursedate[10].november[(int)day-1].push_back(level);
                        break;
                    case 12:
                        coursedate[11].december[(int)day-1].push_back(level);
                        break;

                }
        }
        
        

        for (int m = 0; m < 12; m++)
        {
            double avg = monthlyaverage(allcoursemonths[m], daysinmonth[m]);
            if (avg != 0)
            {
                if (avg > coursemax)
                {
                    coursemax = avg;
                    maxcoursemonth = monthnames[m];
                } 
                if (avg < coursemin)
                {
                    coursemin = avg;
                    mincoursemonth = monthnames[m];
                }
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
    std::cout << "This is for " << year << "\n";
    std::cout << "Station long name: " << wtname << "\n";
    fprintf(fileprint, "Station long name: %s\n", wtname.c_str());
    std::cout << "Station Number: " << wtnumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", wtnumber.c_str());
    std::cout << "Parameter: " << wtparam << "\n";
    fprintf(fileprint, "Parameter: %s\n", wtparam.c_str());

    if (corf != 'f' && corf != 'F')
    {
            
        printf("The Max temperature is: %0.3f deg/C, in: %s\n", max, maxmonth.c_str());
        printf("The Min temperature is: %0.3f deg/C, in: %s\n", min, minmonth.c_str());
    }
    else if (corf == 'f' || corf == 'F')
    {
        printf("The Max temperature is: %0.3f deg/F, in: %s\n", max, maxmonth.c_str());
        printf("The Min temperature is: %0.3f deg/F, in: %s\n", min, minmonth.c_str());
    }
    printf("Water Temperature Daily Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    fprintf(fileprint, "Water Temperature Daily Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    printf("Water Temperature Daily min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    fprintf(fileprint, "Water Temperature Daily min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    


    std::cout << "Station long name: " << wcname << "\n";
    fprintf(fileprint, "Station long name: %s\n", wcname.c_str());
    std::cout << "Station Number: " << wcnumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", wcnumber.c_str());
    std::cout << "Parameter: " << wcparam << "\n";
    fprintf(fileprint, "Parameter: %s", wcparam.c_str());
    std::cout << "This is for year: " << year << "\n";
    printf("The highest water course level is: %0.03f meters in %s\n", coursemax, maxcoursemonth.c_str());
    printf("Water Course Daily Max: %0.3f, on this date: %s\n", wcmax, wcmaxdate.c_str());
    fprintf(fileprint, "Water Course Daily Max: %0.3f, on this date: %s\n", wcmax, wcmaxdate.c_str());
    printf("The lowest water course level is: %0.03f meters in %s\n", coursemin, mincoursemonth.c_str());
    printf("Water Course Daily min: %0.3f, on this date: %s\n", wcmin, wcmindate.c_str());
    fprintf(fileprint, "Water Course Daily min: %0.3f, on this date: %s\n", wcmin, wcmindate.c_str());
    

      
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
            continue;
        }
    
    return 0;
    }
}
    

    
