#include <iostream> 
#include <fstream>
#include <string>
#include <array>
#include <cmath>
#include <vector>

#include "libraries/lib.h"



int main()
{
    int loop = 0;
    while (loop == 0)
    {
        double wcmedian = 0;
        double wtmedian = 0;
        double wtmode = 0;
        double wtoccurance = 0;
        double wcmode = 0;
        double wcoccurance = 0;

        double mintvar = 0;
        double maxtvar = 0;
        std::string mintvarmonth;
        std::string maxtvarmonth;

        double mincvar = 0;
        double maxcvar = 0;
        std::string mincvarmonth;
        std::string maxcvarmonth;

       
    
        std::fstream filewrite("log.txt");


     std::fstream fileread;

    fileread.open ("Data sets/clean/Water_Temperature/Water_Temperature.csv", std::ios::in);
    if (fileread)
    {    
        skipheader(fileread, wtname, wtnumber, wtparam);
        skiplines(fileread, trash);
        readdata(fileread, wtdate, wttemp);
        celorfar(wttemp);
        
        wtmode = findmode(wttemp, wtoccurance);
        

       
        
        std::vector<double> sortedtemps = wttemp;
        wtmedian = findmedian(sortedtemps);
        

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


    fileread.open ("Data sets/clean/Water_Temperature/Water_Temperature.csv", std::ios::in);
        if (fileread)
        {    
                      
            skiplines(fileread, trash);
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
                addtomonth(date, monthno, (int)day, watertemp);
                processTempVariance(date, daysinmonth, monthnames, maxtvar, mintvar, maxtvarmonth, mintvarmonth);


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
            
        findminmaxmonth(alltempmonths, daysinmonth, monthnames, max, min, maxmonth, minmonth);

       
            
        
    
    fileread.open ("Data sets/clean/Water_Course_Level/Water_Course_Level.csv", std::ios::in);
    if (fileread)
    {    
        std::string name;
        std::string number;
        std::string param;
        skipheader(fileread, name, number, param);
        skiplines(fileread, trash);
        readdata(fileread, wcdate, wclevel);
        wcmode = findmode(wclevel, wcoccurance);
       
        
    
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
        wcmedian = findmedian(values);
        
       
        fileread.close();    
    }
    else
    {
        std::cout << "Could not open file up for reading\n";
    }  
    
    fileread.open ("Data sets/clean/Water_Course_Level/Water_Course_Level.csv", std::ios::in);
    if (fileread)
    {    
        skipheader(fileread, wcname, wcnumber, wcparam);
        skiplines(fileread, trash);

        while(fileread.peek() != EOF)
        {
            std::getline(fileread, wtyear, '-');
            std::getline(fileread, wtmonth, '-');
            std::getline(fileread, wtday, 'T');
            std::getline(fileread, trash, ',');
            std::getline(fileread, valueread, ',');
            std::getline(fileread, trash);

            year = stringToDouble(wtyear);
            day = stringToDouble(wtday);
            double level = stringToDouble(valueread);
            int monthno = stringtoint(wtmonth);

            addtomonth(coursedate, monthno, (int)day, level);
        }
       
        findminmaxmonth(allcoursemonths, daysinmonth, monthnames, coursemax, coursemin, maxcoursemonth, mincoursemonth);
        processcoursevariance(coursedate, daysinmonth, monthnames, maxcvar, mincvar, maxcvarmonth, mincvarmonth);
        

        fileread.close();    
        }
        else
        {
            std::cout << "Could not open file up for reading\n";
        }  


        fileread.open("Data sets/Corrupted/Water_Temperature/Water_Temperature.csv");
        if (fileread)
        {
            skipheader(fileread, corruptname, corruptnumber, corruptparam);
            skiplines(fileread, trash);
            readdata(fileread, corrupt_date_vector, corrupt_value_vector);

            addtomonth(corrupt_date_array, monthno, (int)day, corrupt_value_vector);

            for (int i = 0; i < corrupt_date_vector.size(); i++) 
            {
            if (corrupt_value_vector[i] > wcmax)
            {
                corruptmaxdate = corrupt_value_vector[i];
                wcmaxdate = corrupt_date_vector[i];
            }
            if (corrupt_value_vector[i] < wcmin)
            {
                wcmin = corrupt_value_vector[i];
                wcmindate = corrupt_date_vector[i];
            }
            }

            fileread.close();

        }
        else
        {
            std::cout << "Could not open file";
        }

    FILE* fileprint;
    fileprint = fopen ("log.txt", "a");
    std::cout << "\nThis is for " << year << "\n";
    std::cout << "Station long name: " << wtname << "\n";
    fprintf(fileprint, "Station long name: %s\n", wtname.c_str());
    std::cout << "Station Number: " << wtnumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", wtnumber.c_str());
    std::cout << "Parameter: " << wtparam << "\n";
    fprintf(fileprint, "Parameter: %s\n", wtparam.c_str());


    printf("The mean water temperature is %0.3f deg/C\n", wtmedian);
    if (corf != 'f' && corf != 'F')
    {
            
        printf("The Max monthly temperature is: %0.3f deg/C, in: %s\n", max, maxmonth.c_str());
        printf("The Min monthly temperature is: %0.3f deg/C, in: %s\n", min, minmonth.c_str());
        printf("The mode water tempereature is %0.3f deg/C and it occurs %0.0f times\n", wtmode, wtoccurance);
        printf("The max tempereature variation is %0.03f deg/C and this occurs in %s\n", maxtvar, maxtvarmonth.c_str());
        printf("The min tempereature variation is %0.03f deg/C and this occurs in %s\n", mintvar, mintvarmonth.c_str());
    }
    else if (corf == 'f' || corf == 'F')
    {
        printf("The Max monthly temperature is: %0.3f deg/F, in: %s\n", max, maxmonth.c_str());
        printf("The Min monthly temperature is: %0.3f deg/F, in: %s\n", min, minmonth.c_str());
        printf("The mode water tempereature is %0.3f deg/F and it occurs %0.0f\n", wtmode, wtoccurance);
        printf("The max tempereature variation is %0.03f deg/F and this occurs in %s\n", maxtvar, maxtvarmonth.c_str());
        printf("The min tempereature variation is %0.03f deg/F and this occurs in %s\n", mintvar, mintvarmonth.c_str());
    }
    printf("Water Temperature Daily Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    fprintf(fileprint, "Water Temperature Daily Max: %0.3f, on this date: %s\n", wtmax, wtmaxdate.c_str());
    printf("Water Temperature Daily min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    fprintf(fileprint, "Water Temperature Daily min: %0.3f, on this date: %s\n", wtmin, wtmindate.c_str());
    
    


    std::cout << "\nStation long name: " << wcname << "\n";
    fprintf(fileprint, "Station long name: %s\n", wcname.c_str());
    std::cout << "Station Number: " << wcnumber << "\n";
    fprintf(fileprint, "Station Number: %s\n", wcnumber.c_str());
    std::cout << "Parameter: " << wcparam << "\n";
    fprintf(fileprint, "Parameter: %s", wcparam.c_str());
    std::cout << "This is for year: " << year << "\n";
    printf("The median water course level is: %0.3f\n", wcmedian);
    printf("The highest monthly water course level is: %0.03f meters in %s\n", coursemax, maxcoursemonth.c_str());
    printf("The lowest monthly water course level is: %0.03f meters in %s\n", coursemin, mincoursemonth.c_str());
    printf("The mode water course level is %0.3f meters and it occurs %0.0f times\n", wcmode, wcoccurance);
    printf("The max water course level variation is %0.03f meters and this occurs in %s\n", maxcvar, maxcvarmonth.c_str());
    printf("The min water course level variation is %0.03f meters and this occurs in %s\n", mincvar, mincvarmonth.c_str());
    printf("Water Course Daily Max: %0.3f meters, on this date: %s\n", wcmax, wcmaxdate.c_str());
    fprintf(fileprint, "Water Course Daily Max: %0.3f meters, on this date: %s\n", wcmax, wcmaxdate.c_str());
    printf("Water Course Daily min: %0.3f meters, on this date: %s\n", wcmin, wcmindate.c_str());
    fprintf(fileprint, "Water Course Daily min: %0.3f meters, on this date: %s\n", wcmin, wcmindate.c_str());
    

      
    //End the program or continue
        std::cout << "Would you like to reset (R) or exit (E)?\n";
        std::cin >> reset;

        if (reset == 'e'|| reset == 'E')
            {
                std::cout << "Thank you for using the Turning Moore Water Safety Calculator 1.0!\n";
                return 0;
                break;
            }
        else if (reset == 'r' || reset == 'R')
        {
            std::cout << "Going back to the start\n";
            continue;
        }
    
    
    }
}

    

    
