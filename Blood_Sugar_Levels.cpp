
#include "Blood_Sugar_Levels.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
Blood_S_L::Blood_S_L()
{
	count_day = 0;
	count_week = 0;
	for (short index = 0; index < 14; index++)
	{
		bL_Count_Day[index] = 0;
		sum_day[index] = 0;
		max_day[index] = 0;
		min_day[index] = 0;
	}
	for (short index = 0; index < 2; index++)
	{
		bL_Count_week[index] = 0;
		sum_week[index] = 0;
		max_week[index] = 0;
		min_week[index] = 0;
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
	cout << "the daily summary" << endl;
	for (int index = 0; index < count_day;index++)
	{
		cout << "the number of the readings for day: " << index + 1 << " is :" << bL_Count_Day[index] << endl;
		cout << "the sum of the readings for day: " << index + 1<< " is :" << sum_day[index] << endl;
		cout << "the max of the readings for day: " << index + 1 << " is :" <<max_day[index] << endl;
		cout << "the min of the readings for day: " << index + 1 << " is :" << min_day[index] << endl << endl;;
	}
}
void Blood_S_L::print_weekly_summary()
{
	cout << "the weekly summary" << endl;
	for (int index = 0; index < count_week; index++)
	{
		cout << "the number of the readings for week : " << index + 1 << " is :" << bL_Count_week[index] << endl;
		cout << "the sum of the readings for week: " << index + 1 << " is :" << sum_week[index] << endl;
		cout << "the max of the readings for week: " << index + 1 << " is :" << max_week[index] << endl;
		cout << "the min of the readings for week: " << index + 1 << " is :" << min_week[index] << endl << endl;;
	}
}

void Blood_S_L::add_to_sum(float add)
{
	sum_day[count_day] = sum_day[count_day] + add;
	sum_week[count_week] = sum_week[count_week] + add;
}

//read-in 2 try 2
void Blood_S_L::read_in()
{
	char temp_c;
	float temp = 0;
	bool done_today = false;
	cout << "Input the Blood sugar reading you have for today of day:" << count_day + 1 << ",week :" << count_week + 1 << endl;
	cout << "If you wish to know the daily summary thus far input 'D' at any ponit.\nIf you wish to know the weekly summary thus far input 'W' at any ponit." << endl;
	cout << "To input data for the next day input 'N' at any ponit " << endl;
		while (!done_today)
		{			
			if (cin >> temp/* && temp > 0*/)
			{
				cout << "inside the temp " << endl;
				
				add_to_sum(temp);
				if (max_day[count_day] < temp)
				{
					cout << "inside max_day check " << endl;
					max_day[count_day] = temp;
				}
				if (min_day[count_day] > temp || min_day[count_day] == temp)
				{
					cout << "inside mid_day check " << endl;
					min_day[count_day] = temp;
				}
				if (max_week[count_week] < max_day[count_day])
				{
					cout << "inside max_week check " << endl;
					max_week[count_week] = max_day[count_day];
				}
				if (min_week[count_week] > min_day[count_day] || min_week[count_week] == min_day[count_day])
				{
					cout << "inside mid_week check " << endl;
					min_week[count_week] = min_day[count_day];
				}
				bL_Count_Day[count_day]++;
				bL_Count_week[count_week]++;
				
			}			
			cin.clear();
			if (cin >> temp_c)
			{
				cout << "inside the temp_c " << endl;
				if (temp_c == 'D' || temp_c == 'd')
				{
					cout << "inside the day " << endl;
					print_daily_summary();
				}
				if (temp_c == 'W' || temp_c == 'w')
				{
					cout << "inside the week " << endl;
					print_weekly_summary();
				}
				if (temp_c == 'N' || temp_c == 'n')
				{
					cout << "inside the next " << endl;
					if (count_day < 14 && count_day >= 0)
					{
						cout <<"the day: "<< count_day << endl;
						cout << "the week: " << count_week << endl;
						count_day++;
						if (((count_day / 7) == 1) && count_week != 1)
						{
							count_week++;
						}
						cout << "after the day: " << count_day << endl;
						cout << "after the week: " << count_week << endl;

					}
					else
					{
						cout << "You have inputed yuor Blood sugar level for 14 day or 2 week no more can be inputed" << endl;
						done_today = true;
					}	
					
				}
				cin.clear();
				cin.ignore();
												
			}							
			cout << "inside loop two " << endl;
		}		
}


//read-in try 1  
//void Blood_S_L::read_in()
//{
//	char temp_c;
//	float temp(0),index_temp(0);
//	bool done_today = false, done = false;	
//	while (!done)
//	{			
//		cout << "Input the Blood sugar reading you have for today is day:" << count_day +1 <<",week :"<< count_week + 1 <<endl;
//		cout << "If you wish to know the daily summary thus far input 'D' at any ponit.\nIf you wish to know the weekly summary thus far input 'W' at any ponit." << endl;
//		cout << "To input data for the next day input 'N' at any ponit " << endl;
//		if (cin >> index_temp)
//		{
//			while(!done_today)
//			{
//				if (cin >> temp)
//				{
//					if (temp > 0)
//					{
//						sum_day[count_day] += temp;
//						sum_week[count_week] += temp;
//						if (max_day[count_day] < temp)
//						{
//							max_day[count_day] = temp;
//						}
//						if (min_day[count_day] > temp || min_day[count_day] == temp)
//						{
//							min_day[count_day] = temp;
//						}
//						if (max_week[count_week] < max_day[count_day])
//						{
//							max_week[count_week] = max_day[count_day];
//						}
//						if (min_week[count_week] > min_day[count_day] || min_week[count_week] == min_day[count_day])
//						{
//							min_week[count_week] = min_day[count_day];
//						}
//						bL_Count_Day[count_day]++;
//						bL_Count_week[count_week]++;
//					}
//				}
//				else if (cin >> temp_c)
//				{
//					if (temp_c == 'D' || temp_c == 'd')
//					{
//						print_daily_summary();
//					}
//					if (temp_c == 'W' || temp_c == 'w')
//					{
//						print_weekly_summary();						
//					}
//					if (temp_c == 'N' || temp_c == 'n')
//					{
//						if (count_day < 14 && count_day >= 0)
//						{
//							count_day++;
//							if (((count_day / 7) == 1) && count_week != 1)
//							{
//								count_week++;
//							}
//							
//						}
//						else
//						{
//							cout << "You have inputed yuor Blood sugar level for 14 day or 2 week no more can be inputed" << endl;
//							done = true;
//						}
//						cout << "Input the number of Blood sugar reading you have, then input the reading one by one " << endl;
//						cin >> index_temp;
//					}
//
//				}
//
//			}
//		}
//		else if (cin >> temp_c)
//		{
//			if (temp_c == 'D' || temp_c == 'd')
//			{
//				print_daily_summary();
//			}
//			if (temp_c == 'W' || temp_c == 'w')
//			{
//				print_weekly_summary();
//			}
//			if (temp_c == 'N' || temp_c == 'n')
//			{
//				if (count_day < 14 && count_day >= 0)
//				{
//					
//					count_day++;
//					if (((count_day / 7) == 1) && count_week != 1)
//					{
//						count_week++;
//					}
//				}
//				else
//				{
//					cout << "You have inputed your Blood sugar level for 14 day or 2 week no more can be inputed" << endl;
//					done = true;
//				}
//
//			}
//
//		}
//
//		done = true;
//	}
//
//	cin.clear();
//	cin.ignore();
//}
