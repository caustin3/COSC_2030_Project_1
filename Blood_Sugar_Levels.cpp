
#include "Blood_Sugar_Levels.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::fmod;
Blood_S_L::Blood_S_L()
{
	count_day = 0;
	count_week = 0;
	for (short index = 0; index < 14; index++)
	{
		bL_Count_Day[index] = 0;
		sum_day[index] = 0;
		max_day[index] = 0;
		min_day[index] = FLT_MAX;
		sum_day_overflow_counter[index] = 0;
	}
	for (short index = 0; index < 2; index++)
	{
		bL_Count_week[index] = 0;
		sum_week[index] = 0;
		max_week[index] = 0;
		min_week[index] = FLT_MAX;
		sum_week_overflow_counter[index] = 0;
	}
}

Blood_S_L::~Blood_S_L()
{
}

int Blood_S_L::get_count_day()
{
	return count_day;
}

int Blood_S_L::get_count_week()
{
	return count_week;
}

float Blood_S_L::get_sum_day(int day)
{
	return sum_day[day];
}

float Blood_S_L::get_sum_week(int week)
{
	return sum_week[week];
}

float Blood_S_L::get_max_day(int day)
{
	return max_day[day];
}

float Blood_S_L::get_max_week(int week)
{
	return max_week[week];
}

float Blood_S_L::get_min_day(int day)
{
	return min_day[day];
}

float Blood_S_L::get_min_week(int week)
{
	return min_week[week];
}

void Blood_S_L::print_daily_summary()
{
	cout << "******************************************************************************" << endl;
	cout << "the daily summary for today " << count_day + 1 <<endl;
	cout << "the number of the readings for today is :" << bL_Count_Day[count_day] << endl;
	if (sum_day_overflow_counter[count_day]>0)
	{
		cout << "the sum of the readings for today is the sum of : (" << FLT_MAX << "*" << sum_day_overflow_counter[count_day] << ") + " << sum_day[count_day] << endl;
	}
	else
	{
		cout << "the sum of the readings for today is :" << sum_day[count_day] << endl;
	}
	cout << "the max of the readings for today is :" <<max_day[count_day] << endl;
	cout << "the min of the readings for today is :" << min_day[count_day] << endl << endl;

	cout << "******************************************************************************" << endl;
}

void Blood_S_L::print_weekly_summary()
{
	cout << "******************************************************************************" << endl;
	cout << "the weekly summary for week: " << count_week + 1 << endl;
	cout << "the number of the readings for this week is :" << bL_Count_week[count_week] << endl;
	if (sum_week_overflow_counter[count_week]>0)
	{
		cout << "the sum of the readings for this week is the sum of : (" << FLT_MAX << "*" << sum_week_overflow_counter[count_week] <<") + "<< sum_week[count_week] << endl;
	}
	else
	{		
		cout << "the sum of the readings for this week is :" << sum_week[count_week] << endl;
	}
	cout << "the max of the readings for this week is :" << max_week[count_week] << endl;
	cout << "the min of the readings for this week is :" << min_week[count_week] << endl;
	cout << "the highest delta of the readings for this week was on day :" << delta() << endl << endl;
	cout << "******************************************************************************" << endl;
}

void Blood_S_L::print_summary()
{
	cout << "The Summary for all day and weeks " << endl;
	for (count_day = 0; count_day < 14; count_day++)
	{
		print_daily_summary();
	}
	for (count_week = 0 ;count_week < 2; count_week++)
	{
		print_weekly_summary();
	}
}

void Blood_S_L::add_to_sum(float add)
{
	//checks that the sum for both week and day do/dont overflow and add to the overflow count if need and add the new value to the sum 
	float temp_add = add;
	if (add == FLT_MAX)
	{
		sum_day_overflow_counter[count_day]++;
		sum_week_overflow_counter[count_week]++;
		
	}
	//checks if the sum overflow the float by using (a+b)mod n = (a mod n + b mod n) mod n  
	if (fmod(sum_week[count_week] + add,(FLT_MAX)) != fmod(fmod(sum_week[count_week],FLT_MAX)+ fmod(add,FLT_MAX),FLT_MAX))
	{
		sum_week_overflow_counter[count_week]++;
		sum_week[count_week] = (add-(FLT_MAX - sum_week[count_week]));
		
		
	}
	else
	{
		sum_week[count_week] = sum_week[count_week] + add;
	}
	//checks if the sum overflow the float by using (a+b)mod n = (a mod n + b mod n) mod n  
	if (fmod(sum_day[count_day] + add, (FLT_MAX)) != fmod(fmod(sum_day[count_day], FLT_MAX) + fmod(add, FLT_MAX), FLT_MAX))
	{
		sum_day_overflow_counter[count_day]++;
		sum_day[count_day] = (add - (FLT_MAX - sum_day[count_day]));
		
	}
	else
	{
		sum_day[count_day] = sum_day[count_day] + add;
	}
	
	
}

int Blood_S_L::delta()
{
	float temp = 0;
	int day = 0;
	if (count_day > 0)
	{
		for (int index = count_day; index > 0; index--)
		{
			if ((bL_Count_Day[index] - bL_Count_Day[index - 1]) > temp)
			{
				temp = bL_Count_Day[index] - bL_Count_Day[index - 1];
				day = index;
			}

		}
	}
	return day;
}
//read-in 2 try 2
void Blood_S_L::read_in()
{
	char temp_c;
	float temp = 0;
	bool done_today = false;
	cout << "Input the Blood sugar reading you have for today of day:" << count_day + 1 << ",week :" << count_week + 1 << endl;
	cout << "input 'D' for the daily summary.\ninput 'W' for the weekly summary." << endl;
	cout << "for the next day input 'N'\n for the list of commands input 'C'" << endl;
		while (!done_today)
		{			
			cin.clear();
			if (cin >> temp )
			{
				if (temp > 0)
				{
					/*cout << "inside the temp " << endl;*/
					add_to_sum(temp);
					if (max_day[count_day] < temp)
					{
						/*cout << "inside max_day check " << endl;*/
						max_day[count_day] = temp;
					}
					if (min_day[count_day] > temp || min_day[count_day] == temp)
					{
						/*cout << "inside mid_day check " << endl;*/
						min_day[count_day] = temp;
					}
					if (max_week[count_week] < max_day[count_day])
					{
						/*cout << "inside max_week check " << endl;*/
						max_week[count_week] = max_day[count_day];
					}
					if (min_week[count_week] > min_day[count_day] || min_week[count_week] == min_day[count_day])
					{
						/*cout << "inside mid_week check " << endl;*/
						min_week[count_week] = min_day[count_day];
					}					
					bL_Count_Day[count_day]++;
					bL_Count_week[count_week]++;
				}
			}
			else
			{
				cin.clear();
				cin >> temp_c;
				/*cout << "inside the temp_c " << endl;*/
				if (temp_c == 'D' || temp_c == 'd')
				{
					/*cout << "inside the day " << endl;*/
					print_daily_summary();
				}
				else if (temp_c == 'W' || temp_c == 'w')
				{
					/*cout << "inside the week " << endl;*/
					print_weekly_summary();
				}
				else if (temp_c == 'N' || temp_c == 'n')
				{
					/*cout << "inside the next " << endl;*/
					if (count_day < 14 && count_day >= 0)
					{
						/*cout <<"the day: "<< count_day << endl;
						cout << "the week: " << count_week << endl;*/
						count_day++;
						if (((count_day / 7) == 1) && count_week != 1)
						{
							count_week++;
						}
						/*cout << "after the day: " << count_day << endl;
						cout << "after the week: " << count_week << endl;*/
					}
					else
					{
						/*cout << "You have inputed your Blood sugar level for 14 day or 2 week no more can be inputed" << endl;*/
						done_today = true;
					}				
				}
				else if (temp_c == 'C' || temp_c == 'c')
				{
					cout << "'D': for the daily summary." << endl;
					cout << "'W' for the weekly summary." << endl;
					cout << "'n' for next day." << endl;
					cout << "'C' for list of commands" << endl;
				}
			}							
			/*cout << "inside loop two " << endl;*/
		}	
		print_summary();
}


