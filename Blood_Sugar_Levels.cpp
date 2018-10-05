
#include "Blood_Sugar_Levels.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
Blood_S_L::Blood_S_L()
{

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

}
void Blood_S_L::print_weekly_summary()
{

}

void Blood_S_L::read_in()
{
	char temp_c;
	float temp(0),index_temp(0);
	bool done_today = false, done = false;	
	while (!done)
	{			
		cout << "Input the number of Blood sugar reading you have, then input the reading one by one " << endl;
		cout << "If you wish to know the daily summary thus far input 'D' at any ponit.\nIf you wish to know the weekly summary thus far input 'W' at any ponit." << endl;
		cout << "To input data for the next day input 'N' at any ponit " << endl;
		if (cin >> index_temp)
		{
			for (int index = 0; index < index_temp; index++)
			{
				if (cin >> temp)
				{
					if (temp > 0)
					{
						sum_day[count_day] += temp;
						sum_week[count_week] += temp;
						if (max_day[count_day] < temp)
						{
							max_day[count_day] = temp;
						}
						if (min_day[count_day] > temp || min_day[count_day] == temp)
						{
							min_day[count_day] = temp;
						}
						if (max_week[count_week] < max_day[count_day])
						{
							max_week[count_week] = max_day[count_day];
						}
						if (min_week[count_week] > min_day[count_day] || min_week[count_week] == min_day[count_day])
						{
							min_week[count_week] = min_day[count_day];
						}
						bL_Count_Day[count_day]++;
						bL_Count_week[count_week]++;
					}
				}
				else if (cin >> temp_c)
				{
					if (temp_c == 'D')
					{
						print_daily_summary();
					}
					if (temp_c == 'W')
					{
						print_weekly_summary();						
					}
					if (temp_c == 'N')
					{
						if (count_day < 14 && count_day >= 0)
						{
							count_day++;
							if (((count_day / 7) == 1) && count_week != 1)
							{
								count_week++;
							}
						}
						else
						{
							cout << "You have inputed yuor Blood sugar level for 14 day or 2 week no more can be inputed" << endl;
							done = true;
						}
						cout << "Input the number of Blood sugar reading you have, then input the reading one by one " << endl;
						cin >> index_temp;
						index = 0;
					}

				}

			}
		}
		else if (cin >> temp_c)
		{
			if (temp_c == 'D')
			{
				print_daily_summary();
			}
			if (temp_c == 'W')
			{
				print_weekly_summary();
			}
			if (temp_c == 'N')
			{
				if (count_day < 14 && count_day >= 0)
				{
					count_day++;
					if (((count_day / 7) == 1) && count_week != 1)
					{
						count_week++;
					}
				}
				else
				{
					cout << "You have inputed yuor Blood sugar level for 14 day or 2 week no more can be inputed" << endl;
					done = true;
				}

			}

		}
		done = true;
	}
}
