
class Snow {
public:
	Snow(int init_x, int speed, double exRate);
	~Snow();
	void LoadFile(char* FileName);
	void update();
	void update(int dx, int dy);//dx, dy�͎��@�̈ړ��� ���@�̓����ɍ��킹�č~�����ړ�����
	void draw() const;

private:
	int init_x;
	int speed;
	double rate;

	int time;
	int x;
	int y;
	
	bool fin;

};