#include "lib.h"


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

/** 
* @brief Convert a string to a double
* 
* @param numAsString - string only containing the number to convert
* @retval either the value in the string as a double, or -999999999999999999999999999999.9 if a non-valid another character is encounted
*/
int stringtoint(std::string numAsString)
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
				return -9;      
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

	return (int)value;       

}

/** 
* @brief Calculate the monthly average by summing all the values per the given days in the month, then divides it by the count which will be the total amount of days in the month
* 
* @param const std::vector<double> days[] - array of vectors, where each vector contains daily measurements
* @param int numdays - the number of days (the size of the arrays "days")
* @retval double - the average of all values across all days in the given month, or will return 0 if there are no values
*/
double monthlyaverage(const std::vector<double> days[], int numdays)
{
    double total = 0;
    int count = 0;

    for (int d = 0; d < numdays; d++)
    {
        for (double temp : days[d])
        {
            total += temp;
            count ++;
        }
    }
    return (count == 0) ? 0 : total/count;
}

/**
 * @brief Find the median value in a list of numbers.
 *
 * This function sorts a copy of the input vector and then calculates the median:
 * - If the vector is empty, returns 0.
 * - If the number of elements is odd, returns the middle element.
 * - If the number of elements is even, returns the average of the two middle elements.
 * The original vector is not modified, since it is passed by value.
 * @param temps A vector of double values (e.g., temperatures/water levels).
 *              
 * @retval double The median value of the input vector, or 0 if the vector is empty.
 */
double findmedian(std::vector<double> temps)
{
    for (int i = 0; i < temps.size() - 1; i++)
        {
            for (int j = 0; j < temps.size() - i - 1; j++ )
            {
                if (temps[j] > temps[j+1])
                {
                    double temp = temps[j];
                    temps[j] = temps[j+1];
                    temps[j+1] = temp;
                }
            }
            
        }

    
    int n = temps.size();
    if (n == 0) 
    {
        return 0;
    }

    if (n%2 == 0)
    {
        return (temps[n/2-1] + temps[n/2]) / 2;         // if n is even, return the average of the two middle numbers numbers
    }
    else 
    {
        return temps[n/2];                              //if n is odd, return the middle value of the two numbers
    }
}

/**
 * @brief Skip the header row of a CSV file and extract specific fields.
 *
 * This function reads the first line of a CSV file, typically the header, and
 * extracts the values for the station name, number, and parameter while skipping
 * irrelevant fields. It uses the `fileread` stream and modifies the input string
 * references `name`, `number`, and `param`.
 *
 * @param fileread A reference to an open `std::fstream` object for reading the CSV file.
 * @param name A reference to a `std::string` to store the station name from the header.
 * @param number A reference to a `std::string` to store the station number from the header.
 * @param param A reference to a `std::string` to store the parameter name from the header.
 *
 * @retval void The function does not return a value, but updates the input string references.
 * @note If the file is empty, the function does nothing.
 */
void skipheader(std::fstream &fileread, std::string &name, std::string &number, std::string &param)
{
    if (fileread.peek() != EOF)
        {
            

            std::getline(fileread, tempread, ',');
            std::getline(fileread, name, ',');
            std::getline(fileread, tempread);
            std::getline(fileread, tempread, ',');
            std::getline(fileread, number, ',');
            std::getline(fileread, tempread);
            std::getline(fileread, tempread);
            std::getline(fileread, tempread);
            std::getline(fileread, tempread, ',');
            std::getline(fileread, param, ',');
            std::getline(fileread, tempread);
        }
                
       
}

/**
 * @brief Skip comment lines in a CSV file.
 *
 * This function reads lines from the input file stream `fileread` and
 * skips all lines that start with the '#' character, which are typically
 * used as comments or metadata in the file.
 *
 * @param fileread A reference to an open `std::fstream` object for reading the CSV file.
 * @param skipline A temporary string used internally to store skipped lines.
 *
 * @retval void The function does not return a value; it advances the file stream past comment lines.
 * @note Only lines beginning with '#' are skipped. Other lines remain in the stream for further reading.
 */
void skiplines(std::fstream &fileread, std::string skipline)
{
	 while (fileread.peek() == '#')
        { 
            std::getline (fileread, skipline);
        }
}

/**
 * @brief Read data from a CSV file into vectors.
 *
 * This function reads the remaining lines of a CSV file and extracts
 * the date and value fields for each row. The date is stored as a string
 * in `wdate`, and the value is converted to a double and stored in `wtemp`.
 * The function assumes that the date ends at the character 'T' and that
 * the value is the third field in each line.
 *
 * @param fileread A reference to an open `std::fstream` object for reading the CSV file.
 * @param wdate A reference to a vector of strings to store the dates read from the file.
 * @param wtemp A reference to a vector of doubles to store the corresponding values read from the file.
 *
 * @retval void The function does not return a value; it populates the input vectors.
 * @note The function continues reading until the end of the file.
 */
void readdata(std::fstream &fileread, std::vector<std::string> &wdate, std::vector<double> &wtemp)
{
    std::string dateread;
    std::string tempread;
    std::string valueread;
    std::string skipline;

    while(fileread.peek() != EOF)
    {
        
    
        std::getline(fileread, dateread, 'T');
        std::getline(fileread, tempread, ',');
        std::getline(fileread, valueread, ',');
        std::getline (fileread, tempread);

        if (dateread.empty() || valueread.empty()) 
        {
            std::getline(fileread, skipline);
        }
        else
        {
            double val = stringToDouble(valueread);
            if (val != -999999999999999999999999999999.9)
            {
                wdate.push_back(dateread);
                wtemp.push_back(val);
            }
            
        }
        

        
    }
}

/**
 * @brief Add a value to the corresponding day in a specified month.
 *
 * This function inserts a value (e.g., temperature or water level) into
 * the correct day's vector for the specified month in a dataset. The day
 * index is adjusted to zero-based indexing internally. The function assumes
 * that `monthno` is in the range 1–12 and that `day` is in the valid range
 * for that month.
 *
 * @param dataset A reference to an array of 12 `months` structures containing vectors for each day.
 * @param monthno An integer representing the month (1 = January, 12 = December).
 * @param day An integer representing the day of the month (1-based).
 * @param value The value to add to the day's vector (e.g., temperature, water level).
 *
 * @retval void The function does not return a value; it modifies the dataset in place.
 * @note The function uses zero-based indexing for the day internally.
 */
void addtomonth(std::array<months, 12>& dataset, int monthno, int day, double value)
{
	 switch (monthno)
                {
                    case 1: 
                        dataset[0].january[(int)day-1].push_back(value);
                        break;
                    case 2: 
                        dataset[1].february[(int)day-1].push_back(value);
                        break;
                    case 3:
                        dataset[2].march[(int)day-1].push_back(value);
                        break;
                    case 4:
                        dataset[3].april[(int)day-1].push_back(value);
                        break;
                    case 5:
                        dataset[4].may[(int)day-1].push_back(value);
                        break;
                    case 6:
                        dataset[5].june[(int)day-1].push_back(value);
                        break;
                    case 7:
                        dataset[6].july[(int)day-1].push_back(value);
                        break;
                    case 8:
                        dataset[7].august[(int)day-1].push_back(value);
                        break;
                    case 9:
                        dataset[8].september[(int)day-1].push_back(value);
                        break;
                    case 10:
                        dataset[9].october[(int)day-1].push_back(value);
                        break;
                    case 11:
                        dataset[10].november[(int)day-1].push_back(value);
                        break;
                    case 12:
                        dataset[11].december[(int)day-1].push_back(value);
                        break;

                }
}

/**
 * @brief Convert a vector of temperatures between Celsius and Fahrenheit.
 *
 * This function asks the user whether they want temperatures in Celsius (C) or 
 * Fahrenheit (F). If Fahrenheit is selected, all values in the input vector 
 * are converted from Celsius to Fahrenheit in place. If Celsius is selected, 
 * no changes are made.
 *
 * @param wttemps A reference to a vector of double values representing temperatures.
 *                The values may be converted to Fahrenheit if the user chooses.
 *
 * @retval void The function modifies the vector in place if conversion is needed.
 * @note This function interacts with the user via standard input/output.
 */
void celorfar(std::vector<double>& wttemps)
{
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
        for (int i = 0; i < wttemps.size(); i++)
        {
            wttemps[i] = ((wttemps[i]*1.8)+32);
        }

    }
}

void findminmaxmonth(const std::vector <double>* alltempmonths[], const int daysinmonth[], const std::string monthnames[], double &max, double &min, std::string &maxmonth, std::string &minmonth)
{
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
}

double findmode(const std::vector<double> &data, double &maxcount) 
{
    double mode = data[0];
    maxcount = 0;

    for (int i = 0; i < (int)data.size(); i++) 
    {
        int count = 0;
        for (int j = 0; j < (int)data.size(); j++) 
        {
            if (data[j] == data[i]) 
            {
                count++;
            }
        }
        if (count > maxcount) 
        {
            maxcount = count;
            mode = data[i];
        }
    }

    return mode;
}

/**
 * @brief Calculate the population variance of a dataset.
 *
 * This function computes the variance of the given data vector by first
 * calculating the mean, then summing the squared differences from the mean,
 * and finally dividing by the total number of elements.
 *
 * @param data A constant reference to a vector of double values representing 
 *             the dataset. If the vector is empty, the function returns 0.0.
 *
 * @return double The population variance of the dataset. Returns 0.0 if 
 *                the input vector is empty.
 *
 * @note This function calculates the population variance 
 *       (dividing by N, not N-1).
 */
double variance(const std::vector<double> &data) 
{
    if (data.empty()) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < (int)data.size(); i++) 
    {
        sum += data[i];
    }
    double mean = sum / (double)data.size();

    double sqDiffSum = 0.0;
    for (int i = 0; i < (int)data.size(); i++) 
    {
        double diff = data[i] - mean;
        sqDiffSum += diff * diff;
    }

    return sqDiffSum / (double)data.size();
}

/**
 * @brief Find the months with the minimum and maximum variance in temperature data.
 *
 * This function iterates through temperature data for each month, calculating
 * the variance of the recorded values. It identifies the months with the lowest 
 * and highest variance and updates the corresponding output parameters.
 *
 * @param allmonths An array of 12 vectors, where each vector contains temperature 
 *                  values (in double) for a month. Empty months are skipped.
 * @param monthnames A vector of 12 month names corresponding to the data in allmonths.
 * @param maxvar Reference to a double where the maximum variance found will be stored.
 * @param minvar Reference to a double where the minimum variance found will be stored.
 * @param minmonth Reference to a string that will store the name of the month 
 *                 with the minimum variance.
 * @param maxmonth Reference to a string that will store the name of the month 
 *                 with the maximum variance.
 *
 * @retval void The function modifies maxvar, minvar, minmonth, and maxmonth in place.
 *
 * @note Variance is calculated as the mean of squared differences from the mean 
 *       (population variance). If a month has no data, it is ignored.
 */
void findminmaxvariance(const std::vector<double>* allmonths[12], const std::string (&monthnames)[12], double &maxvar, double &minvar, std::string &minmonth, std::string &maxmonth)
{
    maxvar = 0;
    minvar = 1e9;

    for (int i = 0; i < 12; i++) 
    {
        const std::vector<double> &data = *allmonths[i];
        if (data.empty()) continue;

        double var = variance(data);   //using the above variance sequence

        if (var < minvar) 
        {
            minvar = var;
            minmonth = monthnames[i];
        }
        if (var > maxvar) 
        {
            maxvar = var;
            maxmonth = monthnames[i];
        }
    }
}

void processTempVariance(std::array <months, 12> &date, const int daysinmonth[12], const std::string (&monthnames)[12], double &maxtvar, double &mintvar, std::string &maxtvarmonth, std::string &mintvarmonth)
{
    std::vector<double> monthlyAgg[12]; 

    for (int m = 0; m < 12; m++) 
    {
        int days = daysinmonth[m];
        for (int d = 0; d < days; d++) 
        {
            switch (m) 
            {
                case 0:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].january[d].begin(),   date[m].january[d].end()); break;
                case 1:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].february[d].begin(),  date[m].february[d].end()); break;
                case 2:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].march[d].begin(),     date[m].march[d].end()); break;
                case 3:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].april[d].begin(),     date[m].april[d].end()); break;
                case 4:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].may[d].begin(),       date[m].may[d].end()); break;
                case 5:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].june[d].begin(),      date[m].june[d].end()); break;
                case 6:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].july[d].begin(),      date[m].july[d].end()); break;
                case 7:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].august[d].begin(),    date[m].august[d].end()); break;
                case 8:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].september[d].begin(), date[m].september[d].end()); break;
                case 9:  monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].october[d].begin(),   date[m].october[d].end()); break;
                case 10: monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].november[d].begin(),  date[m].november[d].end()); break;
                case 11: monthlyAgg[m].insert(monthlyAgg[m].end(), date[m].december[d].begin(),  date[m].december[d].end()); break;
            }
        }
    }

    const std::vector<double>* alltempmonths[12];
    for (int m = 0; m < 12; ++m) 
    {
        alltempmonths[m] = &monthlyAgg[m];
    }

    findminmaxvariance(alltempmonths, monthnames, maxtvar, mintvar, mintvarmonth, maxtvarmonth);
}

void processcoursevariance(std::array <months, 12> &coursedate, const int daysinmonth[12], const std::string (&monthnames)[12], double &maxcvar, double &mincvar, std::string &maxcvarmonth, std::string &mincvarmonth)
{
    std::vector<double> monthlyAgg[12]; 

    for (int m = 0; m < 12; ++m) 
    {
        int days = daysinmonth[m];
        for (int d = 0; d < days; d++) 
        {
            switch (m) 
            {
                case 0:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].january[d].begin(),   coursedate[m].january[d].end()); 
                        break;
                case 1:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].february[d].begin(),  coursedate[m].february[d].end()); 
                        break;
                case 2:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].march[d].begin(),     coursedate[m].march[d].end()); 
                        break;
                case 3:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].april[d].begin(),     coursedate[m].april[d].end()); 
                        break;
                case 4:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].may[d].begin(),       coursedate[m].may[d].end()); 
                        break;
                case 5:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].june[d].begin(),      coursedate[m].june[d].end()); 
                        break;
                case 6:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].july[d].begin(),      coursedate[m].july[d].end()); 
                        break;
                case 7:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].august[d].begin(),    coursedate[m].august[d].end()); 
                        break;
                case 8:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].september[d].begin(), coursedate[m].september[d].end()); 
                        break;
                case 9:  monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].october[d].begin(),   coursedate[m].october[d].end()); 
                        break;
                case 10: monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].november[d].begin(),  coursedate[m].november[d].end()); 
                        break;
                case 11: monthlyAgg[m].insert(monthlyAgg[m].end(), coursedate[m].december[d].begin(),  coursedate[m].december[d].end()); 
                        break;
            }
        }
    }

    const std::vector<double>* allcoursemonths[12];
    for (int m = 0; m < 12; m++) 
    {
        allcoursemonths[m] = &monthlyAgg[m];
    }

    findminmaxvariance(allcoursemonths, monthnames, maxcvar, mincvar, mincvarmonth, maxcvarmonth);
}

/**
 * @brief Reads weather data from a CSV file and adds it to the monthly dataset.
 * 
 * The file is expected to have entries in the format:
 * YYYY-MM-DD
 * 
 * @param fileread Input file stream (must already be opened).
 * @param coursedate Array/vector of months to store the data.
 */
void readdata(std::ifstream& fileread, std::vector<double> date[])
{
    std::string datayear;
    std::string datamonth; 
    std::string dataday;
    std::string trash;
    std::string valueread;

    while (fileread.peek() != EOF)
    {
        // Parse line using delimiters
        std::getline(fileread, datayear, '-');
        std::getline(fileread, datamonth, '-');
        std::getline(fileread, dataday, 'T');
        std::getline(fileread, trash, ',');
        std::getline(fileread, valueread, ',');
        std::getline(fileread, trash);

        // Convert to numbers
        double year = stringToDouble(datayear);
        int monthno = stringtoint(datamonth);
        double day = stringToDouble(dataday);
        double level = stringToDouble(valueread);



        // Add to the right month/day
        addtomonth(date[i], monthno, (int)day, level);
    }
}