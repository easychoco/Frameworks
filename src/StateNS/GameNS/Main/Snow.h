
class Snow {
public:
	Snow(int init_x, int speed, double exRate);
	~Snow();
	void loadImageFile(char* fileName);
	void update();
	void update(int dx, int dy);//dx, dy�͎��@�̈ړ��� ���@�̓����ɍ��킹�č~�����ړ�����
	void draw() const;
	bool isExit() { return fin; }

private:
	int init_x;
	int speed;
	double rate;

	int time;
	int x;
	int y;
	
	bool fin;
};