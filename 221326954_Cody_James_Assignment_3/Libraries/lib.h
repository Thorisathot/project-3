#ifndef INC_LIB
#define INC_LIB

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cmath>
#include <vector>

// Struct for storing monthly data
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

// Function prototypes
double stringToDouble(std::string numAsString);
int stringtoint(std::string numAsString);
double monthlyaverage(const std::vector<double> days[], int numdays);
double findmedian(std::vector<double> temps);
void skipheader(std::fstream &fileread, std::string &name, std::string &number, std::string &param);
void readdata(std::fstream &fileread, std::vector<std::string> &wdate, std::vector<double> &wtemp);
void skiplines(std::fstream &fileread, std::string skipline);
void addtomonth(std::array<months, 12>& dataset, int monthno, int day, double value);
void celorfar(std::vector<double>& wttemps);
void findminmaxmonth(const std::vector <double>* alltempmonths[], const int daysinmonth[], const std::string monthnames[], double &max, double &min, std::string &maxmonth, std::string &minmonth);
double findmode(const std::vector<double> &data, double &maxcount);
double variance(const std::vector<double> &data);
void findminmaxvariance(const std::vector<double>* allmonths[12], const std::string (&monthnames)[12], double &maxvar, double &minvar, std::string &minmonth, std::string &maxmonth);
void processTempVariance(std::array <months, 12> &date, const int daysinmonth[12], const std::string (&monthnames)[12], double &maxtvar, double &mintvar, std::string &maxtvarmonth, std::string &mintvarmonth);
void processcoursevariance(std::array <months, 12> &coursedate, const int daysinmonth[12], const std::string (&monthnames)[12], double &maxcvar, double &mincvar, std::string &maxcvarmonth, std::string &mincvarmonth);




extern std::string monthnames[12];
extern int daysinmonth[12];


extern const std::vector<double>* alltempmonths[12];
extern const std::vector<double>* allcoursemonths[12];
extern const std::vector<double>* allcorruptmonths[12];

extern double wcmax;
extern double wcmin;
extern double wtmax;
extern double wtmin;

extern char reset;
extern char corf;

extern std::string dateread;
extern std::string tempread;
extern std::string valueread;
extern std::string tempname;
extern std::string tempnumber;
extern std::string coursename;
extern std::string coursenumber;
extern double coursemax;
extern double coursemin;
extern std::string maxcoursemonth;
extern std::string mincoursemonth;

extern std::string wtmaxdate;
extern std::string wtmindate;
extern std::string wcmaxdate;
extern std::string wcmindate;

extern std::string wtparam;
extern std::string wcparam;

extern std::array<months, 12> date;
extern std::array<months, 12> coursedate;

extern std::string wtname;
extern std::string wtnumber;
extern std::string wcname;
extern std::string wcnumber;

extern std::vector<std::string> wtdate;
extern std::vector<std::string> wcdate;

extern std::vector<double> wttemp;
extern std::vector<double> wclevel;

extern std::string wtyear;
extern std::string wtmonth;
extern std::string wtday;



extern double year;
extern double month;
extern double day;
extern double watertemp;

extern std::string trash;

extern double maxtmonth;
extern double mintmonth;


extern std::string maxtmonthname;
extern std::string mintmonthname;
extern double maxtavg;
extern double mintavg;

extern std::string maxcorruptmonth;
extern std::string mincorruptmonth;
extern std::string corruptmaxdate;
extern std::string corruptmindate;

extern std::string corruptparam;
extern std::array<months, 12> corrupt_date_array;
extern std::string corruptname;
extern std::string corruptnumber;
extern std::vector<std::string> corrupt_date_vector;
extern std::vector<double> corrupt_value_vector;




#endif