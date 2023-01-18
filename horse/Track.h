#pragma once

using namespace std;

class Track
{
private:
	Horse* hArray[maxHorses];
	int total_horses;
	int horse_count;
	const float track_length;
	float elapsed_time;

public:
	Track(float lenT, int nH);

	~Track();

	void display_track();

	void run();

	float get_track_len() const;
};

void Horse::display_horse(float elapsed_time)
{
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
	set_color(static_cast<color>(cBLUE + horse_number));

	char horse_char = '0' + static_cast<char>(horse_number);

	putch(' '); putch('\xDB'); putch(horse_char); putch('\xDB');

	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
	{
		if (rand() % 3)
		{
			distance_run += 0.2F;
		}
		finish_time = elapsed_time;
	}
	else
	{
		int mins = int(finish_time) / 60;
		int secs = int(finish_time) - mins * 60;
		cout << " Time =" << mins << ":" << secs;
	}
}

Track::Track(float lenT, int nH) :
	track_length(lenT),
	total_horses(nH),
	horse_count(0),
	elapsed_time(0.0)
{
	init_graphics();

	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;

	for (int j = 0; j < total_horses; j++)
	{
		hArray[j] = new Horse(horse_count++, this);
	}
	time_t aTime;
	srand(static_cast<unsigned>(time(&aTime)));
	display_track();
}

Track::~Track()
{
	for (int j = 0; j < total_horses; j++)
	{
		delete hArray[j];
	}
}

void Track::display_track()
{
	clear_screen();

	for (int f = 0; f <= track_length; f++)
	{
		for (int r = 1; r <= total_horses * 2 + 1; r++)
		{
			set_cursor_pos(f * CPF + 5, r);

			if (f == 0 || f == track_length)
			{
				cout << '\xDE';
			}
			else
			{
				cout << '\xB3';
			}
		}
	}
}

void Track::run()
{
	while (!kbhit())
	{
		elapsed_time += 1.75;

		for (int j = 0; j < total_horses; j++)
		{
			hArray[j]->display_horse(elapsed_time);
		}
		wait(500);
	}
	getch();

	cout << endl;
}

float Track::get_track_len() const
{
	return track_length;
}