#pragma once
class Horse
{
private:
	const Track* ptrTrack;
	const int horse_number;
	float finish_time;
	float distance_run;

public:
	Horse(const int n, const Track* ptrT) :
		horse_number(n),
		ptrTrack(ptrT),
		distance_run(0.0)
	{	}

	~Horse()
	{	}

	void display_horse(const float elapsed_time);
};