#include "lib.h"

// Global variable definitions

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
const std::vector<double>* allcorruptmonths[12] =
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
std::string maxcorruptmonth;
std::string mincorruptmonth;

std::string wtmaxdate;
std::string wtmindate;
std::string wcmaxdate;
std::string wcmindate;
std::string corruptmaxdate;
std::string corruptmindate;

std::string wtparam;
std::string wcparam;
std::string corruptparam;

std::array<months, 12> date;
std::array<months, 12> coursedate;
std::array<months, 12> corruptdate;

std::string wtname;
std::string wtnumber;

std::string wcname;
std::string wcnumber;

std::string corruptname;
std::string corruptnumber;

std::vector<std::string> wtdate;
std::vector<std::string> wcdate;
std::vector<std::string> corrupt_date_vector;

std::vector<double> wttemp;
std::vector<double> wclevel;
std::vector<double> corrupt_value_vector;

std::string wtyear;
std::string wtmonth;
std::string wtday;



double year = 0;
double month = 0;
double day = 0;
double watertemp = 0;

std::string trash;

double maxtmonth;
double mintmonth;

std::string maxtmonthname;
std::string mintmonthname;

double maxtavg = 0;
double mintavg = 5000;


