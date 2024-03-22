#pragma once
class Main
{
private:
	int sum;
	int x;
	int y;
	Main* pMain;
public:
	Main() {
		this->sum = 0;
		this->x = 3;
		this->y = 4;
	}
	virtual ~Main() {}
	void initialize() {}
	void finalize() {}
	int run(Main *pMain) {
		Main* pMain;
		this->pMain = pMain;

		int a = 0;
		int b = 4;
		this->sum = this->sum + this->x + this->y;
		return sum;
	}
};

