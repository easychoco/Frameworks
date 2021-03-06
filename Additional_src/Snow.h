
class Snow {
public:
	Snow(int init_x, int speed, double exRate);
	~Snow();
	int LoadFile(char* FileName);
	void update();
	void update(int dx, int dy);//dx, dyは自機の移動量 自機の動きに合わせて降る雪も移動する
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