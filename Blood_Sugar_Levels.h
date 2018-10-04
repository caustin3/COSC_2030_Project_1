

#ifndef _BLOOD_SUGAR_LEVELS_H_
#define _BLOOD_SUGAR_LEVELS_H_




class Blood_S_L
{
public:
	// Default constructor
	// post: this Blood_S_L is empty.
	Blood_S_L();

	// Destructor
	~Blood_S_L();

	//returns the count of days that have been stored 
	int get_count_day();

	//returns the count of weeks that have been stored 
	int get_count_week();

	//returns the sum of the Blood sugar level inputed for that day
	float get_sum_day(int day);

	//returns the sum of the Blood sugar level inputed for that week 
	float get_sum_week(int week);

	//returns the max reading for that day 
	float get_max_day(int day);

	//returns the max reading for that week 
	float get_max_week(int week);

	//returns the min reading for that day 
	float get_min_day(int day);

	//returns the max reading for that week 
	float get_min_week(int week);

	//reads in the blood sugar levels 
	void read_in();

private:

	//the count of days that have been stored 
	int count_day = 0;

	//the count of weks that have been stored 
	int count_week = 0;

	//the sum of the Blood sugar level inputed for all 14 days 
	float sum_day[14] = {0};

	//the sum of the Blood sugar level inputed for the two weeks 
	float sum_week[2] = { 0 };

	// the max reading for 14 days  
	float max_day[14] = { 0 };

	// the max reading for for the two weeks 
	float max_week[2] = { 0 };

	// the min reading for 14 days 
	float min_day[14] = { 0 };

	// the max reading for thw two weeks
	float min_week[2] = { 0 };


};
#endif