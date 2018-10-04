
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

void Blood_S_L::read_in()
{
	float temp(0),index_temp(0);
	bool done_today = false, done = false;	
	while (!done)
	{	
		while (!done_today)
		{
			cout << "Input the number of Blood sugar reading you have, then input the reading one by one " << endl;
			cin >> index_temp;
			for (int index = 0; index < index_temp; index++)
			{
				cin >> temp;
				sum_day[count_day] += temp;
				if (max_day[count_day] < temp)
				{
					max_day[count_day] = temp;
				}
				if (min_day[count_day] > temp || min_day[count_day] == temp)
				{
					min_day[count_day] = temp;
				}
			}
		}
	}
}
