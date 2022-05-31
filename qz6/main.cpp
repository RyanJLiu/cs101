#include<iostream>
#include<string>

using namespace std;

class Clock
{
    public:
    	int Hour;
        int minute;
        int second;
        string meridian;
        Clock(int h, int m, int s, string mer);
        void display();
};

class StandardClock:public Clock
{
	public:
		StandardClock(int h, int m, int s, string mer);
        void display();
};

class MilitaryClock:public Clock
{
	public:
		MilitaryClock(int h, int m, int s, string mer);
        void display();
};

int main()
{
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}

Clock::Clock(int h, int m, int s, string mer):Hour(h), minute(m), second(s), meridian(mer)
{
}

void Clock::display()
{
	cout<<Hour<<":"<<minute<<":"<<second<<" "<<meridian<<"\n";
}

StandardClock::StandardClock(int h, int m, int s, string mer):Clock(h, m, s, mer)
{
}

void StandardClock::display()
{
	string mer;
	if (meridian=="AM")
		mer="¤W¤È";
	else
		mer="¤U¤È";
	cout<<mer<<" "<<Hour<<":"<<minute<<":"<<second<<"\n";
}

MilitaryClock::MilitaryClock(int h, int m, int s, string mer):Clock(h, m, s, mer)
{
}

void MilitaryClock::display()
{
	int h;
	if (meridian=="AM")
		h=Hour;
	else
		h=Hour+12;
	cout<<h<<":"<<minute<<":"<<second<<"\n";
}
